int sensor = A0;// sensor pinimiz
int sensorValue = 0;// baslangic sensor degerimiz
int yesilLed = 7;// led pinlerimiz
int sariLed = 8;
int kirmiziLed = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);// monitor ekranimiz
  pinMode(sensor, INPUT);// sensor pini giris diger pinleri cikis olarak atadik.
  pinMode(yesilLed, OUTPUT);
  pinMode(sariLed, OUTPUT);
  pinMode(kirmiziLed, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensor);//degerimizi okuduk
  int newValue = 1020 - sensorValue;// sensor degerimizi ters cevirerek uygun hale getirdik
  float scale = newValue / 156.0;// benim sensorum 0 ile 780 arasinda degerler verdigi icin 156 ya bolerek scale ettim.
  Serial.println(scale);// kontrol amaclidir degeri gosteriyor
  delay(200);

  if (scale >= 0 && scale < 1.6) {// degerimiz 0 ile 1.6 arasinda ise yesil 1.6 ile 3.5 arsindaysa sari eger daha buyukse 
    //kirmizi yanacaktir.
    digitalWrite(yesilLed, HIGH);
    digitalWrite(sariLed, LOW);
    digitalWrite(kirmiziLed, LOW);


  } else if (scale >= 1.6 && scale < 3.5) {
    digitalWrite(yesilLed, LOW);
    digitalWrite(sariLed, HIGH);
    digitalWrite(kirmiziLed, LOW);


  } else {
    digitalWrite(yesilLed, LOW);
    digitalWrite(sariLed, LOW);
    digitalWrite(kirmiziLed, HIGH);

  }

//Thank you...

}
