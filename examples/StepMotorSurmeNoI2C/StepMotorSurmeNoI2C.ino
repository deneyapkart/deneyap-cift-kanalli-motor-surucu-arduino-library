/*   
 *    StepMotorSurmeNoI2C örneği,
 *    Bu örnekte temel konfigürasyon ayarları yapılmaktadır. 
 *    Step motor saat yöne tersinde dönmektedir. 
 *
 *    28BYJ-48 step motoruna göre yazılmıştır. Farklı bir step motor kullanırsanız gerekli değişiklikleri gerçekleştirin.
 *    STEP MOTOR MAVİ     -> B0+ (Terminal(Sağ Üst) çıkışı)
 *    STEP MOTOR PEMBE    -> A0- (Terminal(Sağ Alt) çıkışı)
 *    STEP MOTOR SARI     -> B0- (Terminal(Sağ Üst) çıkışı)
 *    STEP MOTOR TURUNCU  -> A0+ (Terminal(Sağ Alt) çıkışı)
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
  //saatYonu(5);          // Step motorun saat yönünde döndürülmesi, her bir adım arasında 5 milisaniye beklemesi
  saatYonuTersi(5);       // Step motorun saat yönünün tersine döndürülmesi, her bir adım arasında 5 milisaniye beklemesi
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