//Piezo Sensor kullanimi
//Created by Arif Mandal

int sensorPin = A0;// sensor pini
int ledPin = 13;//led pini
int sensorDeger = 0;//sensorden gelen degerler


void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT);//sensor pini giris led ise cikis olarak atadik
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  sensorDeger = analogRead(sensorPin);//sensoru okuduk ve sensorDeger degiskenimize atadik.
  if (sensorDeger > 100) {//sensor deger 100 den buyukse yanacak kucukse sonecek.
    digitalWrite(ledPin, HIGH);


  } else {
    digitalWrite(ledPin, LOW);

  }


//Thank you...


}
