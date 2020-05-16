// Puts the player at the center of the display, and fills the rest of the display with the map, read from the progmem.
void centerMap() {
  for (int i = 0; i < displayNumberOfRows; i++)  {
    for (int j = 0; j < displayNumberOfColumns; j++) {
      LEDMatrix[i][j] = pgm_read_byte(&(gameMap[adventurer.lineCoordinate-displayRowAdventurerPosition+i][adventurer.columnCoordinate-displayColumnAdventurerPosition+j]));
      if(i == displayRowAdventurerPosition && j == displayColumnAdventurerPosition) {
        LEDMatrix[i][j] = adventurer.displayColour;
      } 
    }
  }
}

// Makes the whole display "LEDMatrix" equals to 0, i.e. each LED is off
void clearLEDMatrix() {
  // Just seting le LEDmatrix to Wall
  for (byte i = 0; i < displayNumberOfRows; i++)  {
    for (byte j = 0; j < displayNumberOfColumns; j++) {
      LEDMatrix[i][j] = Black;
    }
  }
}


// We update the physical display of the LED matrix, based on the LEDMatrix
void outputDisplay() {
  for(byte rowIndex = 0; rowIndex < displayNumberOfRows; rowIndex++) {
    for(byte columnIndex = 0; columnIndex < displayNumberOfColumns; columnIndex++) {
      // Useful because of the way my matrix is soldered.
      // So we'll invert one column every two compared to our digital matrix
      // If we're on an even column, we're fine, everything is straightfoward
      if(columnIndex%2 == 0) {
        
        if(LEDMatrix[rowIndex][columnIndex] == Black) {leds[(columnIndex + 1)*displayNumberOfRows - rowIndex - 1] = CRGB::Black;}
        if(LEDMatrix[rowIndex][columnIndex] == White) {leds[(columnIndex + 1)*displayNumberOfRows - rowIndex - 1] = CRGB::White;}
        if(LEDMatrix[rowIndex][columnIndex] == Green) {leds[(columnIndex + 1)*displayNumberOfRows - rowIndex - 1] = CRGB::Green;}
        if(LEDMatrix[rowIndex][columnIndex] == Blue) {leds[(columnIndex + 1)*displayNumberOfRows - rowIndex - 1] = CRGB::Blue;}
        if(LEDMatrix[rowIndex][columnIndex] == Red) {leds[(columnIndex + 1)*displayNumberOfRows - rowIndex - 1] = CRGB::Red;}
        if(LEDMatrix[rowIndex][columnIndex] == Purple) {leds[(columnIndex + 1)*displayNumberOfRows - rowIndex - 1] = CRGB::Purple;}
        if(LEDMatrix[rowIndex][columnIndex] == Pink) {leds[(columnIndex + 1)*displayNumberOfRows - rowIndex - 1] = CRGB::Pink;}
        if(LEDMatrix[rowIndex][columnIndex] == Brown) {leds[(columnIndex + 1)*displayNumberOfRows - rowIndex - 1] = CRGB::Brown;}
        if(LEDMatrix[rowIndex][columnIndex] == Orange) {leds[(columnIndex + 1)*displayNumberOfRows - rowIndex - 1] = CRGB::Orange;}
      }
      // If we're on an uneven column, we do a mathematical trick to invert it
      else if(columnIndex%2 == 1) {
        if(LEDMatrix[rowIndex][columnIndex] == Black) {leds[columnIndex*displayNumberOfRows + rowIndex] = CRGB::Black;}
        if(LEDMatrix[rowIndex][columnIndex] == White) {leds[columnIndex*displayNumberOfRows + rowIndex] = CRGB::White;}
        if(LEDMatrix[rowIndex][columnIndex] == Green) {leds[columnIndex*displayNumberOfRows + rowIndex] = CRGB::Green;}
        if(LEDMatrix[rowIndex][columnIndex] == Blue) {leds[columnIndex*displayNumberOfRows + rowIndex] = CRGB::Blue;}
        if(LEDMatrix[rowIndex][columnIndex] == Red) {leds[columnIndex*displayNumberOfRows + rowIndex] = CRGB::Red;}
        if(LEDMatrix[rowIndex][columnIndex] == Purple) {leds[columnIndex*displayNumberOfRows + rowIndex] = CRGB::Purple;}
        if(LEDMatrix[rowIndex][columnIndex] == Pink) {leds[columnIndex*displayNumberOfRows + rowIndex] = CRGB::Pink;}
        if(LEDMatrix[rowIndex][columnIndex] == Brown) {leds[columnIndex*displayNumberOfRows + rowIndex] = CRGB::Brown;}
        if(LEDMatrix[rowIndex][columnIndex] == Orange) {leds[columnIndex*displayNumberOfRows + rowIndex] = CRGB::Orange;}
      }
    }
  }
  
  // And use the dedicated library function to display the matrix physically
  FastLED.show(); 
}

// We update the digital display of the LED matrix
void digitalOutputDisplay() {
  Serial.print("\n We print digitally the current theoritical state of the LED Matrix : \n");
  for (byte i = 0; i < displayNumberOfRows; i++) {
    for (byte j = 0; j < displayNumberOfColumns; j++) {
      Serial.print(LEDMatrix[i][j]);
      if (j < displayNumberOfColumns - 1) {
        Serial.print(", ");
      }
      else {
        Serial.print("\n");
      }
    }
  }
}
