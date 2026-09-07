#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>



int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


#define Type DHT11
int sensePin = 4;

DHT tempSensor(sensePin, Type);

float humidity;
float tempC;

int setTime = 500;


void pad(int col, int row, String text){
  while(text.length() < 16){
    text += " ";
  }
  lcd.setCursor(col, row);
  lcd.print(text);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  tempSensor.begin();

  lcd.begin(16,2);

  lcd.setCursor(0,0);
  lcd.print("Humidity: ");

  lcd.setCursor(0,1);
  lcd.print("Temp: ");


}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = tempSensor.readHumidity();
  tempC = tempSensor.readTemperature();

  pad(10, 0, String(humidity));
  pad(7, 1, String(tempC));

 
  delay(setTime);

}
