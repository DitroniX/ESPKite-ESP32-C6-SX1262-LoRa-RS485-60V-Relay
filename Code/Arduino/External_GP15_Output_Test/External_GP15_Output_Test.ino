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

// ****************  VARIABLES / DEFINES / STATIC / STRUCTURES / CONSTANTS ****************

// **************** INPUTS ****************

// **************** OUTPUTS ****************
#define LED_Green 8  // LED_Green
#define LED_Red 22   // LED_Red
#define User_GP15 15  // External Output

// **************** SETUP ****************
void setup() {

  // Stabalise
  delay(250);

  // Initialise UART
  Serial.begin(115200, SERIAL_8N1);  // 115200
  while (!Serial)
    ;
  Serial.println("");

  //  Configures Outputs
  pinMode(LED_Green, OUTPUT);
  pinMode(LED_Red, OUTPUT);

  // LEDs Default Off State
  digitalWrite(LED_Green, LOW);
  digitalWrite(LED_Red, LOW);

  // Configure GPIO Output
  pinMode(User_GP15, OUTPUT);

  // Configure GPIO Output State
  digitalWrite(User_GP15, LOW);

  Serial.println("ESPKite Bring Up and Test Example Code");
  Serial.println("Cycling GP15 Output High Low");
}

// **************** LOOP ****************
void loop() {

  digitalWrite(User_GP15, HIGH);
  digitalWrite(LED_Green, HIGH);
  delay(1000);
  digitalWrite(User_GP15, LOW);
  digitalWrite(LED_Green, LOW);
  delay(1000);

  // LED Heartbeat
  digitalWrite(LED_Red, HIGH);
  delay(50);
  digitalWrite(LED_Red, LOW);
  delay(500);
}
