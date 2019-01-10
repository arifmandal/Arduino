//RFID Kullanimi ve Uygulamasi
//Created by Arif Mandal

#include <MFRC522.h>//Kutuphanelerimizi ekledik
#include <SPI.h>
#include <Servo.h>

int RST_PIN = 9;//Haberlesme pinlerini tanimladik.
int SS_PIN = 10;//Haberlesme pinlerini tanimladik.
int servoPin = 7;//servonun bagli oldugu pin
int redPin = 3;//kirmizi ledin bagli oldugu pin
int greenPin = 2;//yesil ledin bagli oldugu pin

Servo servo;// servo objemizi olusturduk
MFRC522 rfid(SS_PIN, RST_PIN);// rfid objemizi olusturduk.

byte id[4] = {0, 0, 0, 0};//kart idmizi belirledigimiz array


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//serial monitoru baslattik.
  servo.attach(servoPin);//servonun pinini tanimladik
  servo.write(0);//servo 0 derece olarak baslattik.
  SPI.begin();//haberlesmeyi baslattik
  rfid.PCD_Init();//rfid baslattik
  pinMode(redPin, OUTPUT);//led pinlerimizi cikis pini yaptik
  pinMode(greenPin, OUTPUT);



}

void loop() {
  // put your main code here, to run repeatedly:
  if (!rfid.PICC_IsNewCardPresent()) {//eger yeni kart degilse basa donecek
    return;

  }
  if (!rfid.PICC_ReadCardSerial()) {//okumayi bitirdiyse basa donecek
    return;


  }
  if (rfid.uid.uidByte[0] == id[0] &&// kartimizi bu kisimda kontrol ettik.
      rfid.uid.uidByte[1] == id[1] &&
      rfid.uid.uidByte[2] == id[2] &&
      rfid.uid.uidByte[3] == id[3]) {
    Serial.println("Kapi Acildi.Geciniz...");// dogtu ise yesil led yaniyor servo 180 derece donuyor
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    IdYaz();// id foksiyonu ile idmizi yazdiriyoruz.
    servo.write(180);
    delay(3000);
    servo.write(0);
    delay(1000);




  } else {//yanlis ise kirmizi led yaniyor.
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, HIGH);
    Serial.println("Erisim Engellendi. Lutfen Farkli Bir Kart Deneyiniz...");
    IdYaz();

  }

  rfid.PICC_HaltA();//rfid mizi kapatiyoruz.
}

void IdYaz() {//bu foksiyonumuzda kart numaramizi for dongusu ile yazdiriyoruz.
  Serial.print("ID Numarasi: ");

  for (int sayac = 0; sayac < 4; sayac++) {
    Serial.print(rfid.uid.uidByte[sayac]);
    Serial.print(" ");

  }
  Serial.println("");

}

//thank you...
