/*PIR sensoru kullanimi:
   THANK YOU...
   Created by Arif MANDAL
*/
const int pirPin = 5;
const int ledPin = 2;
const int buzzerPin = 3;
int deger = 0;


void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin,OUTPUT);


}

void loop() {
  deger = digitalRead(pirPin);
  Serial.println(deger);
  if (deger == HIGH) {
    Serial.println("LED VE BUZZER AKTIF ");
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(250);
    digitalWrite(ledPin, LOW);
    delay(250);

  }
  else {
    Serial.println("LED VE BUZZER PASIF ");
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);

  }

}
