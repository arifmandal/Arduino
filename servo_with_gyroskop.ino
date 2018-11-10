#include "Wire.h"
#include <Servo.h>

Servo servoX;
Servo servoY;

const int MPU_ADDR=0x68; 
int16_t ivme_x, ivme_y;
char tmp_str[7];
char* convert_int16_to_str(int16_t i){
  sprintf(tmp_str,"%6d",i);
  return tmp_str;
  }
int xServoPin=9;
int yServoPin=8;

int xPos=0;
int yPos=0;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);//monitoru baslatiyoruz.
  Wire.begin();//I2C haberlesmeyi baslatiyoruz.
  Wire.beginTransmission(MPU_ADDR);//Gy-521 ile iletisimi baslatiyoruz. 
  Wire.write(0x6B);
  Wire.write(0);//MPU-6050 0 yaparak baslatiyoruz.
  Wire.endTransmission(true);
  servoX.attach(xServoPin);
  servoY.attach(yServoPin);
  servoX.write(xPos);
  servoY.write(yPos);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR,7*2,true);


  ivme_x = Wire.read()<<8 | Wire.read(); 
  ivme_y = Wire.read()<<8 | Wire.read(); 


  Serial.print("iX ="); 
  Serial.println(convert_int16_to_str(ivme_x));
  Serial.print("&&iY="); 
  Serial.println(convert_int16_to_str(ivme_y));

  ivme_x=map(ivme_x,-16000,16000,0,180);
  ivme_y=map(ivme_y,-16000,16000,0,180);
  servoX.write(ivme_x);
  servoY.write(ivme_y);
  

  delay(1000);
 
}
