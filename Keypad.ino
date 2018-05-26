#include<Keypad.h>
#include<Password.h>

const byte satir = 4;
const byte sutun = 4;
int counter=0;
Password password = Password( "0000" );
char tusTakimi[satir][sutun] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}

};
byte satirPin[satir] = {9, 8, 7, 6};
byte sutunPin[sutun] = {13, 12, 11, 10};
Keypad pad = Keypad(makeKeymap(tusTakimi), satirPin, sutunPin, satir, sutun);
void setup() {
  Serial.begin(9600);
  Serial.println("Sifrenizi giriniz... ");
  pad.addEventListener(keypadEvent);
}

void loop() {
  pad.getKey();
  
}
void keypadEvent(KeypadEvent eKey) {
  
  switch (pad.getState()) {
    case PRESSED:
    if(eKey=='*'){
        Serial.println(" Kontrol Ediliyor...");
        }else if(eKey=='#'){
          Serial.print(counter+2);
          Serial.println(". kez sifrenizi giriyorsunuz...");
          }
        
        else{
     
      Serial.print(eKey);
      
        }
      switch (eKey) {
        case '*':
          checkPassword();
          break;
        case '#':
          password.reset();
          counter++;
          break;
        default:
          password.append(eKey);
          break;
      }
  }
}
void checkPassword() {
  if (password.evaluate()) {
    Serial.println("Sifre dogru, giris yapabilirsiniz... ");
    
  } else {
    Serial.println("Sifre HATALI # tusuna basarak tekrar deneyiniz... ");
  }
}

