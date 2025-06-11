#include <SD.h>
#include <SPI.h>
#include <RtcDS1302.h>
#include <Wire.h>
#include <hnt_sintegration.h>
#include <light_sintegration.h>
#include <dust_sintegration.h>


const int LIGHT_SENSOR_PIN = A0;
LightSensor lightSensor(LIGHT_SENSOR_PIN);

/*const int HNT_SENSOR_PIN = A1;
DHT11 hnt(HNT_SENSOR_PIN);*/

const int DUST_SENSOR_MEASUREPIN = A2;
const int DUST_SENSOR_LEDPIN = 7;
SHARP dust(DUST_SENSOR_MEASUREPIN, DUST_SENSOR_LEDPIN);

const int chipSelect = 10;

ThreeWire myWire(4, 5, 2); // Data, CLK, RST
RtcDS1302<ThreeWire> rtc(myWire);

int ledIndicator = 1; //successful setup
int ledLS = 3; //Light sensor
//int ledHNT = 6; //hnt sensor
int ledDS = 8; //dust sensor

File myFile;

void setup() {
  Serial.begin(57600);
  rtc.Begin();
  pinMode(DUST_SENSOR_LEDPIN ,OUTPUT);

  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
  rtc.SetDateTime(compiled);

  while (!Serial) {
    // Wait for serial port to connect
  }

  Serial.print("Initializing SD card...");

  if (!SD.begin()) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");


  RtcDateTime now = rtc.GetDateTime();

  /*// Create folder name based on the current date
  String foldername = String(now.Year(), DEC);
  foldername += "-";
  if (now.Month() < 10) foldername += "0";
  foldername += String(now.Month(), DEC);
  foldername += "-";
  if (now.Day() < 10) foldername += "0";
  foldername += String(now.Day(), DEC);

  // Create a folder with the current date as the name
  if (!SD.exists(foldername)) {
    SD.mkdir(foldername);
    Serial.println("Folder created: " + foldername);
  }*/

 String foldername = getMainFolderName(now);

if (!SD.exists(foldername)) {
  SD.mkdir(foldername);
  Serial.println("Main Folder created: " + foldername);
}

String filename = getNextFilename(foldername);
String filePath = foldername + "/" + filename;

Serial.print("Folder Name: ");
Serial.println(foldername);

Serial.print("File Name: ");
Serial.println(filename);

myFile = SD.open(filePath, FILE_WRITE);

if (!myFile) {
  Serial.println("Error opening file: " + filename);
  return;
}

//myFile.println(compiled);


  //myFile.println("Timestamp\tLight Intensity\tAir Quality(ug/m3)");
  myFile.print("Timestamp,");
  /*myFile.print("Humidity,");
myFile.print("Temperature,");
myFile.print("FTemperature,");
myFile.print("KTemperature,");
myFile.print("Dewpoint,");
myFile.print("DewpointFast,");*/
myFile.print("LightIntensity,");
myFile.print("DustResults");
myFile.println();


pinMode(ledIndicator, OUTPUT);
pinMode(ledLS, OUTPUT);
//pinMode(ledHNT, OUTPUT);
pinMode(ledDS, OUTPUT);

digitalWrite(ledIndicator, HIGH);

  atexit(closeFile);
}

void loop() {
      RtcDateTime now = rtc.GetDateTime();

    char dateStr[32];
snprintf(dateStr, sizeof(dateStr), "%02d:%02d:%02d",
         now.Hour(), now.Minute(), now.Second());

myFile.print(dateStr); // Timestamp
myFile.print(",");
Serial.println(dateStr);

      

      /*double hnt_humidity = hnt.humidity();
      double hnt_temperature = hnt.temperature();
      double hnt_ftemperature = hnt.fahrenheit(hnt_temperature);
      double hnt_ktemperature = hnt.kelvin(hnt_temperature);
      double hnt_dewpoint = hnt.dewPoint(hnt.temperature(), hnt.humidity());
      double hnt_dewpointfast = hnt.dewPointFast(hnt.temperature(), hnt.humidity());
      if (hnt_humidity > 0 && hnt_temperature > 0) {
        digitalWrite(ledHNT, HIGH);
        digitalWrite(ledHNT, LOW);
      }*/
      
      float lightIntensity = lightSensor.readLight();
      if (lightIntensity > 0) {
        digitalWrite(ledLS, HIGH);
        digitalWrite(ledLS, LOW);
      }
      
      float dust_results = dust.readDust();
      if (dust_results > 0) {
        digitalWrite(ledDS, HIGH);
        digitalWrite(ledDS, LOW);
      }

      /*Serial.print("\nHumidity: ");
      Serial.println(hnt_humidity);
      Serial.print("Temperature: ");
      Serial.println(hnt_temperature);
      Serial.print("Temperature (°F): ");
      Serial.println(hnt_ftemperature);
      Serial.print("Temperature (°K): ");
      Serial.println(hnt_ktemperature);
      Serial.print("Dewpoint (°C): ");
      Serial.println(hnt_dewpoint);
      Serial.print("DewpointFast (°C): ");
      Serial.println(hnt_dewpointfast);*/

      Serial.print("Light Intensity: ");
      Serial.println(lightIntensity);

      Serial.print("Air Quality: ");
      Serial.println(dust_results);
      Serial.println();

      /*myFile.print(hnt_humidity);
myFile.print(",");
myFile.print(hnt_temperature);
myFile.print(",");
myFile.print(hnt_ftemperature);
myFile.print(",");
myFile.print(hnt_ktemperature);
myFile.print(",");
myFile.print(hnt_dewpoint);
myFile.print(",");
myFile.print(hnt_dewpointfast);
myFile.print(",");*/
myFile.print(lightIntensity);
myFile.print(",");
myFile.print(dust_results);
myFile.println();




      myFile.flush(); // Ensure data is written to the SD card
      delay(1000);
    }

void closeFile() {
  myFile.close();
}

String getNextFilename(String foldername) {
  String filename;
  int fileCount = 1;
  do {
    filename = String(fileCount++) + ".csv";
  } while (SD.exists(foldername + "/" + filename)); // Check if file already exists

  return filename;
}

String getMainFolderName(RtcDateTime now) {
  String mainFolderName = String(now.Year() % 100); // Get last two digits of the year
  mainFolderName += "-";
  if (now.Month() < 10) mainFolderName += "0"; // Add leading zero for months < 10
  mainFolderName += String(now.Month());
  mainFolderName += "-";
  if (now.Day() < 10) mainFolderName += "0"; // Add leading zero for days < 10
  mainFolderName += String(now.Day());
  return mainFolderName;
}
