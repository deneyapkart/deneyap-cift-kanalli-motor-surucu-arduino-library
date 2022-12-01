/*
 *   CiftKanalliDCmotorHizlanmasi örneği,
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   DC motorlar ileri yönde, dutycyle hızlarını 0'dan 100'e +10 artırmaktadır. Dutycyle hızı %80'den yüksek olursa motorların çalışması durmaktadır. 
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap Çift Kanallı Motor Sürücü için oluşturulmuştur
 *      ------>  https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-module-deneyap-dual-channel-motor-driver-m  <------
 *      ------>  https://github.com/deneyapkart/deneyap-cift-kanalli-motor-surucu-arduino-library  <------ 
*/
#include <Deneyap_CiftKanalliMotorSurucu.h>         // Deneyap Çift Kanallı Motor Sürücü kütüphanesi eklenmesi

DualMotorDriver MotorSurucu;                        // DualMotorDriver için class tanımlanması

void setup() {
  Serial.begin(115200);                             // Seri haberleşme başlatılması
  MotorSurucu.begin(0x16);                          // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması, varsayılan: begin(0x16,500), frekans:500Hz
}

void loop() {       
  MotorSurucu.StandBy(ENABLE);                      // DC motorların çalışmasının aktif edilmesi
  for(int i= 0; i<=100; i=i+10){                    // DC motorlar ileri yönde, dutycyle hızlarını 0'dan 100'e +10 artırılması
    MotorSurucu.Motor1Drive(i,1);
    MotorSurucu.Motor2Drive(i,1);
    if(i>80){                                        // dutycyle hızı %80'den büyük olursa
      MotorSurucu.StandBy(DISABLE);                  // DC motorların çalışmasının pasif edilmesi
      Serial.println("DC motor dutycyle hızları %80'den yüksek !!!");
      Serial.println("Motorlar durduruldu.");
    }
    delay(3000);                                     // 3 saniye bekleme süresi
  }
}