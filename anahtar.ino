int kirmiziLed = 13;
int sariLed = 12;
int yesilLed = 11;
int anahtar1 = 2;
int anahtar2 = 3;
int anahtar3 = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(kirmiziLed, OUTPUT);
  pinMode(sariLed, OUTPUT);
  pinMode(yesilLed, OUTPUT);
  pinMode(anahtar1, INPUT);
  pinMode(anahtar2, INPUT);
  pinMode(anahtar3, INPUT);



}

void loop() {
  // put your main code here, to run repeatedly:
  int value1 = digitalRead(anahtar1);
  int value2 = digitalRead(anahtar2);
  int value3 = digitalRead(anahtar3);
  if (value1 == 1) {
    digitalWrite(kirmiziLed, HIGH);
  } if (value2 == 1) {
    digitalWrite(kirmiziLed, HIGH);
    digitalWrite(sariLed, HIGH);

  }  if (value3 == 1) {
    digitalWrite(kirmiziLed, HIGH);
    digitalWrite(sariLed, HIGH);
    digitalWrite(yesilLed, HIGH);
  } else {
    digitalWrite(kirmiziLed, LOW);
    digitalWrite(sariLed, LOW);
    digitalWrite(yesilLed, LOW);
  }

}
