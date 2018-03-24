#include <OneWire.h>
#include <DallasTemperature.h>
#define DATA_PIN 2
int led1 = 13;
int led2 = 12;
OneWire oneWire(DATA_PIN);
DallasTemperature sensors(&oneWire);
void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
}
void loop(void)
{
  sensors.requestTemperatures();
  Serial.print("Oda sicakligi: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.println(" derece");
  delay(1000);
  if (sensors.getTempCByIndex(0) > 30) {
    digitalWrite(led2, LOW);
    digitalWrite(led1, HIGH);
  } else {

    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);


  }
}
