int motorPin=7;//pinlerimizi tanimladik
int ledPin=13;

void setup() {
  Serial.begin(9600);//serial monutoru baslattik
  pinMode(motorPin,OUTPUT);//cikis pinlerimizi atadik.
  pinMode(ledPin,OUTPUT);
}

void loop() {
  int potDeger=analogRead(A0);//degeri okuduk
  int yeniDeger=map(potDeger,0,1023,0,255);//map ile 0-255 arasindaki bir degere donusturduk

  Serial.println(yeniDeger);//degeri gormek icin yazdirdik
  delay(250);//gecikme payi 
  analogWrite(ledPin,potDeger);//ledimizi pot degerine gore yaktik
  analogWrite(motorPin,yeniDeger);//motoru ise yeni degerimize gore calistirdik.
}
