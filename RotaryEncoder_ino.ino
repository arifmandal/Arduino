//rotary encoder Kullanimi
//Created by Arif Mandal

#define CLOCKPIN  2//rotaryEncoder pin tanimlamalari
#define DATAPIN   3
#define SWITCHPIN 4

int sayacNegatif = 0;
int sayacPozitif = 0;
int durum = 0;
int sonDurum = 0;
int led = 9;

void setup() {
  Serial.begin(9600);
  pinMode(CLOCKPIN,  INPUT);//led pini haric diger pinler INPUT GIRIS PINI
  pinMode(DATAPIN,   INPUT);
  pinMode(SWITCHPIN, INPUT);
  pinMode(led,       OUTPUT);
  sonDurum = digitalRead(CLOCKPIN);//encoderin hangi yonde dondugunu anlamak icin clock pinimizi okuduk.


}

void loop() {
  int ledDurum = abs(sayacNegatif + sayacPozitif);
  analogWrite(led, ledDurum);//sayac degerlerimizi toplayip mutlak degerini
  //alip ledin bagli oldugu PWM pinine degeri yazdirdik.
  if (digitalRead(SWITCHPIN) == 0) {//switch pinine basildiginda sayaclar 0 oluyor.
    delay(300);
    sayacNegatif = 0;
    sayacPozitif = 0;
                   Serial.println("SayacNegatif= " + String(sayacNegatif) + "--->SayacPozitif= " + String(sayacPozitif));
    //degerlerimizi yazdirdik.
  }

  durum = digitalRead(CLOCKPIN);
  if (durum != sonDurum) {// encoder in yonune gore sayac degerlerimizi arttirdik
    if (digitalRead(DATAPIN) != durum) {
      if (sayacPozitif > 254) {//254 buyuk ise 254 olarak kalmasini sagladik.
        sayacPozitif = 254;
      }
      sayacPozitif++;

    } else {
      if (sayacNegatif < -254) {//-254 den kucukse -254 olarak kalmasini sagladik.
        sayacNegatif = -254;
      }

      sayacNegatif--;
    }

    Serial.println("SayacNegatif= " + String(sayacNegatif) + "--->SayacPozitif= " + String(sayacPozitif));
    // degerlerimizi yazdirdik





  }
  sonDurum = durum;// sondrumu durum yaparak her cevirmede yonunu dogru bulmasini sagladik.



}//Thank you...
