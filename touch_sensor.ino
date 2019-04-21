int sensor = 8;
int sensorValue = 0;
int ledGreen = 13;
int ledBlue = 12;
int ledRed = 11;
int count = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledRed, OUTPUT);
  Serial.println("Started...");

}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = digitalRead(sensor);
  //Serial.println(sensorValue);
  //Serial.println(count);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledBlue, LOW);
  digitalWrite(ledGreen, LOW);

  if (sensorValue == 1) {
    count++;

    if (count % 3 == 1) {
      digitalWrite(ledRed, HIGH);


    } else if (count % 3 == 2) {
      digitalWrite(ledRed, HIGH);
      digitalWrite(ledBlue, HIGH);
    } else if (count % 3 == 0) {
      digitalWrite(ledRed, HIGH);
      digitalWrite(ledBlue, HIGH);
      digitalWrite(ledGreen, HIGH);


    }




  }
  delay(250);

}
