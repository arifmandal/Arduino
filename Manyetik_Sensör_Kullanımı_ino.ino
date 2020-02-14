//Hall-effect-sensor Kullanimi
//Created by Arif Mandal

int hall_sensor=2;
int hall_sensor_value=0;
int led=9;
int buzzer=6;


void setup() {
  Serial.begin(9600);//degerleri gormek icin monitoru baslattik.
  pinMode(hall_sensor,INPUT);
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.println("Started...");
  delay(50);

}

void loop() {
  hall_sensor_value=digitalRead(hall_sensor);
  Serial.println("Sensor Deger: "+ String(hall_sensor_value));//Optional part...sensor 
  //degerini almak icin kullanildi.
  delay(200);

  if(hall_sensor_value==0){
    for(int i=0; i<=255;i++){//led ve buzzer degerleri PWM pinlerine 
      //bagli oldugu icin parlakligi ve sesi giderek artti. Farkli bir uygulamada yapilabilirdi.
      analogWrite(led,i);
      analogWrite(buzzer,i);
      delay(20);
      
      
      }
    
    
    }else{
      digitalWrite(led,LOW);
      digitalWrite(buzzer,LOW);
      
      }

}//thank you...
