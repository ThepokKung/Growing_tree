#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define Relay 2

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(10);
  }
  Serial.println("Water the plant");
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, HIGH);
  setuplcd();
  lcd_print_1();
  delay(500);
}

void loop() {
  lcd_print_2();
  for (int i = 60; i > -1; i--) {
    delay(1000);
    Serial.println(String(i) + " ");
    lcd_print_3(i);
  }
  water();
}

void setuplcd() {
  lcd.begin();
  lcd.backlight();
}

void lcd_print_1() {
  lcd.setCursor(3, 0);
  lcd.print("Smart Farm");
}

void lcd_print_2() {
  lcd.setCursor(1, 1);
  lcd.print("Water in:");
}

void lcd_print_3(int x) {
  lcd.setCursor(12, 1);
  if ( x >= 10 ) {
    lcd.print(x);
  } else if ( x < 10 ) {
    String y = "0" + String(x);
    lcd.print(y);
  }
  lcd.setCursor(15, 1);
  lcd.print("S");
}

void delay_s(int x) {
  x = x * 1000;
  delay(x);
}

void water() {
  digitalWrite(Relay, LOW);
  delay_s(5);
  digitalWrite(Relay, HIGH);
}
