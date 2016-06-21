ESPDUINO is a recent WIFI enabled Arduino board that is very easy to use for IOT project. ESPDUINO combines Arduino and ESP8266 wireless capability. Connecting ESPDUINO to Wifi and posting sensor data to cloud can be done in easy steps.

![alt tag](https://github.com/westboroughIOT/hello-wiot-club/blob/master/microcontrollers/ESPDuino/IMG_1137.JPG)

Espduino can be purchased online as low as $8,this makes any IOT project cost effective.
Once you got your ESPDUINO there are few more steps to complete

#### IDE update

##### Adding ESP8266 board to your existing Arduino IDE

If you are already using Arduino IDE 1.6.8 or 1.6.9 then you need to add ESP8266 board to the IDE. 
You can do that by following.

Go  File Menu--> and click on preferences

![alt tag](https://github.com/westboroughIOT/hello-wiot-club/blob/master/microcontrollers/ESPDuino/Path.PNG)

Add the following URL to the  "Additional Boards Manager URL"
 
 http://espduino.doit.am/package_esp8266com_index.json

![alt tag](https://github.com/westboroughIOT/hello-wiot-club/blob/master/microcontrollers/ESPDuino/Preference.PNG)

Now go to Tools--> Board --> Boards Manager

Select "updatable" in the type dropdown and you can see the board to be installed. Select the board and install

![alt tag](https://github.com/westboroughIOT/hello-wiot-club/blob/master/microcontrollers/ESPDuino/board.PNG)

Now you can see all the boards that are available as part of the installed package

![alt tag](https://github.com/westboroughIOT/hello-wiot-club/blob/master/microcontrollers/ESPDuino/esp8266boards.PNG)

##### Download complete Arduino IDE prepackaged with ESP8266 module

You can download entire prepackaged IDE under following URL

http://en.doit.am/espduino.php

1. There is no installation involved here, you just need to download and unzip the content. 
2. Once you unzip the content in the download folder, copy the root folder arduino1.6.8-ESPDuino-2.1 to C: drive. I am suggesting this to avoid "File directory too long" error while compiling your ketch.
3. You can launch the Arduino ESP8266 by just clicking the arduino.exe file

#### CH340 driver installation

ESPDUINO requires CH340  driver to installed for to connect your computer

You can download windows version from  http://en.doit.am/CH341SER.zip

MAC version from http://www.doit.am/CH341SER_MAC.ZIP

Once you install the driver and connect ESPDUINO to your laptop you should see the CH340 drive displayed ports

![alt tag](https://github.com/westboroughIOT/hello-wiot-club/blob/master/microcontrollers/ESPDuino/CH340.PNG)

#### IDE Settings

Now that you have ESPDUIO, IDE and drive you are almost ready to try your new board. Before that select  Espduino (ESP 13 module) as the board and make sure following parameters are set.

Board -> ESPDUINO ESP--13 module
Upload Using -- Serial
CPU Frequency - 80 Mhz
Flash Size -- 4M
Upload Speed -- 115200



#### Uploading code to ESPDUINO

Now try upload "Blink" example to Espduino. You can select the example by File--> Examples --> ESP8266 -- Blink

Before you can upload the code to Espduino you need to flash and reset the board. You can do this by pressing flash button and with flash button still being pressed down, press the reset button and have both pressed for 6 seconds. After six seconds  release the reset first (still have flash button pressed). Now click "Upload" in Arduino to upload the code. First the code will complile and when IDE shows "Uploadng" release the reset button as well.


![alt tag](https://github.com/westboroughIOT/hello-wiot-club/blob/master/microcontrollers/ESPDuino/Steps.PNG)




