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
#include "WiFi.h"  // Used only to get the unique number

// **************** USER VARIABLES / DEFINES / STATIC / STRUCTURES / CONSTANTS ****************

// **************** INPUTS ****************
#define User_GP02 2
#define User_GP09 9

// **************** OUTPUTS ****************
#define LED_Red 22  // Red LED

// Pin definitions
#define SPI_MOSI 18
#define SPI_MISO 20
#define SPI_SCK 19
#define SPI_CS 14

#define E22_IRQ 1
#define E22_NRST 21
#define E22_BUSY 3

SX1268 radio = new Module(SPI_CS, E22_IRQ, E22_NRST, E22_BUSY);

//Example Values.  Leave 00 between P2P testing.  Just compile as is, to all devices under test.
// uint8_t appEui[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
// uint8_t devEui[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
// uint8_t appKey[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

uint32_t counter = 0;
uint8_t payload[64];  // buffer for receive

// **************** SETUP ****************
void setup() {
  Serial.begin(115200);

  // Configure GPIO Inputs
  pinMode(User_GP02, INPUT_PULLUP);  // External GP2 Input
  pinMode(User_GP09, INPUT_PULLUP);  // User PGM/User Button

  //  Configures the specified LED GPIO as outputs
  pinMode(LED_Red, OUTPUT);

  // LEDs Default Off State
  digitalWrite(LED_Red, LOW);

  // Used only to get the unique number
  WiFi.mode(WIFI_MODE_STA);

  // initialize SPI
  SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI, SPI_CS);

  // initialize SX1262 FSK modem with default settings
  Serial.print(F("\n[SX1268 433 MHz] Initializing ... "));

  int state = radio.begin(433.0,  // frequency (MHz)
                          125.0,  // bandwidth (kHz)
                          9,      // spreading factor
                          5,      // coding rate
                          RADIOLIB_SX126X_SYNC_WORD_PRIVATE,
                          20,    // TX power (dBm)
                          8,     // preamble length
                          1.6);  // TCXO voltage (use 0.0 if no TCXO)

  if (state == RADIOLIB_ERR_NONE) {
    Serial.println(F("Initialise Success!"));
  } else {
    digitalWrite(LED_Red, HIGH);
    Serial.print(F("Initialise Failed, Code "));
    Serial.println(state);
    while (true) {
      delay(10);
    }
  }

  Serial.println(F("Ready!\n"));

  Serial.print("ESPKite MAC Address:\t");
  Serial.println(WiFi.macAddress());

  Serial.println("\nESPKite - LoRa 433 MHz Point-to-Point Messaging Test");
  Serial.println("Note USB Power Current Limitations.  DC Power Ideal");
  Serial.println("Press USER Button to send Message\n");
}

// **************** LOOP ****************
void loop() {

  // Turn off LED
  digitalWrite(LED_Red, LOW);

  // Check for Button Press
  if (digitalRead(User_GP02) == LOW) {

    Serial.print("Button GP02 Pressed\t");
    sendPacket();
  }

  // Check for Button Press
  if (digitalRead(User_GP09) == LOW) {

    Serial.print("Button GP09 Pressed\t");
    sendPacket();
  }

  // Receive Packet if Payload Available
  receivePacket();

  // Heartbeat LED
  digitalWrite(LED_Red, HIGH);
  delay(50);
}

// ====================== RECEIVE PACKET ======================
void receivePacket() {

  // Try to receive a packet
  int state = radio.receive(payload, sizeof(payload) - 1);  // leave 1 byte for null terminator

  if (state == RADIOLIB_ERR_NONE) {

    // Packet received successfully
    payload[sizeof(payload) - 1] = '\0';  // ensure null termination

    Serial.print(F("Received: "));
    Serial.print(F(" RSSI: "));
    Serial.print(radio.getRSSI());
    Serial.print(F(" dBm   SNR: "));
    Serial.print(radio.getSNR());
    Serial.print(F(" dB\tRX: "));
    Serial.println((char*)payload);
    delay(500);
  }
}

// ====================== SEND PACKET ======================
void sendPacket() {

  // Turn off LED
  digitalWrite(LED_Red, LOW);

  // Build a simple text message
  snprintf((char*)payload, sizeof(payload), "Hello from ESPKite %08X  #%lu", WiFi.macAddress(), counter);

  Serial.print(F("Sending: \t\t\tTX: "));
  Serial.println((char*)payload);

  int state = radio.transmit(payload, strlen((char*)payload));

  if (state == RADIOLIB_ERR_NONE) {

  } else {
    digitalWrite(LED_Red, HIGH);
    Serial.print(F("Sending Failed. Code "));
    Serial.println(state);
    while (true) {
      delay(10);
    }
  }

  counter++;
  delay(500);
}