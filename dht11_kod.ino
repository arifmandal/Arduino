//DHT11 kullanimi
//Created by Arif Mandal

#include<dht11.h>//Kutuphaneyi videonun altindaki linkten indirebilirsiniz.
#define DHT11PIN 2// dht11 pinimiz

dht11 DHT11;// DHT kutuphanesinden obje olusturduk.

int motorPin = 8;// motor ve led pinlerimiz
int greenPin = 12;
int redPin = 13;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);// monitoru baslattik
  Serial.println("amatorEE Muhendis DHT11 Projesi");
  pinMode(motorPin, OUTPUT);// motor ve led pinlerimizi cikis pini yaptik.
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("");
  int value = DHT11.read(DHT11PIN);// dht11 sensorumuzu okuduk

  float nem = DHT11.humidity;// float olarak nem degerimizi aldik.
  float sicaklik = DHT11.temperature;//float olarak sicaklik degerimizi aldik.

  Serial.print("Nem (%): ");// bu degerleri yazdirdik
  Serial.println(nem);

  Serial.print("Sicaklik (Celcius): ");
  Serial.println(sicaklik);

  delay(1000);// rahat gorebilmek icin gecikme verdik.

  if (sicaklik >= 25.00 && nem >= 60.00) {// sicaklik 25 den buyuk ve nem 60 dan buyukse motor calisacak ve 
    //dht11 sensorunu sogutacaktir.
    digitalWrite(motorPin, HIGH);
    digitalWrite(redPin, HIGH);// kirmizi led yanacak yesil led sonuk durumda kalacaktir.
    digitalWrite(greenPin, LOW);


  } else {
    digitalWrite(motorPin, LOW);//diger durumlarda motor durgun kirmizi led sonuk kalacak yesil led yanacaktir.
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);

  }
//thank you...

}
