const int motorPinIleri = 3;
const int motorPinGeri = 4;
const int motorHiz = 2;

int redLed = 8;
int greenLed = 7;




void setup()
{
  pinMode(motorHiz, OUTPUT);
  pinMode(motorPinIleri, OUTPUT);
  pinMode(motorPinGeri, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);


}

void loop()
{
  digitalWrite(motorPinIleri, HIGH);
  digitalWrite(motorPinGeri, LOW);
  for (int i = 0; i <= 255; i++) {
    digitalWrite(motorHiz, i);
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    delay(20);
  }
  digitalWrite(motorPinIleri, LOW);
  digitalWrite(motorPinGeri, HIGH);
  for (int i = 255; i >= 0; i--) {
    digitalWrite(motorHiz, i);
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
    delay(20);
  }
  delay(20);
}
