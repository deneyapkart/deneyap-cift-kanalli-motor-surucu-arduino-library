/*   
 *    CiftKanalliDCmotorSurmeNoI2C örneği,
 *    Bu örnekte temel konfigürasyon ayarları yapılmaktadır. 
 *    A kanalına bağlı DC motor 250 dutycyle hızında dönmektedir. B kanalına bağlı DC motor 150 dutycyle hızında dönmektedir.
 *    
 *    >>>Deneyap Motor Sürücü STNBY pini 3.3v bağlanmalıdır<<<<
 *
 *    Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır
 *    Bu örnek I2C haberleşme protokolü kullanılmadan yazılmıştır
 *      ------>  https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-module-deneyap-dual-channel-motor-driver-m  <------
 *      ------>  https://github.com/deneyapkart/deneyap-cift-kanalli-motor-surucu-arduino-library  <------ 
*/
void setup() {
  Serial.begin(115200);   // Seri haberleşme başlatılması
  pinMode(D0,OUTPUT);     // Deneyap Motor Sürücünün IN1A pinine bağlanmalı
  pinMode(D1,OUTPUT);     // Deneyap Motor Sürücünün IN1B pinine bağlanmalı
  pinMode(D4,OUTPUT);     // Deneyap Motor Sürücünün IN2A pinine bağlanmalı
  pinMode(D5,OUTPUT);     // Deneyap Motor Sürücünün IN2B pinine bağlanmalı
}

void loop() {
  analogWrite(D1, 250);   // 250 dutycyle hızı ile hareketetmesi. 0-255 dutycyle aralığında motor hızı belirlenir.
  digitalWrite(D0, HIGH); // A kanalına bağlı motor

  analogWrite(D5, 150);   // 150 dutycyle hızı ile hareketetmesi. 0-255 dutycyle aralığında motor hızı belirlenir.
  digitalWrite(D4, HIGH); // B kanalına bağlı motor
}
