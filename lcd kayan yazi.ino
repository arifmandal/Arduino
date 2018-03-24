#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);

}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  lcd.setCursor(3,0);
  for(i=0; i<17; i+=2)
{
  lcd.setCursor(i,0);
  lcd.print("Arduino ");
  delay(1000);
  lcd.setCursor(i,0);
  lcd.print("  ");

}
for(i=0; i<17; i+=2)
{
  lcd.setCursor(i,1);
  lcd.print("Dersleri ");
  delay(1000);
  lcd.setCursor(i,1);
  lcd.print("  ");

}
for(i=0; i<17; i+=2)
{
  lcd.setCursor(i,0);
  lcd.print("lcd ");
  delay(1000);
  lcd.setCursor(i,0);
  lcd.print("  ");

}
for(i=0; i<17; i+=2)
{
  lcd.setCursor(i,1);
  lcd.print("Kullanimi ");
  delay(1000);
  lcd.setCursor(i,1);
  lcd.print("  ");

}
}
