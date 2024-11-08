#include <LiquidCrystal_I2C.h>

#define Sensor A1 
#define LED_PIN 13  

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(LED_PIN, OUTPUT);
  lcd.setCursor(0, 0);
  lcd.print("Iniciando...");
  delay(2000);
  lcd.clear();
}

void loop() {
  int adc = analogRead(Sensor);
  float tempC = (adc * (5.0 / 1023.0)) * 100.0;
  float tempF = (tempC * 9.0 / 5.0) + 32.0;

  Serial.print("TempC: ");
  Serial.print(tempC);
  Serial.print(" TempF: ");
  Serial.println(tempF);

  lcd.setCursor(0, 0);
  lcd.print("Temp C: ");
  lcd.print(tempC, 1);

  lcd.setCursor(0, 1);
  lcd.print("Temp F: ");
  lcd.print(tempF, 1);

  if (tempC > 0) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(1000);
}