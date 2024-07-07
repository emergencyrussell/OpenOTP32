# OpenOTP32
## A Hardware One-Time Pad Printer for the Masses

• Current Version: 1.0.0

OpenOTP32 is a development board project that prints One-Time Pad keys on receipt paper using an ESP32 DevKitC v4 and a QR204 thermal printer. "Open" meaning open source, "OTP" meaning "One-Time Pad," and "32" to denote the ESP32 dev board.

The project was conceived to be as accessible and affordable as possible while maintaining good security.
The ESP32 was chosen since its random number generator feature (RNG) is superior to the decidedly inferior Arduino analog pin randomness.

I hope to elevate this project higher than that of a novelty toy, but people much smarter than me will have to make that determination. Toward this end, I have a couple concerns that I hope can be put to rest:

*1. Is the ESP32 RNG sufficiently unpredictable?*

*2. Do the WiFi/Bluetooth connectivity features of the ESP32 present a vulnerability?*

## Building
To build the OpenOTP32, you will need a power source to connect both the ESP32 and the QR204.

For portable builds, you obviously need a battery system of some sort. Five volts is ideal. You don't want more than 9V for the printer, and from what I read, the ESP32 won't like dealing with extra voltage. Two-amp draw is also required for the printer. I opted for a USB power bank phone charger since I already had one available and it met the necessary power specifications, which can be read in detail within the [printer's datasheet](https://cdn-learn.adafruit.com/downloads/pdf/mini-thermal-receipt-printer.pdf).

### Parts
##### (your build may vary)
- ESP32
- QR204
- 5v, 2A USB power bank
- Breadboard pins
- Trash USB cable

#### ESP32
- Sketch is written using Arduino IDE v1.8.
- Installed are the Adafruit Thermal Printer and the EspSoftwareSerial libraries.
- Pins 16 and 17 send and receive data between the QR204.

#### QR204
- The "Tiny" model of Adafruit thermal printer, again, documented [here](https://cdn-learn.adafruit.com/downloads/pdf/mini-thermal-receipt-printer.pdf).

#### Power Bank
5V, 2A. Per the [Adafruit documentation](https://cdn-learn.adafruit.com/downloads/pdf/mini-thermal-receipt-printer.pdf), a current of 2A is required for the printer to function.