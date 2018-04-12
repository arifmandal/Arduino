int redPin = 11;
int greenPin = 10;
int bluePin = 6;
int brightness = 255;
String colorChoice;


void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  Serial.println("Please, input your color choice:(red, green,blue) ");
  while (Serial.available() == 0) {}
  colorChoice = Serial.readString();
  if (colorChoice == "red") {
    analogWrite(redPin, brightness);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  }
  else if (colorChoice == "green") {
    analogWrite(redPin, 0);
    analogWrite(greenPin, brightness);
    analogWrite(bluePin, 0);
  }

  else if (colorChoice == "blue") {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, brightness);
  } else {
    Serial.println("Invalid choice: Please choose valid choice: ");
  }






}
