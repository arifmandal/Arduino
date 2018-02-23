int led1 = 8;
int led2 = 9;
int led3 = 10;
int led4 = 11;
int data;



void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);


}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.read();

  }
  delay(100);
  if (data == '1') {
    digitalWrite(led1, HIGH);

  }
  else if (data == '2') {
    digitalWrite(led1, LOW);

  }
  else if (data == '3') {
    digitalWrite(led2, HIGH);

  }
  else if (data == '4') {
    digitalWrite(led2, LOW);

  }
  else if (data == '5') {
    digitalWrite(led3, HIGH);

  }
  else if (data == '6') {
    digitalWrite(led3, LOW);

  }
  else if (data == '7') {
    digitalWrite(led4, HIGH);

  }

  else if (data == '8') {
    digitalWrite(led4, LOW);

  }



}
