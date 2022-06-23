# Deneyap Çift Kanallı Motor Sürücü TC78H660FTG Arduino Kütüphanesi

***** Fotoğraf eklenecek ****

Deneyap Çift Kanallı Motor Sürücü TC78H660FTG için Arduino kütüphanesidir.

## :mag_right:Özellikler 
- `Ürün ID` **M20**, **mpv1.0**
- `MCU` TC78H660FTG, STM8S003F3
- `Ağırlık`
- `Modul Boyutları` 
- `I2C Adres` 0x16, 0x17, 0x18, 0x19

| Adres |  | 
| :--- | :---     |
| 0x16 | varsayılan adres |
| 0x17 | ADR1 kısa devre yapıldığındaki adres |
| 0x18 | ADR2 kısa devre yapıldığındaki adres |
| 0x19 | ADR1 ve ADR2 kısa devre yapıldığındaki adres |

## :closed_book:Dokümanlar
Deneyap Çift Kanallı Motor Sürücü

[TC78H660FTG](https://www.mouser.com.tr/datasheet/2/408/TC78H660FTG_datasheet_en_20200714-1713920.pdf)

[Arduino Kütüphanesi Nasıl İndirilir](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap Çift Kanallı Motor Sürücü TC78H660FTG
Bu Arduino kütüphanesi Deneyap Çift Kanallı Motor Sürücü TC78H660FTG I2C çevre birimi ile kullanılmasını sağlar. Arduino ile uyumlu, I2C çevre birimine sahip herhangi bir geliştirme kartı ile bu kütüphaneyi projelerinizde kullanabilirsiniz.

## :globe_with_meridians:Repo İçeriği
- `/docs` README_tr.md ve ürün fotoğrafları
- `/examples` .ino uzantılı örnek uygulamalar
- `/src` kütüphane için .cpp ve .h uzantılı dosyalar
- `keywords.txt` Arduino IDE'de vurgulanacak anahtar kelimeler
- `library.properties` Arduino yöneticisi için genel kütüphane özellikleri

## Sürüm Geçmişi
1.0.0 - ilk sürüm

## :rocket:Donanım Bağlantıları
- Deneyap Çift Kanallı Motor Sürücü TC78H660FTG ile kullanılan geliştirme kartı I2C kablosu ile bağlanabilir
- veya jumper kablolar ile ile 3V3, GND, SDA ve SCL bağlantıları yapılabilir. 

|Çift Kanallı Motor Sürücü| Fonksiyon| Kart pinleri |
| :---     | :---   |   :---  |
| 3.3V     | Güç    | 3.3V    |
| GND      | Toprak |GND      |
| SDA      | I2C Data  | SDA pini |
| SCL      | I2C Clock | SCL pini|
|SWIM | Debug | bağlantı yok |
|RES  | Debug | bağlantı yok |
|IN1A|||
|IN1B|||
|IN2A|||
|IN2B|||
|STBY|||
|MODE|||

## :bookmark_tabs:Lisans Bilgisi 
Lisans bilgileri için [LICENSE](https://github.com/deneyapkart/deneyap-cift-kanalli-motor-surucu-arduino-library/blob/master/LICENSE) dosyasını inceleyin.
