# OpenOTP32
## A Hardware One-Time Pad Printer for the Masses

• Current Version: 0.1.0


OpenOTP32 is a development board project that prints One-Time Pad keys on receipt paper using an ESP32 DevKitC v4 and a QR204 thermal printer. "Open" meaning open source, "OTP" meaning "One-Time Pad," and "32" to denote the ESP32 dev board.

The project was conceived to be as accessible and affordable as possible while maintaining good security.
The ESP32 was chosen since its random number generator feature (RNG) is superior to the decidedly inferior Arduino analog pin randomness.

I hope to elevate this project higher than that of a novelty toy, but people much smarter than me will have to make that determination. Toward this end, I have a couple concerns that I hope can be put to rest:

*1. Is the ESP32 RNG sufficiently unpredictable?*

*2. Do the WiFi/Bluetooth connectivity features of the ESP32 present a vulnerability?*

# Contents
## [Building](https://github.com/emergencyrussell/OpenOTP32#building-1)
### [Parts](https://github.com/emergencyrussell/OpenOTP32#parts-1)
### [Tools](https://github.com/emergencyrussell/OpenOTP32#tools-1)
### [Installation & Assembly](https://github.com/emergencyrussell/OpenOTP32#installation--assembly-1)
1. [Upload the Sketch](https://github.com/emergencyrussell/OpenOTP32#1-upload-the-sketch-1)
  
  - [Detecting the ESP32 on Your Machine](https://github.com/emergencyrussell/OpenOTP32#11-detecting-the-esp32-on-your-machine-1)
  
  - [Installing the Needed Libraries](https://github.com/emergencyrussell/OpenOTP32#12-installing-the-needed-libraries-1)

2. [Prepare the Thermal Printer](https://github.com/emergencyrussell/OpenOTP32#2-prepare-the-thermal-printer-1)

3. [Prepare USB Cable](https://github.com/emergencyrussell/OpenOTP32#3-prepare-the-usb-cable)

4. [Connect Power](https://github.com/emergencyrussell/OpenOTP32#4-connect-power-1)

5. <a name="5-powass">[Power On the Assembly](#5_powass)</a>

## [Building](https://github.com/emergencyrussell/OpenOTP32#building)
### [Parts](https://github.com/emergencyrussell/OpenOTP32#parts)
##### (your build may vary)
- ESP32
- QR204
- 5v, 2A USB power bank
- Breadboard extension cables (male + female, or just female)
- Trash USB cable

#### ESP32
- Sketch is written using Arduino IDE v1.8.
- Installed are the Adafruit Thermal Printer and the EspSoftwareSerial libraries.
- Pins 16 and 17 send and receive data between the QR204.

#### QR204
- The "Tiny" model of Adafruit thermal printer, again, documented [here](https://cdn-learn.adafruit.com/downloads/pdf/mini-thermal-receipt-printer.pdf).
- It's a fun little printer. I recommend playing around with it to see all the cool things you can do with it. :)

#### Power Bank
5V, 2A. Per the [Adafruit documentation](https://cdn-learn.adafruit.com/downloads/pdf/mini-thermal-receipt-printer.pdf), a current of 2A is required for the printer to function. This means the low-end 1A power banks won't cut it.

### [Tools](https://github.com/emergencyrussell/OpenOTP32#tools)
- A wire stripper (or sharp edge)

### Installation & Assembly

#### 1. Upload the Sketch
After setting up your machine to detect the ESP32 and installing the necessary libraries, upload the provided code from the Arduino IDE v1.8 to the ESP32 board.

##### Detecting the ESP32 on Your Machine
You may need some drivers to get your machine to detect the ESP32: I used the [Silicon Labs CP210x VCP Windows Driver](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads) (Third option down).

##### Installing the Needed Libraries:

- [Adafruit Thermal Printer Library](https://github.com/adafruit/Adafruit-Thermal-Printer-Library)
- [EspSoftware Serial](https://github.com/plerup/espsoftwareserial)

Sketch -> Include Library -> Add .ZIP Library…

#### 2. Prepare the Thermal Printer

Depending on your cable situation, you may need to solder. The QR204 typically comes with connector cables, which can be used in conjunction with the breadboard cables, or the connectors can be bypassed with female to female breadboard cables if necessary. Using male + female breadboard cables with the provided QR204 connectors is a more sturdy connection.

Connect the Printer to the ESP32:

- TX: Attach to Pin 16 on the ESP32
- RX: Attach to Pin 17
- GND: Ground; attach to one of the ESP32's GND pins

#### 3. Prepare the USB Cable

To be able to run the OTP assembly off of the USB power bank, you'll need to strip your USB cable so that the ESP32 and QR204 Voltage (VIN) and Ground (GND) pins are connected to the juice. 

#### 4. Connect Power

Attach the red wire (VIN) of the trash USB to the VIN cable of the QR204 and the VIN pin of the ESP32, and then attach the black wire (GND) of the USB to the GND cable and pin, with soldering, alligator clips, or, for austere builds, the breadboard cables can be stripped and twisted together with the USB wires. 

#### <a name="5_powass">[5. Power On the Assembly](#5-powass)</a>

That's all there is to it. Power it on and the ESP32 will send its RNG string to be printed as a single pair of keys. Hopefully you didn't forget to load a roll of thermal receipt paper in the printer. If you did, go ahead and load it and press the EN button on the ESP32 and it will send a new string to the printer.