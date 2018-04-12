int kirmiziLed=13;
int sariLed=12;
int yesilLed=8;
int maviLed=7;


void setup() {
  // put your setup code here, to run once:
  pinMode(kirmiziLed,OUTPUT);
  pinMode(sariLed,OUTPUT);
  pinMode(yesilLed,OUTPUT);
  pinMode(maviLed,OUTPUT);
  digitalWrite(kirmiziLed,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(kirmiziLed,HIGH);
  delay(50);
  digitalWrite(kirmiziLed,LOW);
  delay(50);
  digitalWrite(sariLed,HIGH);
  delay(50);
  digitalWrite(sariLed,LOW);
  delay(50);
  digitalWrite(yesilLed,HIGH);
  delay(50);
  digitalWrite(yesilLed,LOW);
  delay(50);
  digitalWrite(maviLed,HIGH);
  delay(50);
  digitalWrite(maviLed,LOW);
  delay(50);

}
