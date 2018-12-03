//seven segment display ile sayi tahmin oyunu
//Created by Arif Mandal


int e = 2;
int d = 3;
int c = 4;
int g = 5;
int f = 6;
int a = 7;
int b = 8;
int randomNumber = 0; //arduinonun tutacagi random sayi
int incButton = 9; //arttirma butonunun pin numarasi
int decButton = 10; //azaltma butonunun pin numarasi
int incDurum = 0; //9.pin durum
int decDurum = 0; //10.pin durum
int counter = 0; //sayacimiz
int redLed = 13; //kirmizi led pini
int greenLed = 12; //yesil led pini



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//monitorumuzu baslattik
  pinMode(a, OUTPUT);//display ve led pinlerimizi cikis buton pinlerimizi giris yani input yapiyoruz.
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(incButton, INPUT);
  pinMode(decButton, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  //random sayi olusturma
  randomSeed(analogRead(0));//0. pinden deger okuyarak gurultuleri temizliyoruz.
  randomNumber = random(0, 10); //0 dahil olmak uzere 10'a kadar sayi uretiyor.
  Serial.print("Random number:");
  Serial.println(randomNumber);//sayimizi gormek icin yazdiriyoruz.

  writeNumber(5);//display ilk basta sanslar esit olmasi icin 5 yazacaktir.
  counter = 5; //counter'i 5 olarak baslatiyoruz.





}

void loop() {
  // put your main code here, to run repeatedly:
  incDurum = digitalRead(incButton); //Pinlerimizin degerlerini aliyoruz.
  decDurum = digitalRead(decButton); //Pinlerimizin degerlerini aliyoruz.

  writeNumber(counter);// counterimizi display'e yazdiriyoruz.
  //arttirma butonu
  if (incDurum == HIGH) { //arttirma butonuna basilmissa;
    delay(10);//dalgalanmalar icin 10 milisaniye bekletiyoruz.
    counter++;//sayacimizi arttirip
    writeNumber(counter);// yazdiriyoruz

    if (counter > 9) { //9dan buyukse 0'a geri donmesini sagliyoruz.
      counter = 0;

    }
    while (incDurum == HIGH) { //anahtarimizin durumunu kontrol ediyoruz.
      incDurum = digitalRead(incButton);

    }
    delay(10);



  }

  //azaltma butonu
  //arttrma butonu ile ayni ozelliklere sahip sadece counter--
  if (decDurum == HIGH) {
    delay(10);
    writeNumber(counter);
    counter--;

    if (counter < 0) {
      counter = 9;

    }

    while (decDurum == HIGH) {
      decDurum = digitalRead(decButton);

    }
    delay(10);



  }

  if (counter == randomNumber) {//eger arduinonun tuttugu sayi ayniysa yesil yanacak degilse kirmizi yanacaktir
    digitalWrite(greenLed, HIGH);

    digitalWrite(redLed, LOW);


  } else {
    digitalWrite(redLed, HIGH);

    digitalWrite(greenLed, LOW);

  }


}

void writeNumber(int number) {// seven segment display sayilarinin gosterimi degisiklige yapmaya gerek yoktur.
  switch (number) {
    case 0:
      digitalWrite(e, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(g, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      break;

    case 1:
      digitalWrite(e, LOW);
      digitalWrite(d, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(g, LOW);
      digitalWrite(f, LOW);
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      break;

    case 2:
      digitalWrite(e, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(g, HIGH);
      digitalWrite(f, LOW);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      break;

    case 3:
      digitalWrite(e, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(f, LOW);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      break;

    case 4:
      digitalWrite(e, LOW);
      digitalWrite(d, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);

      break;

    case 5:
      digitalWrite(e, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      break;

    case 6:
      digitalWrite(e, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);

      break;

    case 7:
      digitalWrite(e, LOW);
      digitalWrite(d, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(g, LOW);
      digitalWrite(f, LOW);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      break;
    case 8:
      digitalWrite(e, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      break;
    case 9:
      digitalWrite(e, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      break;
  }


}

//Thank you...
