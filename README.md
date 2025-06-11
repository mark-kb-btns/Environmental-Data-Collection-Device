# Environmental Data Collection Device

![Screenshot 2025-06-12 015048](https://github.com/user-attachments/assets/de00a4ef-4284-43c5-a3a1-df4a7e9a0c3b)
![Screenshot 2025-06-12 015115](https://github.com/user-attachments/assets/806ad8b2-7f57-4c32-b2c4-9da4af6ed1ed)

# Project Description
The device is designed to collect environmental data such as temperature, humidity, and other relevant atmospheric parameters over a period of time. As it is intended to operate in a stationary location, the device stores all collected data locally. To access the recorded information, the device must be manually retrieved. This data can then be used to observe environmental trends and conditions over time using spreadsheet software or data visualization tools.

# Software Components
1. **Dust Sensor** (`src/dust_sintegration.cpp`)
   * Arduino program to interface with Sharp Optical Dust Sensor GP2Y1010AU0F
   * [Dust Sensor Code](https://github.com/mark-kb-btns/Environmental-Data-Collection-Device/blob/main/src/dust_sintegration.cpp)
   * Header File: [Dust Sensor h](https://github.com/mark-kb-btns/Environmental-Data-Collection-Device/blob/main/include/dust_sintegration.h)

2. **Light Sensor** (`src/light_sintegration.cpp`)
   * Arduino program to interface with Grove Light Sensor
   * [Light Sensor Code](https://github.com/mark-kb-btns/Environmental-Data-Collection-Device/blob/main/src/light_sintegration.cpp)
   * Header File: [Light Sensor h](https://github.com/mark-kb-btns/Environmental-Data-Collection-Device/blob/main/include/light_sintegration.h)

3. **Main Source Code** (`src/main.ino`)
   * Integrates different sensor and interface modules
   * [Main Code](https://github.com/mark-kb-btns/Environmental-Data-Collection-Device/blob/main/src/main.ino)

# Prototype
Due to constraints, the following are early versions or initial attempts that were later abandoned:
1. **Humidity and Temperature Sensor** (`src/hnt_sintegration.cpp`)
   * Arduino program to interface with DHT11 Humidity and Light Sensor
   * [HnT Sensor Code](https://github.com/mark-kb-btns/Environmental-Data-Collection-Device/blob/main/src/hnt_sintegration.cpp)
   * Header File: [HnT Sensor h](https://github.com/mark-kb-btns/Environmental-Data-Collection-Device/blob/main/include/hnt_sintegration.h)

2. **Obstacle Detection and Mobility** (`src/mobility_wUS.ino`)
   * Arduino program to interface with an Ultrasonic Sensor HC-SR04 and four (4) DC motors.
   * [Mobility w/ Utrasonic Sensor Code](https://github.com/mark-kb-btns/Environmental-Data-Collection-Device/blob/main/src/mobility_wUS.ino)

# Folder Structure
<pre><code> 
Environmental-Data-Collection-Device/
│
├── include/                   # Header files for sensor integration
│   ├── dust_sintegration.h
│   └── light_sintegration.h
│
├── src/                       # Main and sensor source codes
│   ├── main.ino               # Integrates all modules
│   ├── dust_sintegration.cpp  # Dust sensor logic
│   ├── light_sintegration.cpp # Light sensor logic
│
└── README.md
  </code></pre>


# Getting Started
To get started with the Environmental Data Collection Device, follow these steps to set up the hardware and deploy the software components:

**Prerequisites**
<br> Before uploading the code, make sure you have the following:
  * Arduino IDE (latest version recommended)
  * Required libraries for:
      * Real-Time Clock (DS1302)
      * SD card communication
      * Sensor interfaces (e.g., analogRead, Wire, etc.)
  * A compatible USB cable to upload code to the Uno R3 board

**Hardware Setup**
<br>Assemble your hardware with the following components:
  * Uno R3 Development Board
  * Sharp Optical Dust Sensor (GP2Y1010AU0F) – for detecting airborne particles
  * Grove Light Sensor – to measure ambient light levels
  * DS1302 RTC Module – to timestamp recorded data
  * Micro SD Card Module – to store environmental data locally

**Uploading the Code**
1. Open main.ino in the Arduino IDE.
2. Ensure the required header and .cpp files are in the same project folder or properly included in the IDE.
3. Select the correct Board (Arduino Uno) and Port from the Tools menu.
4. Click Upload to flash the device.

**Data Access & Visualization**
* Data collected by the sensors is saved to the SD card as .csv files.
* Retrieve the SD card and open the file using spreadsheet software (e.g., Excel or Google Sheets) to visualize and analyze trends.

![image](https://github.com/user-attachments/assets/58834efc-eb62-431a-8a54-1e5e5a381cc9)
![23-12-19](https://github.com/user-attachments/assets/5867a5ed-7c56-434f-861a-1b290a6527d7)

# Contribute
We welcome contributions to improve the Environmental Data Collection Device project!

If you’d like to contribute:
1. Fork the repository
2. Clone your fork
3. Create a new feature or fix branch
4. Make your changes and commit them with clear messages
5. Push to your fork
6. Submit a Pull Request to the main branch with a description of your changes.
