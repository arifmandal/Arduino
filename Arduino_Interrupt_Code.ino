//Arduino Interrupt Kullanimi
//Created By Arif Mandal

/*Interrup Onemli Bilgiler:
 * General Syntax:attachInterrupt(digitalPinToInterrupt(pin),ISR,Mode);
 * 1.digitalPinToInterrupt(pin): arduino nano icin pin yerine 2 veya 3. pinleri yazabilirsiniz.
 * 2.ISR(Interrupt Service Routine ): Interrupt icin yazilmis foksiyonu cagirir.
 * 3.Mode: 3 adet mode vardir
 *    a)RISING: LOW dan HIGH'a gecerken tetiklenir.
 *    b)FALLING:HIGH dan LOW'a gecerken tetiklenir.
 *    c)CHANGE:LOW dan HIGH'a gecerken ve HIGH dan LOW'a gecerken tetiklenir, yani butona bir basmada
 *    iki kez olay gerceklesir
 * *****ISR kisa olmasi ve foksiyonun icinde delay olmamasi onerilir******

*/
int ledArray[4]={8,7,6,5};//yesil,sari,kirmizi,mavi
void setup() {
  for(int i=0; i<4;i++){
    pinMode(ledArray[i],OUTPUT);
    
    }
  attachInterrupt(digitalPinToInterrupt(2),butonKesme,RISING);

}

void loop() {
  for(int i=0;i<4;i++){
    digitalWrite(ledArray[i],HIGH);
    delay(500);
    digitalWrite(ledArray[i],LOW);
    delay(500);
    
    }

}


void butonKesme(){
  for(int i=0;i<4;i++){
    digitalWrite(ledArray[i],HIGH);
    //interrupt foksiyonu oldugu icin delay koymuyoruz.
    
    }
  
  
  
  }

 //Thank you...
