// Добавляем необходимые библиотеки
#include <Wire.h>               //стандартная библиотека Arduino IDE
#include <LiquidCrystal_I2C.h>  //библиотека для дисплея с работой по I2C
#include <dht11.h>              //библиотека датчика DHT11
dht11 DHT;          // Объявление переменной класса dht11
#define DHT11PIN 4  // пин для сигнала поступающего с датчика

byte degree[8] = // кодируем символ градуса (битовая маска)
{
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
};

LiquidCrystal_I2C lcd(0x27, 16, 2); // Задаем адрес и размерность дисплея

void setup()
{
  lcd.init();                 // Инициализация lcd   
  lcd.backlight();            // Включаем подсветку
  lcd.createChar(1, degree);  // Создаем символ под номером 1
}
void loop()
{ // Выводим показания влажности и температуры
  int chk = DHT.read(DHT11PIN);
  lcd.setCursor(0, 0);            // Устанавливаем курсор в начало 1 строки
  lcd.print("Humidity:     %");   // Выводим текст Влажности
  lcd.setCursor(11, 0);
  lcd.print(DHT.humidity);
  lcd.setCursor(0, 1);            // Устанавливаем курсор в начало 2 строки
  lcd.print("Temp:         \1C"); // Выводим текст температуры и значок градуса (1 - значёк, С - символ цельсия)
  lcd.setCursor(11, 1);
  lcd.print(DHT.temperature);
  delay(300000);                  //опрос раз в 5 минут
}
