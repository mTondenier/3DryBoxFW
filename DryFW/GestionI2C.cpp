#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

void displayTempHeat (int heatTemp)
{
lcd.setCursor(8,0);
lcd.print(heatTemp);
}

void displayHumi (int humi)
{
lcd.setCursor(14,0);
lcd.print(humi);
}

void displayTemp (int temp)
{
lcd.setCursor(2,0); 
lcd.print(temp);
  
}


void displayChit (int number) {
lcd.setCursor(15,1); 
lcd.print(number);
  
}


void initDisplay ()
{
lcd.init(4,5);
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("T");
lcd.write(223);
lcd.setCursor(7,0);
lcd.print("T");
lcd.write(223);
lcd.setCursor(12,0);
lcd.print("H");
lcd.write(37);
lcd.setCursor(6,0);
lcd.print("T");
lcd.write(223);

}


void displayMenu (String title, int value) {
  lcd.setCursor(0,1);
  if (value != -1) {
  lcd.print(title);
  int letter = title.length();
  lcd.setCursor(letter,1);
  
  lcd.write(58);
  lcd.print(" ");
  lcd.print(value);
  }
  else {
    lcd.print("                ");
  }
}
