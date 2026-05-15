/*
  Dave Williams, DitroniX 2019-2026 (ditronix.net)
  ESPKite - IoT ESP32-C6 Based Home and Industrial LoRa Controller SDK
  Features include ESPKite | ESP32-C6 LoRa SX1262 E22-900M22S E22-400M22S RS485 5-60V Relay

  ESPKite - Basic Bring Up Test Code - May 2026

  NB. To test the RS-485:
  * Simply connect another RS-485 device
  * Wiring A to A and B to B
    * Monitor in computer terminal if using USB-RS485
    * Use the 'RS485 RX' Code Example on another ESPKite, or ESPKnack, ESPuno Pi Zero etc.

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

// Libraries

// **************** USER VARIABLES / DEFINES / STATIC / STRUCTURES / CONSTANTS ****************

#include <Wire.h>

// Hardware Serial 1 pins - RS485
#define RXLP 4
#define TXLP 5
#define ENLP 23  // RS485 UART Enable

// **************** FUNCTIONS AND ROUTINES ****************

// **************** SETUP ****************
void setup() {
  // Stabalise
  delay(250);

  // Initialise UART
  Serial.begin(115200);
  while (!Serial)
    ;  // Wait for serial port to connect
  Serial.println("");

  // Initialise UART 1 - RS485 Port
  Serial1.begin(9600, SERIAL_8N1, RXLP, TXLP);  //LP
  while (!Serial)
    ;

  Serial.println("UART 1 Opened (RS485 Port)");

  //Initialise RS485 UART Enable on GP23
  pinMode(ENLP, OUTPUT);

  Serial.println("ESPKite Bring Up and Test Example Code");
  Serial.println("Running RS485 RX Test");
}

// **************** LOOP ****************
void loop() {

  // Force RS485 UART Driver Disabled and Receiver is Enabled
  digitalWrite(ENLP, LOW);

  if (Serial1.available() > 0) {

    // Read Incomming Byte from RS485 UART and Output to the Serial Monitor
    char incomingbyte = Serial1.read();
    Serial.print(incomingbyte);
  }
}
