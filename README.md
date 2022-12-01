# Deneyap Dual Channel Motor Driver Arduino Library
[FOR TURKISH VERSION](docs/README_tr.md) ![trflag](https://github.com/deneyapkart/deneyapkart-arduino-core/blob/master/docs/tr.png)

***** Add photo ****

Arduino library for Deneyap Dual Channel Motor Driver TC78H660FTG

## :mag_right:Specifications 
- `Product ID` **M20**, **mpv1.0**
- `MCU` TC78H660FTG, STM8S003F3
- `Weight` 
- `Module Dimension` 25,4 mm x 38,1 mm
- `I2C address` 0x16, 0x17, 0x18, 0x19

| Address |  | 
| :---    | :---     |
| 0x16| default address |
| 0x17| address when ADR1 pad is shorted |
| 0x18| address when ADR2 pad is shorted |
| 0x19| address when ADR1 and ADR2 pads are shorted |

## :closed_book:Documentation
[Deneyap Dual Channel Motor Driver](https://docs.deneyapkart.org/en/content/contentDetail/deneyap-module-deneyap-dual-channel-motor-driver-m)

[Deneyap Dual Channel Motor Driver Shematic](https://cdn.deneyapkart.org/media/upload/userFormUpload/M7vZpQGvXRLxsH7HJsgpplR93ygaxZ9P.pdf)

[Deneyap Dual Channel Motor Driver Mechanical Drawing](https://cdn.deneyapkart.org/media/upload/userFormUpload/2EPBc4V9PklIkCudDzVfQ6MZSH6xxOCu.pdf)

[TC78H660FTG-datasheet](https://toshiba.semicon-storage.com/info/TC78H660FTG_datasheet_en_20200714.pdf?did=68604&prodName=TC78H660FTG)

[How to install a Arduino Library](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap Dual Channel Motor Driver
This Arduino library allows you to use Deneyap Dual Channel Motor Driver with I2C peripheral. You can use this library in your projects with any Arduino compatible board with I2C peripheral.

## :globe_with_meridians:Repository Contents
- `/docs ` README_tr.md and product photos
- `/examples ` Examples with .ino extension sketches
- `/src ` Source files (.cpp .h)
- `keywords.txt ` Keywords from this library that will be highlighted in the Arduino IDE
- `library.properties ` General library properties for the Arduino package manager

## Version History
1.1.0 - added new class(Stepper), added new functions(StepDriver, PwmConfig, StandBy, Mode, setSpeed, step), updated function(begin), added new sketches(StepMotorTamTurSurme, CiftKanalliDCmotorHizlanmasi, CiftKanalliDCmotorSurmeNoI2C, StepMotorSaatYonuSaatYonuTersi, StepMotorSurmeNoI2C), updated sketch(CiftKanalliDCmotorSurme)

1.0.0 - initial release

## :rocket:Hardware Connections
- Deneyap Dual Channel Motor Driver and Board can be connected with I2C cable
- or 3V3, GND, SDA and SCL pins can be connected with jumper cables

## Headers
|Dual Channel Motor Driver| Function | Board pins | 
|:--- |   :---  | :---|
|3.3V | Power   |3.3V |      
|GND  | Ground  | GND | 
|SDA  | I2C Data  | SDA pin |
|SCL  | I2C Clock | SCL pin |
|SWIM | Debug | no connection |
|RES  | Debug | no connection |
|IN1A	|Phase A |Digital pin|
|IN1B	|Enable A|PWM pin|
|IN2A	|Phase B |Digital pin|
|IN2B	|Enable B|PWM pin|
|STBY	|Standby pin|Digital pin|
|MODE 	|Control mode select pin|Digital pin|

## Terminal (Left Down)
|Module pin|Pins|
|:--- |   :---  |
|VM |Motor Power|
|GND|Motor Ground|

## Terminal (Right Down)
|Module pin|Pins|
|:--- |   :---  |
|AO+|1. motor (+)|
|AO-|1. motor (-)|

## Terminal (Right Up)
|Module pin|Pins|
|:--- |   :---  |
|BO+|2. motor (+)|
|BO-|2. motor (-)|

## :bookmark_tabs:License Information
For step motor's class based on [Stepper Library for Arduino Library](https://github.com/arduino-libraries/Stepper). Changed to work with Deneyap Dual Motor Driver.

Please review the [LICENSE](https://github.com/deneyapkart/deneyap-cift-kanalli-motor-surucu-arduino-library/blob/master/LICENSE) file for license information.