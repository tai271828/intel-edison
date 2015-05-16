#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
const int pinTemp = A0;      // pin of temperature sensor
const int pinButton = 3;     // pin of button define here
float temperature;           // Creating temperature variable
int B=3975;                  // B value of the thermistor
float resistance;            // Creating resistance variable

void setup()
{
    lcd.begin(16, 2);
    pinMode(pinButton, INPUT);
    Serial.begin(9600);
}

void loop()
{
    lcd.noDisplay();
    delay(500);
    int val = analogRead(pinTemp);
    resistance=(float)(1023-val)*10000/val;
    temperature=1/(log(resistance/10000)/B+1/298.15)-273.15;
    lcd.setCursor(0,0);
    if(digitalRead(pinButton))
    {
    if (temperature >= 28)
    {
      lcd.setRGB(255,0,0);
    }
    else if (temperature < 28)
    {
      lcd.setRGB(0,0,255);
    }
    lcd.print(temperature);
    lcd.print("I love tai very much");
    Serial.println(temperature);
    delay(10000);
    lcd.display();

    delay(10000);
    lcd.noDisplay();
    }
    else
    {
    lcd.setRGB(0,0,0);
    }

}
