/* Grove - Light Sensor demo v1.0
* 
* Signal wire to A0.
* By: http://www.seeedstudio.com
*/
#include <math.h>

const int LIGHT_SENSOR_A0 = A0; // Grove - Light Sensor is connected to A0 of Arduino
const int LED_PIN = 14;         // Connect the LED Grove module to Pin 12, Digital 12
float Rsensor;                   // Resistance of sensor in K

void setup() {
    Serial.begin(9600);   // Start the Serial connection
    pinMode(LED_PIN, OUTPUT); // Set the LED pin as an OUTPUT
}

void loop() {
    int sensorValue = analogRead(LIGHT_SENSOR_A0);
    Rsensor = (float)(1023 - sensorValue) * 10 / sensorValue;

    Serial.println("The analog read data is ");
    Serial.println(Rsensor, DEC);
    //Serial.println("The sensor resistance is ");
    //Serial.println(Rsensor, DEC); // Show the light intensity on the serial monitor;

    
    // Use A0 for analog input and LED_PIN for controlling the LED
    if (Rsensor > 500) {
        digitalWrite(LED_PIN, LOW); // Turn on the LED
    } else {
        digitalWrite(LED_PIN, HIGH);  // Turn off the LED
    }

    delay(1000); // Add a delay to make the changes easier to observe
}
