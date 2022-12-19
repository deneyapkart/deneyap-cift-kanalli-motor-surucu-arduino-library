/*   
 *    StepMotorTamTurSurme örneği,
 *    Bu örnekte temel konfigürasyon ayarları yapılmaktadır. 
 *    Step motor tam tur atmaktadır. Step motor birer adım ilerlemekte ve adım sayısını seri port ekranına yazdırmaktadır. 
 *
 *    28BYJ-48 step motoruna göre yazılmıştır. Farklı bir step motor kullanırsanız gerekli değişiklikleri gerçekleştirin.
 *    STEP MOTOR MAVİ     -> B0+ (Terminal(Sağ Üst) çıkışı)
 *    STEP MOTOR PEMBE    -> A0- (Terminal(Sağ Alt) çıkışı)
 *    STEP MOTOR SARI     -> B0- (Terminal(Sağ Üst) çıkışı)
 *    STEP MOTOR TURUNCU  -> A0+ (Terminal(Sağ Alt) çıkışı)
 *
 *    Bu örnek Deneyap Çift Kanallı Motor Sürücü için oluşturulmuştur
 *      ------>  https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-module-deneyap-dual-channel-motor-driver-m  <------
 *      ------>  https://github.com/deneyapkart/deneyap-cift-kanalli-motor-surucu-arduino-library  <------ 
*/
#include <Deneyap_CiftKanalliMotorSurucu.h>       // Deneyap Çift Kanallı Motor Sürücü kütüphanesi eklenmesi

const int stepsPerRevolution = 4076;              // Tam tur adım sayısı, kullandığınız step motora göre tur sayısı değişiklik gösterebilir 

Stepper myStepper(stepsPerRevolution);            // Stepper için class tanımlanması

int adimSayisi= 0;

void setup() {
  Serial.begin(115200);                           // Seri haberleşme başlatılması
  if (!myStepper.begin(0x16)) {                   // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması, varsayılan: begin(0x16,500), frekans:500Hz
      delay(3000);
      Serial.println("I2C bağlantısı başarısız"); // I2C bağlantısı başarısız olursa seri port ekranına yazdırılması
      while(1);
  } 
  myStepper.setSpeed(60);                         // Step motor hızının belirlenmesi
}

void loop() {
  myStepper.step(1);                              // Step motorun 1 adım ilerlemesi
  Serial.print("adım sayısı:");
  Serial.println(adimSayisi);                     // Adım sayısının seri port ekranına yazdırılması
  adimSayisi++;
  delay(10);
  if(stepsPerRevolution == adimSayisi) {          // Tam tur atılırsa
    Serial.println("Tam tur atıldı");             // "Tam tur atıldı" seri port ekranına yazdırılması
    delay(3000);                                  // 3 saniye bekleme süresi
    adimSayisi=0;                                 // Adım sayısının sıfırlanması
  }
}