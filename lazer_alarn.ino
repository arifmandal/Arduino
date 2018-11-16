//laser'li alarm sistemi
//Created by Arif Mandal

int ldrPin = A0;//pinlerimizi tanimladik
int laserPin = 7;
int redPin = 8;
int greenPin = 9;
int buzzPin = 10;


void setup() {
  // put your setup code here, to run once:
  pinMode(ldrPin, OUTPUT);//butun verilerimizi output yani cikis olarak atadik
  pinMode(laserPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);//ldr'nin degerlerini gorebilmek icin monitoru baslattik


}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(laserPin, HIGH);//lazer herzamn acik konumda kalacak
  int ldrVal = analogRead(ldrPin);//degerimizi okuduk
  Serial.println(ldrVal);//dogru karar verebilmek icin degeri ekrana yazdirdik.

  if (ldrVal < 300) {//ldr degeri 300 kucukse yesilled acik kirmizi led kapali olacak
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);


  } else {//diger durumlarda yesil kapali kirmizi acik olacak
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, HIGH);
    for (int hz = 440; hz < 1000; hz++) {//for dongusu ile alarm sesini verdik.
      tone(buzzPin, hz, 50);


    }
    for (int hz = 1000; hz > 440; hz--) {
      tone(buzzPin, hz, 50);


    }
  }

//kodlar uzerinde istediginiz degisikligi yapabilirsiniz...tesekkur ediyorum...



}
