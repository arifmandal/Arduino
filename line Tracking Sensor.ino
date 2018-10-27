//line tracking sensor
//Created by Arif Mandal

int sensorPin = 12;
int sensorValue;
int redPin = 8;
int bluePin = 9;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = digitalRead(sensorPin);
  Serial.println(sensorValue);
  if (sensorValue == 1) {
    digitalWrite(redPin, LOW);
    digitalWrite(bluePin, HIGH);


  } else {
    digitalWrite(bluePin, LOW);
    digitalWrite(redPin, HIGH);

  }


}
//THank you...
