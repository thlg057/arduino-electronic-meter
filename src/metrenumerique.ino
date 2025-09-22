/*!
   Arduino digital meter project
   Autor : thlg

   Based on Haljia Arduino starter kit
   http://www.haljia.com/
   Component :
   - Arduino Uno
   - Ultra sonic HC-SR04
   - 4 digits/7 segments Led display 5641BH

   Released under the MIT license
   https://opensource.org/licenses/MIT

   Date: 2017-12-27
*/

#include "Ultrasonic.h"
#include "Display4Digit7Segments.h"

int aPin = 2;  //         A
int bPin = 3;  //      ________
int cPin = 4;  //     |        |
int dPin = 5;  //   F |        |  B
int ePin = 6;  //     |    G   |
int fPin = 7;  //     |________|
int gPin = 8;  //     |        |
int GND1 = 14; //     |        |
int GND2 = 15; //   E |        |   C
int GND3 = 16; //     |________|
int GND4 = 17; //
int DTime = 4; //         D

int sensorTrigPlotId = 11;
int sensorEchoPlotId = 10;

Ultrasonic ultrasonic(sensorTrigPlotId, sensorEchoPlotId); //(Trig,Echo)
Display4Digit7Segments ledComponent(aPin, GND1); //(segA, Digit1)

const long interval = 1000;
unsigned long previousMillis = 0;
int mDistanceInCm = 0;

void setup()
{
  ledComponent.Setup();
}

void loop()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    mDistanceInCm = ultrasonic.Ranging(CM);
  }
  
  ledComponent.Display(mDistanceInCm, 3);
  delay(DTime);
}

