/*
 * Traffic Lights
 * Created by Arif Mandal
 */
int ledGecikme=10000; //gecikme miktarimizi belirledik
int kirmiziLed=10;// kirmizi led pin numaramiz
int sariLed=9;// sari led pin numaramiz
int yesilLed=8;// yesil led pin numarimiz


void setup() {
  // put your setup code here, to run once:
  pinMode(kirmiziLed,OUTPUT); // ledlerimizi cikis olarak atadik
  pinMode(sariLed,OUTPUT);
  pinMode(yesilLed,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(kirmiziLed,HIGH); // kirmizi ledimizi gecikme miktari kadar yaktik
  delay(ledGecikme);

  digitalWrite(sariLed,HIGH); // sari ledimizi 20000 milisaniye yaktik
  delay(2000);

  digitalWrite(yesilLed,HIGH);//yesil ledimizi yakip digerlerini sondurduk
  digitalWrite(kirmiziLed,LOW);
  digitalWrite(sariLed,LOW);
  delay(ledGecikme);

  digitalWrite(sariLed,HIGH);// sonra sari ledimizi yakip yesili sondurduk
  digitalWrite(yesilLed,LOW);
  delay(2000);

  digitalWrite(sariLed,LOW); // en son sari ledimizide sondurduk.

  // thank you...

}
