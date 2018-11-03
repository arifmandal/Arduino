#include "Wire.h"//I2C ile haberlesmasini saglamak icin wire kutuphanemizi dahil ediyoruz.

const int MPU_ADDR=0x68; //MPU-6050'nin I2C deki adresi,eger ADO pin HIGH olursa I2C 0x69 olmalidir.
/*Accelerometer (İvme Ölçer)
-İvme ölçer üzerine düşen statik(yerçekimi) veya dinamik (aniden hızlanma veya durma) ivmeyi ölçmektedirler.
-Sensörden aldığımız değer m/s2 veya yer çekimi türünden ifade edilebilir. 
-Eğer uzayda veya herhangi bir çekim alanının kapsamında değilse sensör üzerine 1g’lik bir yerçekimi kuvveti etki etmektedir. 
-Bu kuvvet de yaklaşık olarak 9.8 m/s2 'dir. 
-Sensör sürekli olarak yer çekimi etkisi altında kaldığından eğim ölçer yani akıllı cep telefonlarında telefon dikey veya 
yatay konuma getirdiğinde telefonun ekranı hareke göre değişmektedir veya hareket algılar yani Nintendo wii gibi 
ürünlerde wii remote sallandığında oynanan oyundaki karakterlerde benzer hareketi yapar. 
-Ölçü aralığı olarak ± 1g, ± 2g, ± 4g vb. değerler ile ifade edilmektedir ve bir, iki ve üç eksende 
ölçüm yapabilen türevleri vardır.*/


int16_t ivme_x, ivme_y,ivme_z;

/*Gyroscope
- Tekerleğin etrafındaki çembere dik açıyla bağlanmış başka bir çember ve bağlantılı bu çemberlere dik açıyla 
tutturulmuş başka bir çember gyroscope’u modeller. 
-Gyroscope’un önemli iki özelliği vardır. 
-İlk özelliği yatay eksende dönmekte olan bir gyroscope’a yatay eksen doğrultusunda bir kuvvet uyguladığında 
yatay eksen etrafında dönmek yerine eksen etrafında dönmeye başlar, diğer özelliği ise gyroscope’un dönmeye 
başladığı eksenin jiroskobun durduğu yüzey ne açıyla oynatılırsa oynatılsın jiroskobun dönüş ekseni sabit kalır. 
-Bu özelliğinden dolayı uyduların sürekli olarak dünyaya dönük kalması, uçaklarda ve çeşitli araçlarda yapay ufuk 
oluşturulması ve otopilot gibi uygulamalarda kullanılmaktadır. */
int16_t gyro_x, gyro_y, gyro_z;
int16_t sicaklik;// sicaklik degerini tutar.

char tmp_str[7];
char* convert_int16_to_str(int16_t i){
  sprintf(tmp_str,"%6d",i);
  return tmp_str;
  }

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);//monitoru baslatiyoruz.
  Wire.begin();//I2C haberlesmeyi baslatiyoruz.
  Wire.beginTransmission(MPU_ADDR);//Gy-521 ile iletisimi baslatiyoruz. 
  Wire.write(0x6B);
  Wire.write(0);//MPU-6050 0 yaparak baslatiyoruz.
  Wire.endTransmission(true);

}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR,7*2,true);


  ivme_x = Wire.read()<<8 | Wire.read(); 
  ivme_y = Wire.read()<<8 | Wire.read(); 
  ivme_z = Wire.read()<<8 | Wire.read();
  sicaklik = Wire.read()<<8 | Wire.read();
  gyro_x = Wire.read()<<8 | Wire.read();
  gyro_y = Wire.read()<<8 | Wire.read(); 
  gyro_z = Wire.read()<<8 | Wire.read();


  Serial.print("iX ="); 
  Serial.print(convert_int16_to_str(ivme_x));
  Serial.print(" &&iY="); 
  Serial.print(convert_int16_to_str(ivme_y));
  Serial.print(" &&iZ="); 
  Serial.print(convert_int16_to_str(ivme_z));
  Serial.print(" &&gX="); 
  Serial.print(convert_int16_to_str(gyro_x));
  Serial.print(" &&gY="); 
  Serial.print(convert_int16_to_str(gyro_y));
  Serial.print(" &&gZ="); 
  Serial.print(convert_int16_to_str(gyro_z));
  Serial.print(" &&sicaklik="); 
  Serial.println(sicaklik/340.00+36.53);
  Serial.println("***************************************************************************************************");
  
  
  delay(2000);

}
