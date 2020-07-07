/**
 * Write Hello LCD via 4 wires
 */
#include <LiquidCrystal.h>

#define RS 4
#define E 5
#define DB4 12
#define DB5 13
#define DB6 14
#define DB7 15

LiquidCrystal lcd(RS, E, DB4, DB5, DB6, DB7);
void printLCD();
void printLCD2();

void setup() {
  lcd.begin(16, 2);
  // put your setup code here, to run once:

}

void loop() {
  printLCD("Hello!");
  int val = analogRead(0);
  printLCD2(String(val));
  delay(300);
  lcd.clear();
}

void printLCD(String text){
  lcd.setCursor(0, 0);
  lcd.print(text);  
}

void printLCD2(String text){
  lcd.setCursor(0, 1);
  lcd.print(text);  
}
