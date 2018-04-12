int sensorPin = A0;
int ledRed = 12;
int ledGreen = 13;
int buzzerPin = 11;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledRed, OUTPUT);
   pinMode(sensorPin, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(sensorPin);
  Serial.println(value);
  float hesaplananDeger = (4.0 / 390.0) * value;
  Serial.print(hesaplananDeger);
  Serial.println(" cm");
  delay(500);
  if (hesaplananDeger >= 3) {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);
    digitalWrite(buzzerPin, HIGH);

  } else {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);
    digitalWrite(buzzerPin, LOW);
  }

}
