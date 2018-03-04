int ldrPin = A0;
int ldrDeger;
int ledPin = 6;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);

}

void loop() {
  ldrDeger = analogRead(ldrPin);
  Serial.println(ldrDeger);

  if (ldrDeger > 600) {
    digitalWrite(ledPin, HIGH);

  } else {
    digitalWrite(ledPin, LOW);


  }
  delay(250);

}
