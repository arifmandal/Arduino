/*
 * Tilt switch kullanimi
 * Created by Arif Mandal
 */
#define SENSOR_PIN 2// sensor pinimizi tanimladik ve diger pinlerimizi
#define LED_PIN 13
#define BUZZER_PIN 4


void setup() {
  // put your setup code here, to run once:
  pinMode(SENSOR_PIN,INPUT_PULLUP);//devrede sensore direnc baglamak yerine pull up direnci kullandik
  pinMode(LED_PIN,OUTPUT);// diger pinlerimizi cikis pini yaptik
  pinMode(BUZZER_PIN,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(SENSOR_PIN)==LOW){// sensor 0 yani low okuyorsa ledi yak ve buzeri ac dedik
    digitalWrite(LED_PIN,HIGH);
    digitalWrite(BUZZER_PIN,HIGH);
    }else{// diger durumda led ve buzer kapali
      digitalWrite(LED_PIN,LOW);
      digitalWrite(BUZZER_PIN,LOW);
      }
//thank you....
}
