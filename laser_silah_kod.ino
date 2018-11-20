//laser silahi yapimi
//created by Arif Mandal

#include <Servo.h>//kutuphaneyi dahil ettik

Servo xServo;//servo objelerimizi olusturduk
Servo yServo;

int pos=0;//servolarin ilk konumu
int xServoPin=9;// servo pinlerimizi atadik
int yServoPin=8;

int xJoyPin=A0;//Joystick pinlerimizi atadik
int yJoyPin=A1;
int xPos=0;//joystick degerimizi tutacak deger
int yPos=0;
int buttonPin=7;//joystick button pini
int buttonPress=0;

int lazerPin=6;//ve diger pinlerimizi atadik
int redPin=13;
int greenPin=12;
int buzzerPin=11;

void setup() {
  // put your setup code here, to run once:

  pinMode(lazerPin,OUTPUT);//BUTTON PIN HARIC BUTUN PINLER CIKIS PINI
  pinMode(buttonPin,INPUT);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);

  digitalWrite(buttonPin,HIGH);//button pinini high olarak atadik basta
  xServo.attach(xServoPin);// servolarimizi baslattik
  yServo.attach(yServoPin);

  xServo.write(pos);// 0 konumlarina getirdik
  yServo.write(pos);


  

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonPress=digitalRead(buttonPin);//button degerimizi okuduk
  if(buttonPress==LOW){//buttona basiliysa asagidaki komutlari
    digitalWrite(lazerPin,HIGH);
    digitalWrite(greenPin,LOW);
    digitalWrite(redPin,HIGH);
    digitalWrite(buzzerPin,HIGH);
    
    
    }else{//degilse else kismini yapacak
     digitalWrite(lazerPin,LOW);
    digitalWrite(greenPin,HIGH);
    digitalWrite(redPin,LOW);
    digitalWrite(buzzerPin,LOW);
      
      }
    xPos=analogRead(xJoyPin);// joystick degerimizi okuyup map ile 0-180 arasinda degerleri servomuza gonderdik
    xPos=map(xPos,0,1023,0,180);
    yPos=analogRead(yJoyPin);
    yPos=map(yPos,0,1023,0,180);

    xServo.write(xPos);
    yServo.write(yPos);
    delay(200);//200 milisaniye gecikme verdik
    

  

}//Thank you...
