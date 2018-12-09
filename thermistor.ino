//Thermistor kullanimi 
//Created by Arif Mandal

int thermistorPin=A1;//Thermistor pinimiz
int Vo;//voltaj degisim degerimizi
float R1=2252;
float logR2,R2,T;

float A=1.484778004e-03,B=2.348962910e-04,C=1.006037158e-07;// thermistoru dereceye cevirecek degerlerimiz

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//monitoru baslatiyoruz.

}

void loop() {
  // put your main code here, to run repeatedly:
  Vo=analogRead(thermistorPin);// degerimizi okuyup donusumleri yapiyoruz.
  Vo=1023-Vo;
  R2=R1*(1023.0/(float)Vo-1.0);
  logR2=log(R2);
  T=(1.0/(A+B*logR2+C*logR2*logR2*logR2));
  T=T-273.15;//kelvinden dereceye donusum


  Serial.print(" TEMP= ");// ve yazdiriyoruz
  Serial.print(T);
  Serial.println(" C");
  delay(500);// 500 milisaniye gecikme veriyoruz...

  //nasil donusturuldugunu anlamak icin thermistorunun datasheetini inceleyebilirsiniz...
  //thank you...



  

}
