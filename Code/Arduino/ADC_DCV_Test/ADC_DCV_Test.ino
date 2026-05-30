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

// The ESP32-C6 has an effective ADC voltage range between 0V and 2.5V, although it can technically read up to (3.3V depending on the tolerances and calibration

// ****************  VARIABLES / DEFINES / STATIC ****************

// Constants
const int LoopDelay = 1;  // Loop Delay in Seconds

// Variables
float ADC_Voltage;
int DCV_Percentage;

// **************** OUTPUTS ****************
#define LED_Red 22   // Red LED
#define LED_Green 8  // Green LED

// **************** INPUTS ****************
#define ADC 0  // ADC (12-bit 0–4095 0-1.1V - Attenuation to 0-3.3V)

// ######### FUNCTIONS #########

// Map float values to percentages
float MapValues(float x, float DC_Min, float DC_Max, float Percentage_Min, float Percentage_Max) {
  return (x - DC_Min) * (Percentage_Max - Percentage_Min) / (DC_Max - DC_Min) + Percentage_Min;
}

// ######### SETUP #########
void setup() {

  // Stabalise
  delay(250);

  // Initialise UART:
  Serial.begin(115200, SERIAL_8N1);  //115200
  while (!Serial)
    ;
  Serial.println("");

  // LEDs
  pinMode(LED_Red, OUTPUT);
  pinMode(LED_Green, OUTPUT);

  // LEDs Default Off State
  digitalWrite(LED_Red, LOW);
  digitalWrite(LED_Green, LOW);

  // ADC
  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);  // 0 ~ 3.3V

  Serial.println("ESPKite Bring Up and Test Example Code");
}

// ######### LOOP #########
void loop() {

  // Raw ADC Value
  Serial.print("ADC Raw: ");
  Serial.print(analogRead(ADC));

  // Read DC Input Voltage
  ADC_Voltage = analogReadMilliVolts(ADC);
  ADC_Voltage = ADC_Voltage / 1000;  // mV

  Serial.print("\tADC Voltage: ");
  Serial.print(ADC_Voltage);
  Serial.print(" V ");

  ADC_Voltage = ADC_Voltage * 77.5;  // Scaled

  Serial.print("\tADC Scaled: ");
  Serial.print(ADC_Voltage);
  Serial.print(" V ");

  DCV_Percentage = MapValues(ADC_Voltage, 5, 75, 5, 100);  // Typically 5V to 75V
  Serial.print("\tDCV: ");
  Serial.print(DCV_Percentage);
  Serial.print(" % ");

  if (ADC_Voltage < 5.5)
    Serial.print("\t(USB Powered)");

  if (ADC_Voltage > 5.5)
    Serial.print("\t(DC Powered)");

  Serial.println("\n");

  // Heatbeat LED
  digitalWrite(LED_Red, HIGH);
  delay(50);
  digitalWrite(LED_Red, LOW);

  // Loop Delay
  delay(LoopDelay * 1000);
}
