/* 
 *  ADVENTURE GAME ARDUINO
 *  Creator : Thomas Cibils
 *  Last update : 05.02.2019
 *  FastLED tuto : https://github.com/FastLED/FastLED/wiki/Basic-usage - used for WS2812B 5050 RGB LED Strip 5M 150 300 Leds 144 60LED/M Individual Addressable 5V
 *  */

#include <TimerOne.h>
#include "FastLED.h"
#include <avr/pgmspace.h>

// LED MATRIX CODE
#define displayNumberOfRows 10                          // Number of rows
#define displayNumberOfColumns 6                       // Number of coumns
#define NUM_LEDS displayNumberOfRows * displayNumberOfColumns // Number of LEDs

CRGB leds[NUM_LEDS];                                          // Defining leds table for FastLed
#define DATA_PIN 6                                            // Output pin for FastLed

// LED Matrix
// top column is from 0 to 7, bottom one from 56 to 63 (for a 8x8 matrix)
byte LEDMatrix[displayNumberOfRows][displayNumberOfColumns];

#define mapNumberOfRows 200
#define mapNumberOfColumns 120

// With PROGMEM, 200 x 120 is feasible, but not 200 x 200
const byte PROGMEM gameMap[mapNumberOfRows][mapNumberOfColumns]; /*TBD = {
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 3, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};*/

// Original colours for leds.
const byte Black = 0;
const byte White = 1;
const byte Blue = 2;
const byte Red = 3;
const byte Green = 4;
const byte Purple = 5;

// Define colours of the various game elements
const byte Adventurer = Blue;
const byte Wall = White;
const byte Zombie = Red;


// Pin used from the arduino
#define leftButton A5        // Input pin for button Left
#define upButton A4          // Input pin for button Up
#define rightButton A3       // Input pin for button Right
#define downButton A2        // Input pin for button Down
#define aButton A0           // Input pin for button A
#define bButton A1           // Input pin for button B


struct pointOnMatrix {
  int lineCoordinate;
  int columnCoordinate;
};

pointOnMatrix adventurerPosition = {4, 4};

unsigned long lastMillis = 0;
unsigned const int growthSpeed = 1500;  // In miliseconds, every how much will the menace grow

unsigned int leftButtonValue = LOW;
unsigned int rightButtonValue = LOW;
unsigned int upButtonValue = LOW;
unsigned int downButtonValue = LOW;

unsigned int lastLeftButtonValue = LOW;
unsigned int lastRightButtonValue = LOW;
unsigned int lastUpButtonValue = LOW;
unsigned int lastDownButtonValue = LOW;


void setup() {

  Serial.begin(9600);

  // Set matrix pins to output
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

  // Set button pins to input
  pinMode(leftButton, INPUT);
  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(aButton, INPUT);
  pinMode(bButton, INPUT);
}

void loop() {

    // ----------------------------------------------------------
    // Checking if a button has been pushed, reacting accordingly
    // ----------------------------------------------------------
    
    leftButtonValue = analogRead(leftButton);
    if (leftButtonValue < 200 && lastLeftButtonValue > 800) {
      // If the button 1 has been pressed, we go left
      moveAdventurerLeft();
    }
    lastLeftButtonValue = leftButtonValue; // And we update what we read just after

    upButtonValue = analogRead(upButton);
    if (upButtonValue < 200 && lastUpButtonValue > 800) { 
     // If the button 2 has been pressed, we go right
        moveAdventurerUp();
    }
    lastUpButtonValue = upButtonValue; // And we update what we read just after

    rightButtonValue = analogRead(rightButton);
    if (rightButtonValue < 200 && lastRightButtonValue > 800) { 
     // If the button 2 has been pressed, we go right
        moveAdventurerRight();
    }
    lastRightButtonValue = rightButtonValue; // And we update what we read just after

    downButtonValue = analogRead(downButton);
    if (downButtonValue < 200 && lastDownButtonValue > 800) { 
     // If the button 2 has been pressed, we go right
        moveAdventurerDown();
    }
    lastDownButtonValue = downButtonValue; // And we update what we read just after


  // Lets the menace grow, but not too fast
  if(millis() - lastMillis > growthSpeed) {
//     growingMenace();
    lastMillis = millis();
  }
  
  // Center map and display result
  centerMap();
  outputDisplay();
  delay(1);
}


// We end the game with a curtain of light
void endGame() {

  // Serial.print("\n GAME OVER \n");
  delay(1000);
  clearLEDMatrix();
  // We light up the rows one by one, with .2 sec of delay between each
  for (byte i = 0; i < displayNumberOfRows; i++) {
    for (byte j = 0; j < displayNumberOfColumns; j++) {
      LEDMatrix[i][j] = Red;
    }
      outputDisplay();
    
    delay(500);
  }
  // It stays on for 4 seconds
  delay(3500);

}
