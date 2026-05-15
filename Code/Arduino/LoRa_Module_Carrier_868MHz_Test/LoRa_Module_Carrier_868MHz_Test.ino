/*
  Dave Williams, DitroniX 2019-2026 (ditronix.net)
  ESPKite - IoT ESP32-C6 Based Home and Industrial LoRa Controller SDK
  Features include ESPKite | ESP32-C6 LoRa SX1262 E22-900M22S E22-400M22S RS485 5-60V Relay

  ESPKite - Basic Bring Up Test Code - May 2026

  Remember!
  - Set the BOARD to Use ESP32C6 Dev Module (or similar).
  - You can also set the BAUD rate up to 921600 to speed up flashing.
  - The SDK does NOT need external power to flash.  It will take Power from the USB 5V.
  - The Serial Monitor is configured for BAUD 115200
  
  The purpose of this test code is to cycle through the various main functions of the board as part of bring up testing.
  .
  This test code is OPEN SOURCE and formatted for easier viewing.  Although is is not intended for real world use, it may be freely used, or modified as needed.
  It is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.

  Further information, details and examples can be found on our website or github.com/DitroniX

  * github.com/DitroniX
  * github.com/DitroniX/ESPKite-ESP32-C6-SX1262-LoRa-RS485-60V-Relay
  * github.com/DitroniX/ESPKite-ESP32-C6-SX1262-LoRa-RS485-60V-Relay/wiki
  * hackster.io/DitroniX/espkite-esp32-c6-sx1262-lora-rs485-5-60v-relay-output-8891a3
*/

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

SX1262 radio = new Module(SPI_CS, E22_IRQ, E22_NRST, E22_BUSY);

// **************** SETUP ****************
void setup() {
  // Stabalise
  delay(250);

  // Initialise UART
  Serial.begin(115200);
  while (!Serial)
    ;  // Wait for serial port to connect
  Serial.println("");

  SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI, SPI_CS);

  Serial.print(F("\n[SX1262] Initializing ... "));

  int state = radio.begin(868.0);
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
  Serial.println("LoRa TX 868 MHz");
}

// **************** LOOP ****************
void loop() {
  Serial.print("\nSending Packet\n");
  Serial.print(F("startTransmit code "));
  int transmissionState = radio.startTransmit("Hello World!");
  Serial.println(transmissionState);
  Serial.println("Test End\n");

  delay(2000);
}