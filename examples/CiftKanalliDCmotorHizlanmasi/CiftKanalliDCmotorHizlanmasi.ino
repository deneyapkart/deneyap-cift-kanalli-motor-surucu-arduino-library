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
  if (!MotorSurucu.begin(0x16)) {                   // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması, varsayılan: begin(0x16,500), frekans:500Hz
      delay(3000);
      Serial.println("I2C bağlantısı başarısız");   // I2C bağlantısı başarısız olursa seri port ekranına yazdırılması
      while(1);
  } 
}

void loop() {
  MotorSurucu.StandbyMode(ENABLE);                  // DC motorların çalışmasının aktif edilmesi
  for(int i=0; i<100; i=i+10) {                     // DC motorlar ileri yönde, dutycyle hızlarını 0'dan 100'e +10 artırılması
    Serial.println("DC motorlar hızlanıyor !!!");
    MotorSurucu.MotorDrive(MOTOR1, i, 1);
    MotorSurucu.MotorDrive(MOTOR2, i, 1);
    if(i>80) {                                       // dutycyle hızı %80'den büyük olursa
      MotorSurucu.StandbyMode(DISABLE);              // DC motorların çalışmasının pasif edilmesi
      Serial.println("DC motorların dutycyle hızları %80'den yüksek !!!");
      Serial.println("Motorlar durduruldu.");
    }
    delay(5000);                                     // 5 saniye bekleme süresi
  }
}