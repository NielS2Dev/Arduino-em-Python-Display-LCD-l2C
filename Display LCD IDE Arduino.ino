#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String message = Serial.readStringUntil('\n');
    lcd.clear();
    displayMessage(message);
  }
}

void displayMessage(String message) {
  lcd.setCursor(0, 0);
  if (message.length() > 16) {
    lcd.print(message.substring(0, 16));
    lcd.setCursor(0, 1);
    lcd.print(message.substring(16));
  } else {
    lcd.print(message);
  }
}
