// C++ code
//
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  pinMode(A0, INPUT); //connect the LDR in the A0 (analogic A0)
  pinMode(13, OUTPUT); //connect the LED in the 13 (digital 13)

  lcd.init();
  lcd.backlight();

}

void loop()
{
  int valor = analogRead(A0);
  lcd.setCursor(0, 0);
  lcd.print("LDR Value:");

  lcd.print(valor);



  lcd.print("           ");

  if (valor > 340) {
    lcd.setCursor(0, 1);
    lcd.print("Lights On");
    lcd.print("           ");
    digitalWrite(13, LOW);
  }
  else {
    lcd.setCursor(0, 1);
    lcd.print("Lights Off");
    lcd.print("             ");
    digitalWrite(13, HIGH);
  }
}