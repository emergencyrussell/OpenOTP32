// Hardware One-Time Pad tossed together by Emergency Russell
//
// ESP-32 DevKitC v4 driving a QR-204 thermal printer
//
// Send secret messages to your friends :)

#include <Adafruit_Thermal.h>
// EspSoftwareSerial library:
#include <SoftwareSerial.h>

// Define the RX and TX pins for the SoftwareSerial
#define TX_PIN 17
#define RX_PIN 16

int sequenceLength = 400;

// Create SoftwareSerial object for the thermal printer
SoftwareSerial mySerial(RX_PIN, TX_PIN);

// Create Adafruit_Thermal object
Adafruit_Thermal printer(&mySerial);

void setup() {
  // Start the software serial communication
  mySerial.begin(9600);

  // Create empty String to populate with random numbers
  String randSeq = "";

  // Preparing the String and formatting into groups of five
  for (int i = 0; i < sequenceLength; i++) {
    uint32_t randomDigit = esp_random() % 10; // Gen random digit
    randSeq += String(randomDigit);
    
	// How many digits per group (DPG; default, five)
	if ((i + 1) % 5 == 0) {
      randSeq += " ";
    }
	
	// How many digits per line (DPL; default, twenty-five)
    if ((i + 1) % 25 == 0) {
      randSeq += "\n";
    }
  }

  //Print a single key pair
  printer.println(randSeq);
  printer.println("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
  printer.feed(2);
  printer.println(randSeq);
  printer.println("-----------------------------");
}

void loop() {
  // Mischief Managed (:
}
