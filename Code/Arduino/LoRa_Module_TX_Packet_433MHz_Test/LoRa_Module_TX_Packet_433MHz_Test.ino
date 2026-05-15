// REMEMBER TO PUT THE LORA ENABLE JUMPER ON - OR THIS CODE WILL NOT WORK.

// IMPORTANT: ENSURE AN ANTENNA, OR RF LOAD, IS CONNECTED TO THE LORA MODULE - BEFORE TX.  OTHERWISE DAMAGE TO THE LORA MODULE COULD RESULT.

// Libraries
#include <RadioLib.h>
#include <SPI.h>

// **************** USER VARIABLES / DEFINES / STATIC / STRUCTURES / CONSTANTS ****************

// Pin definitions
#define SPI_MOSI 18
#define SPI_MISO 20
#define SPI_SCK 19
#define SPI_CS 14

#define E22_IRQ 1
#define E22_NRST 21
#define E22_BUSY 3

SX1268 radio = new Module(SPI_CS, E22_IRQ, E22_NRST, E22_BUSY);

// **************** SETUP ****************
void setup() {
  Serial.begin(115200);

  SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI, SPI_CS);

  Serial.print(F("\n[SX1268 433 MHz] Initializing ... "));

  int state = radio.begin(433.0);
  if (state == RADIOLIB_ERR_NONE) {
    Serial.println(F("success!"));
  } else {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true) {
      delay(10);
    }
  }

  Serial.print("\nSending Packet\n");

  radio.setOutputPower(10);

  Serial.println("ESPKite Bring Up and Test Example Code");
  Serial.println("LoRa TX Packet 433 MHz");
}

// **************** LOOP ****************
void loop() {
  Serial.print("\nSending Packet\n");
  Serial.print(F("startTransmit code "));
  int transmissionState = radio.startTransmit("Hello World!");
  transmissionState = radio.startTransmit("Hello World!");
  transmissionState = radio.startTransmit("Hello World!");
  transmissionState = radio.startTransmit("Hello World!");
  transmissionState = radio.startTransmit("Hello World!");
  Serial.println(transmissionState);
  Serial.println("Test End\n");

  delay(2000);
}