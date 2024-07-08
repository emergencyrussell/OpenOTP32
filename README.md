# OpenOTP-32

• Current Version: 0.1.0

![An OpenOTP-32 in action](/assets/images/openotp32-1.jpg)

## *A DIY Hardware One-Time Pad Printer for the Masses*

# Contents:
## <a name="i-intro">[Introduction](#i_intro)</a>
## <a name="b-building">[Building](#b_building)</a>
### <a name="p-parts">[Parts](#p_parts)</a>
### <a name="t-tools">[Tools](#t_tools)</a>
### <a name="instal-ass">[Installation & Assembly](#instal_ass)</a>
1. <a name="1-upsketch">[Upload the Sketch](#1_upsketch)</a>
  
  - <a name="1-1-detesp">[Detecting the ESP32 on Your Machine](#1_1_detesp)</a>
  
  - <a name="1-2-instalib">[Installing the Needed Libraries](#1_2_instalib)</a>

2. <a name="2-preprint">[Prepare the Thermal Printer](#2_preprint)</a>

3. <a name="3-prepusb">[Prepare USB Cable](#3_prepusb)</a>

4. <a name="4-conpow">[Connect Power](#4_conpow)</a>

5. <a name="5-powass">[Power On the Assembly](#5_powass)</a>

## <a name="u-usage">[Usage](#u_usage)</a>

<a name="i_intro">First some background:</a>

OpenOTP-32 is a development board project that prints One-Time Pad keys on thermal receipt paper using an ESP32 DevKitC v4 and a QR204 thermal printer. "Open" meaning open source, "OTP" meaning "One-Time Pad," and "32" to denote the ESP32 dev board.

The project was inspired by the ADL-1 and was conceived to be as accessible and affordable as possible while still maintaining good security.
The ESP32 was chosen since its random number generator feature (RNG) is superior to the reportedly inferior Arduino analog pin randomness and it maintains good affordability.

I hope to elevate this project higher than that of a novelty toy, but people much smarter than me will have to help make that determination. Toward this end, I have a couple concerns that I hope can be put to rest:

### *1. Is the ESP32 RNG sufficiently unpredictable?*

> [The hardware RNG produces true random numbers…](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/random.html)

> A data sample of 2 GB, which is read from the random number generator at a rate of 5 MHz with only the highspeed ADC being enabled, has been tested using the Dieharder Random Number Testsuite (version 3.31.1). The sample passed all tests.

*—[ESP32 Technical Reference Manual, RNG, 25.3 Functional Description](https://www.espressif.com/sites/default/files/documentation/esp32_technical_reference_manual_en.pdf#rng)*

### *2. Do the WiFi/Bluetooth connectivity features of the ESP32 present a vulnerability?*

Ϩ-(ツ)-S

### Now then, let's get down to business:

## <a name="b_building">[Building](#b-building)</a>
### <a name="p_parts">[Parts](#p-parts)</a>
##### (your build may vary)
- ESP32: ~$5 - $10
- QR204: ~$30 - $40
- 57mm thermal receipt paper: ~$2/roll
- 2A-output USB power bank (USB already provides the correct voltage, 5V): ~$20 - $50
- Breadboard extension cables (male-female, or female-female): ~$5
- Trash USB cable: about five bucks new, if you reeeally can't find one lying around

Total ends up being from $67 to $112 or so, depending on what parts you already have. Compare to the $280 ADL-1.

#### ESP32
- Sketch is written using Arduino IDE v1.8.
- Installed are the Adafruit Thermal Printer and the EspSoftwareSerial libraries.
- Pins 16 and 17 send and receive data between the QR204.

#### QR204
- The "Tiny" model of Adafruit thermal printer, again, documented [here](https://cdn-learn.adafruit.com/downloads/pdf/mini-thermal-receipt-printer.pdf).
- It's a fun little printer. I recommend playing around with it to see all the cool things you can do with it. :)

#### Power Bank
2A output. Per the [Adafruit documentation](https://cdn-learn.adafruit.com/downloads/pdf/mini-thermal-receipt-printer.pdf), a current of 2A is required for the printer to function. This means the low-end 1A power banks won't cut it.

### <a name="t_tools">[Tools](#t-tools)</a>
- A wire stripper (or sharp edge)
- (Optional) Soldering iron and solder



### <a name="instal_ass">[Installation & Assembly](#instal-ass)</a>


#### 1. <a name="1_upsketch">[Upload the Sketch](#1-upsketch)</a>
After setting up your machine to detect the ESP32 and installing the necessary libraries, upload the [provided code](/OpenOTP32/OpenOTP32.ino) from the Arduino IDE v1.8 to the ESP32 board.

In the code, the `sequenceLength` variable determines how many digits the key uses. The code will automatically group the numbers into five digits and will automatically line break after 25 digits, or five groups of five. These groupings were determined based off the printing width, but the `sequenceLength` variable is made to play with. You can have a whole CVS receipt of a One-Time Pad key if you like :)

##### <a name="1_1_detesp">[Detecting the ESP32 on Your Machine](#1-1-detesp)</a>
You may need some drivers to get your machine to detect the ESP32: I used the [Silicon Labs CP210x VCP Windows Driver](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads) (Third option down).

##### <a name="1_2_instalib">[Installing the Needed Libraries](#1-2-instalib)</a>:

- [Adafruit Thermal Printer Library](https://github.com/adafruit/Adafruit-Thermal-Printer-Library)
- [EspSoftware Serial](https://github.com/plerup/espsoftwareserial)

Sketch -> Include Library -> Add .ZIP Library…


#### 2. <a name="2_preprint">[Prepare the Thermal Printer](#2-preprint)</a>

Depending on your cable situation, you may need to solder. The QR204 typically comes with connector cables, which can be used in conjunction with the breadboard jumpers, or the connectors can be bypassed with female to female breadboard jumpers if necessary. Using male-female breadboard jumpers with the provided QR204 connectors is a more sturdy temporary connection. The breadboard jumpers should be sufficient for the data connections.

Connect the Printer to the ESP32:

- TX: Attach to Pin 16 on the ESP32
- RX: Attach to Pin 17
- GND: Ground; attach to one of the ESP32's GND pins


#### 3. <a name="3_prepusb">[Prepare the USB Cable](#3-prepusb)</a>

To be able to run the OTP assembly off the USB power bank, you'll need to strip your USB cable so that the ESP32 and QR204 Voltage (VIN) and Ground (GND) pins are connected to the juice. 


#### 4. <a name="4_conpow">[Connect Power](#4-conpow)</a>

Attach the red wire (VIN) of the trash USB to the VIN cable of the QR204 and the VIN pin of the ESP32, and then attach the black wire (GND) of the USB to the GND cable and pin, with soldering, alligator clips, or, for austere builds, the breadboard jumpers can be stripped and twisted together with the USB wires. For more permanent builds, the [Adafruit Thermal Printer Manual](https://cdn-learn.adafruit.com/downloads/pdf/mini-thermal-receipt-printer.pdf) (p.11) cautions that "breadboard wires are small gauge and not suited to continuous heavy power draw," so sturdier-gauge wires should be implemented.


#### 5. <a name="5_powass">[Power On the Assembly](#5-powass)</a>

Plug the USB cable into the power bank and switch on. That's all there is to it. Once powered, the ESP32 will send its RNG string to be printed as a single pair of identical keys. Hopefully you didn't forget to load a roll of thermal receipt paper in the printer. If you did, go ahead and load it and press the EN button on the ESP32 and it will send a new set of random digits to the printer.

![Identical key pair](/assets/images/openotp32-2.jpg)

# <a name="u_usage">[Usage](#u-usage)</a>

![One-Time Pad codex](/assets/images/openotp32-3.jpg)

First convert your plaintext using your codex (e.g. above). Then, to encrypt, subtract the random digits from the plaintext conversion. If you get a negative number, add ten. This way, you always maintain a digit from 0-9. Once the encryption is complete, you can send the seemingly random string of numbers to your friend :)

To decrypt, it's a similar process, but in reverse. Since your friend has an identical key, they can add the key and if they get more than 9 when decrypting, they subtract ten. They then convert the numbers back to plaintext and read your message. 

Advanced usage of the One-Time Pad incorporates a codebook, using number sequences to represent common words or phrases, which adds an extra layer of security.

What sets the One-Time Pad apart from its less-secure ancestor, Vigenère, is its key length and the principle of only ever using a key once. If you use a key to encrypt or decrypt a message, you must never use the key again or all the messages you send with it can no longer be considered secure. Best practice is to destroy the key. Thermal paper is particularly ideal in this regard, since the numbers are printed with heat (*thermally* even) they can be destroyed with heat. Generate friction with your fingernail or pour your kettle over it and watch the numbers vanish.