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

// Libraries
#include <GyverOLED.h>

// **************** USER VARIABLES / DEFINES / STATIC / STRUCTURES / CONSTANTS ****************

// Define I2C (Expansion Port)
#define I2C_SDA 6
#define I2C_SCL 7

// **************** OUTPUTS ****************
#define LED_Red 22  // Red LED

// OLED Instance. You will need to select your OLED Display. 
// Uncomment/Comment as needed.
GyverOLED<SSD1306_128x32, OLED_BUFFER> oled;  //0.6"
//GyverOLED<SSD1306_128x32, OLED_NO_BUFFER> oled;
//GyverOLED<SSD1306_128x64, OLED_BUFFER> oled;
//GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;
// GyverOLED<SSH1106_128x64> oled; //1.1"

// Draw Battery
void drawBattery(byte percent) {
  oled.drawByte(0b00111100);
  oled.drawByte(0b00111100);
  oled.drawByte(0b11111111);
  for (byte i = 0; i < 100 / 8; i++) {
    if (i < (100 - percent) / 8) oled.drawByte(0b10000001);
    else oled.drawByte(0b11111111);
  }
  oled.drawByte(0b11111111);
}

// **************** SETUP ****************
void setup() {
  // Stabalise
  delay(250);

  // Initialise UART
  Serial.begin(115200);
  while (!Serial)
    ;  // Wait for serial port to connect
  Serial.println("");

  // Initialise RED LED on GP22
  pinMode(LED_Red, OUTPUT);

  // Initialize I2C
  Wire.begin(I2C_SDA, I2C_SCL);

  Serial.println("ESPKnack - Example Code");
}

// **************** LOOP ****************
void loop() {

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(15, 0);
  oled.setScale(2);
  oled.print("ESPKite");
  oled.update();
  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(30, 1);
  oled.setScale(3);
  oled.print("LoRa");
  oled.update();
  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(15, 1);
  oled.setScale(2);
  oled.print("ESPKite");
  oled.update();
  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(15, 2);
  oled.setScale(2);
  oled.print("ESPKite");
  oled.update();
  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(30, 1);
  oled.setScale(3);
  oled.print("LoRa");
  oled.update();
  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(27, 1);
  oled.setScale(3);
  oled.print("RS485");
  oled.update();
  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(24, 1);
  oled.setScale(2);
  oled.print("GPIO");
  oled.update();
  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(30, 1);
  oled.setScale(3);
  oled.print("LoRa");
  oled.update();
  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(24, 1);
  oled.setScale(3);
  oled.print("Relay");
  oled.update();
  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(19, 1);
  oled.setScale(3);
  oled.print("5-60V");
  oled.update();
  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(13, 1);
  oled.setScale(2);
  oled.print("ESP32-C6");
  oled.update();
  delay(500);

  // Heatbeat LED
  digitalWrite(LED_Red, HIGH);
  delay(100);
  digitalWrite(LED_Red, LOW);
}
