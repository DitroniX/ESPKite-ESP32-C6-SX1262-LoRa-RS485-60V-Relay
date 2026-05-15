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

/*
  ESPKite Bring Up and Test Example Code

  ESP32-C6 Initialized - 'C6 Factory Default Port Assignment Test'

  MOSI: 22
  MISO: 23
  SCL / SCLK: 21
  CS / SS: 0

  SDA: 19
  SCL: 18
*/

// Libraries
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

void setup() {
  // Stabalise
  delay(250);

  // Initialise UART
  Serial.begin(115200, SERIAL_8N1);  // 115200
  while (!Serial)
    ;
  Serial.println("");

  Serial.println("ESPKite Bring Up and Test Example Code");  

  Serial.println("\nESP32-C6 Initialized - 'C6 Factory Default Port Assignment Test'\n");

  Serial.print("MOSI: ");
  Serial.println(MOSI);

  Serial.print("MISO: ");
  Serial.println(MISO);

  Serial.print("SCL / SCLK: ");
  Serial.println(SCK);

  Serial.print("CS / SS: ");
  Serial.println(SS);

  Serial.print("\nSDA: ");
  Serial.println(SDA);

  Serial.print("SCL: ");
  Serial.println(SCL);
}

void loop() {}