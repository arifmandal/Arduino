//seven segment display kullanimi
//Created by Arif Mandal


int e = 2;
int d = 3;
int c = 4;
int g = 5;
int f = 6;
int a = 7;
int b = 8;


void setup() {
  // put your setup code here, to run once:
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= 9; i++) {
    writeNumber(i);
    delay(1000);

  }

}

void writeNumber(int number) {
  switch (number) {
    case 0:
      digitalWrite(e, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(g, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      break;

    case 1:
      digitalWrite(e, LOW);
      digitalWrite(d, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(g, LOW);
      digitalWrite(f, LOW);
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      break;

    case 2:
      digitalWrite(e, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(g, HIGH);
      digitalWrite(f, LOW);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      break;

    case 3:
      digitalWrite(e, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(f, LOW);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      break;

    case 4:
      digitalWrite(e, LOW);
      digitalWrite(d, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);

      break;

    case 5:
      digitalWrite(e, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      break;

    case 6:
      digitalWrite(e, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);

      break;

    case 7:
      digitalWrite(e, LOW);
      digitalWrite(d, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(g, LOW);
      digitalWrite(f, LOW);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      break;
    case 8:
      digitalWrite(e, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      break;
    case 9:
      digitalWrite(e, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      break;
  }


}

//Thank you...
