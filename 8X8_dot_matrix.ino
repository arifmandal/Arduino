#include "LedControlMS.h"

// VCC---->5 VOLT
//GND----->GND 
// pin 4 --------> DataIn--->DIN
// pin 3---------> CLOCK--->CLK
//pin 2----------> CHIPSELECT--->CS

#define BOARD_SAYISI 1 // KULLANILAN BOARD SAYISI

LedControl led=LedControl(4,3,2,BOARD_SAYISI);//LED KONTROL KUTUPHANESINDEN OBJE OLUSTURUP PINLERI ATADIK.


void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<BOARD_SAYISI; i++){// KULLANILAN BOARD SAYISININ OZELLIKLERINI ATADIK.
    led.shutdown(i,false);//SUREKLI CALISMASINI SAGLIYOR
    led.setIntensity(i,10);//PARLAKLIGI DEGISTIRIYOR
    delay(200);
    }

}

void loop() {
  // put your main code here, to run repeatedly:
    led.writeString(0,"ARDUINO"); //YAZDIRMAK ISTEDIGIMIZ CUMLEYI YAZIYORUZ
    led.clearAll();// HER HARFIN YANMASINDAN SONRA BOARD TEMIZLENECEK 
    delay(1000);// BASLANGICTA 1 SN DURACAK
}
