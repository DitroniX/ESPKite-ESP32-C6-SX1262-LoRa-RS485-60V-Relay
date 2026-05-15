## ESPKite, ESP32-C6, LoRa 868MHz SX1262, LoRa 433MHz SX1268, RS485, 5-60V, Relay Output

**Supporting STEM Electronic Internet of Things & Home Automation Technology for Smart Energy Monitoring**

Availability Late May 2026.

## Welcome to ESPKite
[![DitroniX WiKi Pages](https://github.com/DitroniX/ESPKite-ESP32-C6-SX1262-LoRa-RS485-60V-Relays/blob/main/Datasheets%20and%20Information/GitHub%20WiKi.png?raw=true)](https://github.com/DitroniX/ESPKite-ESP32-C6-SX1262-LoRa-RS485-60V-Relays/wiki)

[**For Latest Project Updates - Click Here**](https://github.com/DitroniX/ESPKite-ESP32-C6-SX1262-LoRa-RS485-60V-Relays#updates)

![ESPKite PreProduction Family](https://github.com/DitroniX/ESPKite-ESP32-C6-SX1262-LoRa-RS485-60V-Relay/blob/main/Datasheets%20and%20Information/ESPKite%20Family%20-%20Feature.png)
![ESPKite PreProduction 868MHz](https://github.com/DitroniX/ESPKite-ESP32-C6-SX1262-LoRa-RS485-60V-Relay/blob/main/Datasheets%20and%20Information/ESPKite%20868%20MHz%20-%20Feature.png)
![ESPKite PreProduction 433MHz](https://github.com/DitroniX/ESPKite-ESP32-C6-SX1262-LoRa-RS485-60V-Relay/blob/main/Datasheets%20and%20Information/ESPKite%20433%20MHz%20-%20Feature.png)


ESPKite Board (850-930MHz)           |  ESPKite Complete Kit  (850-930MHz)    |  ESPKite 433 MHz (410-493MHz) Version 
:-------------------------:|:-------------------------:|:-------------------------:
![ESPKite](https://github.com/DitroniX/ESPKite-ESP32-C6-SX1262-LoRa-RS485-60V-Relay/blob/main/Datasheets%20and%20Information/ESPKite%20433MHz%20Features%20(Thumb).png)  |  ![ESPKite](https://github.com/DitroniX/ESPKite-ESP32-C6-SX1262-LoRa-RS485-60V-Relay/blob/main/Datasheets%20and%20Information/ESPKite%20KIT%20-%20Features%20(Thumb).png)  |  ![ESPKite](https://github.com/DitroniX/ESPKite-ESP32-C6-SX1262-LoRa-RS485-60V-Relay/blob/main/Datasheets%20and%20Information/ESPKite%20433MHz%20Features%20(Thumb).png)

## What is the ESPKite?

**ESPKite** is a compact, feature rich, SDK board with a range of IoT technologies.
* Espressif ESP32-C6 MCU (WiFi 2.4GHz BT Zigbee Thread)
* LoRa (EByte E22-900M22S with Semtech SX1262), module covering 850 MHz through to 930 MHz.
    * Optional EByte E22-400M22S with Semtech SX1268, for 410 to 493MHz Version.
* SMA Female (LoRa Antenna Connector)
* RS485 Interface CS48520AD with ±20kV ESD Protection (RS-485 / DMX)
* Relay (NO 3A 30VDC 250VAC)
* GPIO (20V Voltage Tolerant)
* TMP102 On-board Digital Temperature Sensor
* EEPROM (24C64 64Kbit with Noise suppression function Built-in power-on reset, POR)
* Internal High Voltage SMPS (Power directly from 5-60V DC supply).
* Internal Expansion Ports (I2C and SPI, for Display and MicroSD)
* Compact board (77mm x 49mm)
* 4 x Terminal Blocks
* Type C USB is connected to a CH343P UART / 5V Power
* DIN Enclosure Mountable (Maybe alternatively screw fixed)

## Semtech 

* E22-900M22S SX1262
    * Operating Frequency: 850-930 MHz (868/915. Default: 868 MHz)
* E22-400M22S SX1268
    * Operating Frequency: 410~493 MHz (433/470. Default: 433 MHz

Both E22 modules feature:

* Modulation: LoRa™, GFSK
* Interface: SPI
* Transmitter RF Power Output: 22 dBm (~160mW)
* Receiver Sensitivity: -147 dBm (Low sensitivity)
* Communication Distance: Up to 6-7 km (in open, clear air)
* Integrated TCXO (32MHz crystal oscillator)
* E22 Module Current
    * RX current up to approx 7mA.
    * TX current up to approx 119mA.
    * Sleep current approx 2nA.


## The Board

The ESPKite board has been designed to be compact and practical.

![ESPKite Bpards](https://github.com/DitroniX/ESPKite-ESP32-C6-SX1262-LoRa-RS485-60V-Relay/blob/main/Datasheets%20and%20Information/ESPKite%20433MHz%20and%20868MHz.png)
![ESPKite Enclosures](https://github.com/DitroniX/ESPKite-ESP32-C6-SX1262-LoRa-RS485-60V-Relay/blob/main/Datasheets%20and%20Information/ESPKite%20868MHz%20433MHz.png)



* A power enable PCB jumper is available to aid LoRa firmware development, or protect the PA if no antenna, or RF load, is fitted.

* DC supply range from 5V to 60V, with maximum of 75V, is achieved via an on-board SMPS.

* Should you wish to use Wi-Fi, BT, Zigbee, the ESP32-C6 uses an IPEX MHF3 U.FL connector.

* RS485 load enable PCB jumper is provided.  This would normally be fitted to enable the 120R load.

* Relay provides set of dry contacts, normally open.  These are galvanically isolated and can switch 3A (30V DC, or 250V AC).

* MCU Reset and PGM/User tactile buttons are slightly height extended, for enclosure.


## Updates
-   26-05-15 - Next Stage: Finish testing and then order production boards next week.
-   26-05-15 - ESPKite Enclosures, complete with Labels
-   26-05-15 - Preproduction 868 MHz and 433 MHz boards being tested
-   26-05-05 - The DitroniX Shop is taking Pre-Orders (discounted until end May)
-   26-05-05 - Added new 433MHz E22-400M22S version.  410 to 493MHz.  
-   26-05-04 - In PreProduction
-   26-04-14 - Preliminary Information


## **Purchase**

* DitroniX Shop - You may also pre-order, and order, via the http://ditronix.net 

* eBay - Our STEM SDK boards and accessories are available from our online shops on [eBay](https://www.ebay.co.uk/usr/ditronixuk) 

[![Display-Type-B](https://raw.githubusercontent.com/DitroniX/DitroniX/main/Files/DitroniX.net%20STEM%20IoT%20eBay.jpg?raw=true)](https://www.ebay.co.uk/usr/ditronixuk)


## **Further Information**

Additional information, and other technical details on this project, maybe found in the related repository pages.

**Repository Folders**

 - **Code** *(Code examples for Arduino  IDE, Raspberry Pi and PlatformIO)*
 -  **Datasheets and Information** *(Component Datasheets, Schematics, Board Layouts, Photos, Technical Documentation)*
 - **Certification** *(Related Repository Project or Part, Certification Information)*

**Repository Tabs**

 - **Wiki** *(Related Repository Wiki pages and Technical User Information)*
 - **Discussions** *(Related Repository User Discussion Forum)*
 - **Issues** *(Related Repository Technical Issues and Fixes)*

***

We value our Customers, Users of our designs and STEM Communities, all over the World . Should you have any other questions, or feedback to share to others, please feel free to:

* Visit the related [Project](https://github.com/DitroniX?tab=repositories) *plus the related* **Discussions** and **Wiki** Pages.  See tab in each separate repository.
* **Project Community Information** can be found at https://www.hackster.io/DitroniX
* [DitroniX.net Website - Contact Us](https://ditronix.net/contact/)
* **Twitter**: [https://twitter.com/DitroniX](https://twitter.com/DitroniX)
* [Supporting the STEM Projects - BuyMeACoffee](https://www.buymeacoffee.com/DitroniX)
*  **LinkedIN**: [https://www.linkedin.com/in/g8puo/](https://www.linkedin.com/in/g8puo/)

***Dave Williams, Maidstone, UK.***

Electronics Engineer | Software Developer | R&D Support | RF Engineering | Product Certification and Testing | STEM Ambassador

## STEM

**Supporting [STEM Learning](https://www.stem.org.uk/)**

Life is one long exciting learning curve, help others by setting the seed to knowledge.

![DitroniX Supporting STEM](https://hackster.imgix.net/uploads/attachments/1606838/stem_ambassador_-_100_volunteer_badge_edxfxlrfbc1_bjdqharfoe1_xbqi2KUcri.png?auto=compress%2Cformat&w=540&fit=max)
