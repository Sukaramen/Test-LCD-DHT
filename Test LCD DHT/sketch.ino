// Library yang digunakan
#include "LiquidCrystal_I2C.h"
#include "DHT.h"

// Mendefinisikan DHT22
#define DHTPIN 2
#define DHTTYPE DHT22

// Mendefinisikan LCD 20x4
#define I2C_ADDR    0x27
#define LCD_COLUMNS 20
#define LCD_LINES   4

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();
}

void loop() {
  // Pembacaan Sensor DHT dengan Tipe Data FLOAT
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // Dioutput Melalui LCD 20x4
  lcd.setCursor(1,0);
  lcd.print("Test Reading DHT22");
  lcd.setCursor(3,1);
  lcd.print("Temp = ");
  lcd.print(temp);
  lcd.print("*C");
  lcd.setCursor(4,2);
  lcd.print("Hum = ");
  lcd.print(hum);
  lcd.print("%");
  lcd.setCursor(0,3);
  lcd.print("github.com/Sukaramen");
}
