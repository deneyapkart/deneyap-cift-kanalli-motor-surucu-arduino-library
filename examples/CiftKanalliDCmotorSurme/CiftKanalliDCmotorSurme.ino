/*
 *   CiftKanalliDCmotorSurme örneği,
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   1.motoru %80 dutycyle hızı ile ileri yönde hareket etmektedir. 2.motoru %75 dutycyle hızı ile geri yönde hareket etmektedir.
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
  MotorSurucu.MotorDrive(MOTOR1, 80, 1);            // Birinci motor çalıştırılması. %80 dutycyle hızı ile ileri yönde hareket edilmesi
  MotorSurucu.MotorDrive(MOTOR2, 75, 0);            // İkinci motor çalıştırılması.  %75 dutycyle hızı ile geri yönde hareket edilmesi
  if(MotorSurucu.CheckMotorError()==1) Serial.println("HATA !!! Lütfen motorları kontrol edin");
}