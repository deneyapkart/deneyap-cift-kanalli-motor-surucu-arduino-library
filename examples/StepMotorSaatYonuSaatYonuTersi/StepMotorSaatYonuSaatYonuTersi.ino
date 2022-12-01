/*   
 *    StepMotorSaatYonuSaatYonuTersi örneği,
 *    Bu örnekte temel konfigürasyon ayarları yapılmaktadır. 
 *    Step motor tam tur atmaktadır. Step motor birer adım ilerlemekte ve adım sayısını seri port ekranına yazdırmaktadır. 
 *
 *    28BYJ-48 step motoruna göre yazılmıştır. Farklı bir step motor kullanırsanız gerekli değişiklikleri gerçekleştirin.
 *    STEP MOTOR MAVİ     -> A0-
 *    STEP MOTOR PEMBE    -> B0+
 *    STEP MOTOR SARI     -> A0+
 *    STEP MOTOR TURUNCU  -> B0-
 *
 *    Bu örnek Deneyap Çift Kanallı Motor Sürücü için oluşturulmuştur
 *      ------>  https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-module-deneyap-dual-channel-motor-driver-m  <------
 *      ------>  https://github.com/deneyapkart/deneyap-cift-kanalli-motor-surucu-arduino-library  <------ 
*/
#include <Deneyap_CiftKanalliMotorSurucu.h>   // Deneyap Çift Kanallı Motor Sürücü kütüphanesi eklenmesi

const int stepsPerRevolution = 4096;          // Tam tur adım sayısı, kullandığınız step motora göre tur sayısı değişiklik gösterebilir 

Stepper myStepper(stepsPerRevolution);        // Stepper için class tanımlanması

void setup() {
  Serial.begin(115200);                       // Seri haberleşme başlatılması
  myStepper.begin(0x16);                      // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması, varsayılan: begin(0x16,500), frekans:500Hz
  myStepper.Mode(STEP);
  myStepper.setSpeed(30);                     // Step motor hızının belirlenmesi
}

void loop() {
  Serial.println("Step motor saat yönünde dönüyor...");
  myStepper.step(2048);                       // Step motorun saat yönünde yarım tur atması
  delay(1000);
  Serial.println("Step motor saat yönünün tersine dönüyor...");
  myStepper.step(-2048);                      // Step motorun saat yönü tersinde yarım tur atması
  delay(1000);
}