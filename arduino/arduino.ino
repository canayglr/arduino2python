#define trigPin 9  // Trig pini Arduino'nun pin 9'una bağlı
#define echoPin 10 // Echo pini Arduino'nun pin 10'una bağlı

void setup() {
  Serial.begin(9600); // Seri port hızını 9600 baud olarak ayarla
  pinMode(trigPin, OUTPUT); // Trig pinini çıkış olarak ayarla
  pinMode(echoPin, INPUT);  // Echo pinini giriş olarak ayarla
}

void loop() {
  long sure;  // Sinyalin geri dönme süresi
  int mesafe; // Hesaplanan mesafe

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  sure = pulseIn(echoPin, HIGH);
  mesafe = sure * 0.034 / 2; // Mesafeyi santimetre cinsinden hesapla

  Serial.println(mesafe); // Mesafeyi seri port üzerinden gönder
  delay(1000); // 1 saniye bekle
}
