int triggerPin=12;
int echoPin=13;
int led1=2;
int led2=3;
int led3=4;
int led4=5;
int buzzerPin=6;
float totalSure;
float mesafe;






void setup() {
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  pinMode(triggerPin,OUTPUT);
  pinMode(echoPin,INPUT);

}

void loop() {
  digitalWrite(triggerPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(triggerPin,LOW);
  totalSure=pulseIn(echoPin,HIGH);
  mesafe=(totalSure/2.0)/(29.1);
  Serial.println(mesafe);
  if(mesafe<=10){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    analogWrite(buzzerPin,5*mesafe);
    }

   else if(mesafe<=25&&mesafe>10){
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    analogWrite(buzzerPin,3*mesafe);
    }

    else if(mesafe<=50&&mesafe>25){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    analogWrite(buzzerPin,mesafe);
    }
    else {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,HIGH);
    analogWrite(buzzerPin,mesafe);
    }

}
