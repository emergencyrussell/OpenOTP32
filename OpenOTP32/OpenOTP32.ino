// Hardware One-Time Pad tossed together by Emergency Russell
//
// ESP-32 DevKitC v4 driving a QR-204 thermal printer
//
// Send secret messages to your friends :)

#include <Adafruit_Thermal.h>
#include <SoftwareSerial.h>
#include "esp_system.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"

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
  
  //bootloader_random_enable();
  esp_adc_cal_characteristics_t *adc_chars = (esp_adc_cal_characteristics_t*) calloc(1, sizeof(esp_adc_cal_characteristics_t));
  adc1_config_width(ADC_WIDTH_BIT_12);
  adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_0);
  esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_0, ADC_WIDTH_BIT_12, 1100, adc_chars);
  
  // Create empty String to populate with random numbers
  String randSeq = "";
  
  // Preparing the String and formatting into groups of five
  for (int i = 0; i < sequenceLength; i++) {
    uint32_t randomDigit = esp_random() % 10; // Gen random digit
    randSeq += String(randomDigit);
    if ((i + 1) % 5 == 0) {
      randSeq += " ";
    }
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