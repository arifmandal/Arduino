#include<IRremote.h>
#include<Servo.h>

const int RECV_PIN = 11;
const int SERVO_PIN = 9;
int pos = 90;

unsigned long sonKod;

IRrecv irrecv(RECV_PIN);
decode_results kod;

Servo servo;
void setup() {
  // put your setup code here, to run once:
  irrecv.enableIRIn();
  servo.attach(SERVO_PIN);
  servo.write(pos);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&kod)) {
    if (kod.value == 0xFFA25D) {
      kod.value = sonKod;
    }
    if (kod.value == 0xFF30CF) {
      sonKod = kod.value;
      pos += 25;
      if (pos > 180) {
        pos = 180;
      }
      servo.write(pos);
    }
    
    if (kod.value == 0xFF6897)
    {
      sonKod = kod.value;
      pos -= 25;
      if (pos < 0) {
        pos = 0;
      }
      servo.write(pos);
    }
    
    if (kod.value == 0xFFE21D)
    {

      sonKod = kod.value;
      pos = 90;
      servo.write(pos);
    }
    delay(30);  
    irrecv.resume(); 


  }

}
