//Cisim Sayici Proje
//Created by Arif mandal

int irSensorPin = 8;//sensor pinimiz
int ledPin = 12;//led pinimiz
int count = 0;// cisim sayisi


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//monitoru baslattik
  pinMode(irSensorPin, INPUT);// sensor giris
  pinMode(ledPin, OUTPUT);//ledi cikis pini olarak atadik
  Serial.println("Started!!!");
  delay(50);


}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(irSensorPin == 1)) {// eger sensorun onunde engel varsa
    while (digitalRead(irSensorPin) == 1) {};// engelin gecmesi icin bekleme zamani
    count = count + 1;//cisim sayisini 1 arttiriyor.
    Serial.print("Algilanan Cisim Sayisi: ");//ve yazdiriyoruz.
    Serial.print(count);
    digitalWrite(ledPin, HIGH);//ledimiz 300 milisaniye yanacak engel varsa
    delay(300);
    digitalWrite(ledPin, LOW);// ledimizi sonduruyoruz engel gecince
    delay(200);// 200 milisaniye sistemin bekleme suresi

  } else {
    Serial.print("Algilanan Cisim Sayisi: ");//cisim gecmemisse birsey yapmayacaktir...
    delay(200);

  }
///Thank you...
}
