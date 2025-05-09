#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int ledPin = 6;
int buzzer = 4;
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(115200);
  lcd.init(); 
  lcd.backlight(); 
}

void loop() {
  if (Serial.available() > 0) {
    char signal = Serial.read();
    lcd.clear();
    if (signal == '1') { 
      digitalWrite(ledPin, HIGH);
      digitalWrite(buzzer, HIGH);
      lcd.setCursor(0, 0);
      lcd.print("Kamu Terdeteksi!");
      lcd.setCursor(0, 1);
      lcd.print("Mengantuk!");
    } else if (signal == '0') {
      digitalWrite(ledPin, LOW);
      digitalWrite(buzzer, LOW);
      lcd.setCursor(0, 0);
      lcd.print("Kamu Terdeteksi!");
      lcd.setCursor(0, 1);
      lcd.print("Tidak Mengantuk!");
    } else {
      lcd.setCursor(0, 0);
      lcd.print("Error");
    }
  }
}
