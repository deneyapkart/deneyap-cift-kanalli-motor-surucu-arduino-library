/*   
 *    StepMotorSurmeNoI2C örneği,
 *    Bu örnekte temel konfigürasyon ayarları yapılmaktadır. 
 *    Step motor saat yöne tersinde dönmektedir. 
 *
 *    28BYJ-48 step motoruna göre yazılmıştır. Farklı bir step motor kullanırsanız gerekli değişiklikleri gerçekleştirin.
 *    STEP MOTOR MAVİ     -> A0-
 *    STEP MOTOR PEMBE    -> B0+
 *    STEP MOTOR SARI     -> A0+
 *    STEP MOTOR TURUNCU  -> B0-
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
  pinMode(D6,OUTPUT);     // Deneyap Motor Sürücünün IN2A pinine bağlanmalı
  pinMode(D7,OUTPUT);     // Deneyap Motor Sürücünün IN2B pinine bağlanmalı
}

void loop() {
  //saatYonu(5);          // Step motorun saat yönünde döndürülmesi, her bir adım arasında 5 mili saniye beklemesi
  saatYonuTersi(5);       // Step motorun saat yönünün tersine döndürülmesi, her bir adım arasında 5 mili saniye beklemesi
}

void saatYonu(int bekleme){
  digitalWrite(D0,LOW);
  digitalWrite(D1,LOW);
  digitalWrite(D6,HIGH);
  digitalWrite(D7,HIGH);
  delay(bekleme); 

  digitalWrite(D0,LOW);
  digitalWrite(D1,LOW);
  digitalWrite(D6,HIGH);
  digitalWrite(D7,LOW);
  delay(bekleme);

  digitalWrite(D0,LOW);
  digitalWrite(D1,HIGH); 
  digitalWrite(D6,HIGH);
  digitalWrite(D7,LOW);
  delay(bekleme);

  digitalWrite(D0,LOW);
  digitalWrite(D1,HIGH);
  digitalWrite(D6,LOW);
  digitalWrite(D7,LOW);
  delay(bekleme); 

  digitalWrite(D0,HIGH);
  digitalWrite(D1,HIGH);
  digitalWrite(D6,LOW);
  digitalWrite(D7,LOW);
  delay(bekleme);

  digitalWrite(D0,HIGH);
  digitalWrite(D1,LOW);
  digitalWrite(D6,LOW);
  digitalWrite(D7,LOW);
  delay(bekleme); 

  digitalWrite(D0,HIGH);
  digitalWrite(D1,LOW); 
  digitalWrite(D6,LOW);
  digitalWrite(D7,HIGH);
  delay(bekleme);

  digitalWrite(D0,LOW);
  digitalWrite(D1,LOW);
  digitalWrite(D6,LOW);
  digitalWrite(D7,HIGH);
  delay(bekleme); 
}

void saatYonuTersi(int bekleme){
  digitalWrite(D0,LOW);
  digitalWrite(D1,LOW);
  digitalWrite(D6,LOW);
  digitalWrite(D7,HIGH);
  delay(bekleme); 

  digitalWrite(D0,HIGH);
  digitalWrite(D1,LOW); 
  digitalWrite(D6,LOW);
  digitalWrite(D7,HIGH);
  delay(bekleme);

  digitalWrite(D0,HIGH);
  digitalWrite(D1,LOW);
  digitalWrite(D6,LOW);
  digitalWrite(D7,LOW);
  delay(bekleme);

  digitalWrite(D0,HIGH);
  digitalWrite(D1,HIGH);
  digitalWrite(D6,LOW);
  digitalWrite(D7,LOW);
  delay(bekleme);

  digitalWrite(D0,LOW);
  digitalWrite(D1,HIGH);
  digitalWrite(D6,LOW);
  digitalWrite(D7,LOW);
  delay(bekleme); 

  digitalWrite(D0,LOW);
  digitalWrite(D1,HIGH); 
  digitalWrite(D6,HIGH);
  digitalWrite(D7,LOW);
  delay(bekleme);

  digitalWrite(D0,LOW);
  digitalWrite(D1,LOW);
  digitalWrite(D6,HIGH);
  digitalWrite(D7,LOW);
  delay(bekleme);

  digitalWrite(D0,LOW);
  digitalWrite(D1,LOW);
  digitalWrite(D6,HIGH);
  digitalWrite(D7,HIGH);
  delay(bekleme); 
}