# Deneyap Çift Kanallı Motor Sürücü Arduino Kütüphanesi

***** Fotoğraf eklenecek ****

Deneyap Çift Kanallı Motor Sürücü TC78H660FTG için Arduino kütüphanesidir.

## :mag_right:Özellikler 
- `Ürün ID` **M20**, **mpv1.0**
- `MCU` TC78H660FTG, STM8S003F3
- `Ağırlık`
- `Modul Boyutları` 25,4 mm x 38,1 mm
- `I2C Adres` 0x16, 0x17, 0x18, 0x19

| Adres |  | 
| :--- | :---     |
| 0x16 | varsayılan adres |
| 0x17 | ADR1 kısa devre yapıldığındaki adres |
| 0x18 | ADR2 kısa devre yapıldığındaki adres |
| 0x19 | ADR1 ve ADR2 kısa devre yapıldığındaki adres |

## :closed_book:Dokümanlar
[Deneyap Çift Kanallı Motor Sürücü](https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-module-deneyap-dual-channel-motor-driver-m)

[Deneyap Çift Kanallı Motor Sürücü Şematik](https://cdn.deneyapkart.org/media/upload/userFormUpload/M7vZpQGvXRLxsH7HJsgpplR93ygaxZ9P.pdf)

[Deneyap Çift Kanallı Motor Sürücü Teknik Çizim](https://cdn.deneyapkart.org/media/upload/userFormUpload/2EPBc4V9PklIkCudDzVfQ6MZSH6xxOCu.pdf)

[TC78H660FTG-datasheet](https://toshiba.semicon-storage.com/info/TC78H660FTG_datasheet_en_20200714.pdf?did=68604&prodName=TC78H660FTG)

[Arduino IDE'de Kütüphane Nasıl İndirilir](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap Çift Kanallı Motor Sürücü
Bu Arduino kütüphanesi Deneyap Çift Kanallı Motor Sürücü I2C çevre birimi ile kullanılmasını sağlar. Arduino ile uyumlu, I2C çevre birimine sahip herhangi bir geliştirme kartı ile bu kütüphaneyi projelerinizde kullanabilirsiniz.

## :globe_with_meridians:Repo İçeriği
- `/docs` README_tr.md ve ürün fotoğrafları
- `/examples` .ino uzantılı örnek uygulamalar
- `/src` kütüphane için .cpp ve .h uzantılı dosyalar
- `keywords.txt` Arduino IDE'de vurgulanacak anahtar kelimeler
- `library.properties` Arduino yöneticisi için genel kütüphane özellikleri

## Sürüm Geçmişi
1.1.1 - fonksiyonlar güncellendi, yeni hata fonksiyonu eklendi, yeni yapılandırma parametreleri eklendi, hatalar giderildi

1.1.0 - yeni class eklendi(Stepper), yeni fonksiyonlar eklendi(StepDriver, PwmConfig, StandBy, Mode, setSpeed, step), fonksiyon güncellendi(begin), yeni örnekler eklendi(StepMotorTamTurSurme, CiftKanalliDCmotorHizlanmasi, CiftKanalliDCmotorSurmeNoI2C, StepMotorSaatYonuSaatYonuTersi, StepMotorSurmeNoI2C), örnek güncellendi(CiftKanalliDCmotorSurme)

1.0.0 - ilk sürüm

## :rocket:Donanım Bağlantıları
- Deneyap Çift Kanallı Motor Sürücü ile kullanılan geliştirme kartı I2C kablosu ile bağlanabilir
- veya jumper kablolar ile 3V3, GND, SDA ve SCL bağlantıları yapılabilir. 

## Headers
|Çift Kanallı Motor Sürücü| Fonksiyon| Kart pinleri |
| :---     | :---   |   :---  |
| 3.3V     |3.3V Besleme Gerilimi| 3.3V    |
| GND      | Toprak |GND      |
| SDA      | Çift Yönlü Veri Hattı | SDA pini |
| SCL      | Veri Hattı Zaman Senkronizasyon İşareti	 | SCL pini|
|SWIM | Debug | bağlantı yok |
|RES  | Debug | bağlantı yok |
|IN1A	|Phase A |Dijital pin|
|IN1B	|Enable A|PWM pin|
|IN2A	|Phase B |Dijital pin|
|IN2B	|Enable B|PWM pin|
|STBY	|Standby pin|Dijital pin|
|MODE 	|Control mode select pin|Dijital pin|

## Terminal (Sol Alt)
|Module pin|Pins|
|:--- |   :---  |
|VM |Motor Power|
|GND|Motor Ground|

## Terminal (Sağ Alt)
|Module pin|Pins|
|:--- |   :---  |
|AO+|1. motor (+)|
|AO-|1. motor (-)|

## Terminal (Sağ Üst)
|Module pin|Pins|
|:--- |   :---  |
|BO+|2. motor (+)|
|BO-|2. motor (-)|

## :bookmark_tabs:Lisans Bilgisi 
Lisans bilgileri için [LICENSE](https://github.com/deneyapkart/deneyap-cift-kanalli-motor-surucu-arduino-library/blob/master/LICENSE) dosyasını inceleyin.
