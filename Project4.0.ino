
#include <math.h>

float temperature;

const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k
const int pinTempSensor = A2;

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

 int colorR = 0;
 int colorG = 255;
 int colorB = 0;

int lowThreshold=25;
int highThreshold=30;
void setup() 
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    
    // Print a message to the LCD.
    lcd.print("temperature = ");

    delay(100);

   
}

void loop() {
    lcd.setCursor(0, 1);
    int a = analogRead(pinTempSensor);

    float R = 1023.0/a-1.0;
    R = R0*R;

    temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15;
    lcd.println(temperature);

    if(temperature>lowThreshold&&temperature<highThreshold)
    {
        colorR=0;
        colorG=255;
        colorB=0;
        lcd.println(" Okay!    ");
    }
 else if(temperature>highThreshold)
      {
        colorR=255;
        colorG=0;
        colorB=0;
        lcd.println(" Too hot!!");
      }
    else if(temperature<lowThreshold)
      {
        colorR=0;
        colorG=0;
        colorB=255;
        lcd.println("//;Too Cold!");
      }
           lcd.setRGB(colorR, colorG, colorB);
    delay(100);
}


