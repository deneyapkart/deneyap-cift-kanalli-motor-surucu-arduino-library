/*
 *   Çift Kanallı Motor sürme örneği,
 *
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   ....
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap TASLAK için oluşturulmuştur
 *      ------>  www.....com  <------ //docs
 *      ------>  https://github.com/deneyapkart/deneyap-cift-kanalli-motor-surucu-arduino-library  <------ 
 *
*/

#include <Deneyap_CiftKanalliMotorSurucu.h> // Deneyap_CiftKanalliMotorSurucu kutuphanesi eklendi

DualMotorDriver MotorSurucu;

void setup(){

  Serial.begin(115200); // Seri monitor baslatildi
  MotorSurucu.begin(0x16); // begin(slaveAddress) fonksiyonu ile cihazlarin haberlesmesi baslatildi  
}

void loop() {
   
  int rawValue = analogRead(A0); // A0 pininden duty cycle degeri okundu
  int dutyCycle = (rawValue / 40.95); // Duty cycle degeri 0-100 arasına olceklendirildi 
  Serial.print("%");
  Serial.println(dutyCycle); // Seri monitore duty cycle degeri yazdirildi                                   

  /* Motor1Drive(dutyCycleDegeri, yonBilgisi)
     Motor2Drive(dutyCycleDegeri, yonBilgisi)
     DUTY CYCLE   -------> %0-100
     ILERI        -------> 1
     GERI         -------> 0                      */  
  MotorSurucu.Motor1Drive(dutyCycle,1); // Birinci motor calistirildi
  delay(50); // 50ms bekleme suresi
  
  MotorSurucu.Motor2Drive(dutyCycle,1); // Ikinci motor calistirildi
  delay(50); // 50ms bekleme suresi
}
