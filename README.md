# Deneyap Dual Channel Motor Driver TC78H660FTG Arduino Library
[FOR TURKISH VERSION](docs/README_tr.md) ![trflag](https://github.com/deneyapkart/deneyapkart-arduino-core/blob/master/docs/tr.png)

***** Add photo ****

Arduino library for Deneyap Dual Channel Motor Driver TC78H660FTG

## :mag_right:Specifications 
- `Product ID` **M20**, **mpv1.0**
- `MCU` TC78H660FTG, STM8S003F3
- `Weight` 
- `Module Dimension`
- `I2C address` 0x16, 0x17, 0x18, 0x19

| Address |  | 
| :---    | :---     |
| 0x16| default address |
| 0x17| address when ADR1 pad is shorted |
| 0x18| address when ADR2 pad is shorted |
| 0x19| address when ADR1 and ADR2 pads are shorted |

## :closed_book:Documentation
Deneyap Dual Channel Motor Driver TC78H660FTG

[TC78H660FTG](https://www.mouser.com.tr/datasheet/2/408/TC78H660FTG_datasheet_en_20200714-1713920.pdf)

[How to install a Arduino Library](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap Dual Channel Motor Driver TC78H660FTG
This Arduino library allows you to use Deneyap Dual Channel Motor Driver TC78H660FTG with I2C peripheral. You can use this library in your projects with any Arduino compatible board with I2C peripheral.

## :globe_with_meridians:Repository Contents
- `/docs ` README_tr.md and product photos
- `/examples ` Examples with .ino extension sketches
- `/src ` Source files (.cpp .h)
- `keywords.txt ` Keywords from this library that will be highlighted in the Arduino IDE
- `library.properties ` General library properties for the Arduino package manager

## Version History
1.0.0 - initial release

## :rocket:Hardware Connections
- Deneyap Dual Channel Motor Driver TC78H660FTG and Board can be connected with I2C cable
- or 3V3, GND, SDA and SCL pins can be connected with jumper cables

|Dual Channel Motor Driver| Function | Board pins | 
|:--- |   :---  | :---|
|3.3V | Power   |3.3V |      
|GND  | Ground  | GND | 
|SDA  | I2C Data  | SDA pin |
|SCL  | I2C Clock | SCL pin |
|SWIM | Debug | no connection |
|RES  | Debug | no connection |
|IN1A|||
|IN1B|||
|IN2A|||
|IN2B|||
|STBY|||
|MODE|||

## :bookmark_tabs:License Information
Please review the [LICENSE](https://github.com/deneyapkart/deneyap-cift-kanalli-motor-surucu-arduino-library/blob/master/LICENSE) file for license information.