#include<LiquidCrystal.h>

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char data = 0;

int lamp = 8;
int tv = 9;
int fan = 10;
int ac = 11;



void setup() {

 lcd.begin(16,2);
 Serial.begin(9600);

 pinMode(lamp, OUTPUT);
 pinMode(tv, OUTPUT);
 pinMode(fan, OUTPUT);
 pinMode(ac, OUTPUT);

  lcd.setCursor(0,0);
 lcd.print("HOME AUTOMATION");
 lcd.setCursor(0,1);
 lcd.print("     SOHAIL     ");
 delay(10000);
 lcd.clear();

}

void loop() {
 
if (Serial.available()>0)
{
  data=Serial.read();
  Serial.print(data);
  Serial.print("\n");

  if (data=='a')
  {
 digitalWrite(lamp, LOW);   // LAMP will on as relay is low level trigger
 lcd.setCursor(0,0);
 lcd.print("LAMP ON   TV OFF");
 lcd.setCursor(0,1);
 lcd.print("FAN OFF   AC OFF");
  }

 else if (data=='b')
 {
 digitalWrite(lamp, HIGH);   // LAMP will off as relay is low level trigger
 lcd.setCursor(0,0);
 lcd.print("LAMP OFF  TV OFF");
 lcd.setCursor(0,1);
 lcd.print("FAN OFF   AC OFF");
 }


 if (data=='c')
 {
 digitalWrite(tv, LOW);    // TV will on as relay is low level trigger
 lcd.setCursor(0,0);
 lcd.print("LAMP OFF   TV ON");
 lcd.setCursor(0,1);
 lcd.print("FAN OFF   AC OFF");
 }

 else if (data=='d')
 {
 digitalWrite(tv, HIGH);   // TV will off as relay is low level trigger
 lcd.setCursor(0,0);
 lcd.print("LAMP OFF  TV OFF");
 lcd.setCursor(0,1);
 lcd.print("FAN OFF   AC OFF");
 }


 if (data=='e')
 {
 digitalWrite(fan, LOW);      // FAN will on as relay is low level trigger
 lcd.setCursor(0,0);
 lcd.print("LAMP OFF  TV OFF");
 lcd.setCursor(0,1);
 lcd.print("FAN ON    AC OFF");
 }

 else if (data=='f')
 {
 digitalWrite(fan, HIGH);   // FAN will off as relay is low level trigger
 lcd.setCursor(0,0);
 lcd.print("LAMP OFF  TV OFF");
 lcd.setCursor(0,1);
 lcd.print("FAN OFF   AC OFF");
 }


 if (data=='g')
 {
 digitalWrite(ac, LOW);    // AC will on as relay is low level trigger
 lcd.setCursor(0,0);
 lcd.print("LAMP OFF  TV OFF");
 lcd.setCursor(0,1);
 lcd.print("FAN OFF    AC ON");
 }

 else if (data=='h')
 {
 digitalWrite(ac, HIGH);      // AC will off as relay is low level trigger
 lcd.setCursor(0,0);
 lcd.print("LAMP OFF  TV OFF");
 lcd.setCursor(0,1);
 lcd.print("FAN OFF   AC OFF");
 }

}
}
