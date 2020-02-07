int sensor=2;
int led=3;
int buzzer=4;
int sensorValue=0;



void setup() {
  pinMode(sensor,INPUT);
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  Serial.println("Started...");
  delay(5);

}

void loop() {
  sensorValue=digitalRead(sensor);
  Serial.println("Sensor Value="+String(sensorValue));
  delay(200);
  if(sensorValue==0){
    digitalWrite(buzzer,HIGH);
    digitalWrite(led,HIGH);
    delay(300);
    digitalWrite(led,LOW);
    
    }else{
      digitalWrite(buzzer,LOW);
      digitalWrite(led,HIGH);
      
      }

  
}
