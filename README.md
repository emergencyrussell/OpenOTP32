# OpenOTP32
## A Hardware One-Time Pad Printer for the Masses

• Current Version: 1.0.0

OpenOTP32 is a development board project that prints One-Time Pad keys on receipt paper using an ESP32 DevKitC v4 and a QR204 thermal printer. "Open" meaning open source, "OTP" meaning "One-Time Pad," and "32" to denote the ESP32 dev board.

The project was conceived to be as accessible and affordable as possible while maintaining good security.
The ESP32 was chosen since its random number generator feature (RNG) is superior to the decidedly inferior Arduino analog pin randomness.
I hope to elevate this project higher than that of a novelty toy, but people much smarter than me will have to make that determination. Toward this end, I have a couple concerns that I hope can be put to rest:

	*1) Is the ESP32 RNG sufficiently unpredictable?*

	*2) Do the WiFi/Bluetooth connectivity features of the ESP32 present a vulnerability?*