// Puts the player at the center of the display, and fills the rest of the display with the map, read from the progmem.
void centerMap() {
  // We'll plot the relevant part of the map on the display
  // Then add the player and potential other moving elements as well.

  // First we define which part of the map we'll display. We'll display a rectangle of the map, starting on top left
  byte topLeftFixingLine = 0;       // We'll plot the map starting from this line
  byte topLeftFixingColumn = 0;     // We'll plot the map starting from this column

  // First we define the start of fixing of the line. If we get near the top or bottom of the map, we want the player to move on the display
  if(adventurer.lineCoordinate < displayRowAdventurerPosition) {
    topLeftFixingLine = 0;
  }

  else if(adventurer.lineCoordinate > mapNumberOfRows - (displayNumberOfRows - displayRowAdventurerPosition)) {
    topLeftFixingLine = mapNumberOfRows - displayNumberOfRows;
  }

  // And if we're on the middle of it, the map will simply move around
  else {
    topLeftFixingLine = adventurer.lineCoordinate - displayRowAdventurerPosition;
  }

  // Same for the column fixing
  if(adventurer.columnCoordinate < displayColumnAdventurerPosition) {
    topLeftFixingColumn = 0;
  }

  else if(adventurer.columnCoordinate > mapNumberOfColumns - (displayNumberOfColumns - displayColumnAdventurerPosition)) {
    topLeftFixingColumn = mapNumberOfColumns - displayNumberOfColumns;
  }

  // And if we're on the middle of it, the map will simply move around
  else {
    topLeftFixingColumn = adventurer.columnCoordinate - displayColumnAdventurerPosition;
  }

  // ------------------
  // Now that that's defined, we plot things starting with this top left starter
  
  // We iterate on all the display
  for (int i = 0; i < displayNumberOfRows; i++)  {
    for (int j = 0; j < displayNumberOfColumns; j++) {
      // First we simply plot the map
      LEDMatrix[i][j] = pgm_read_byte(&(gameMap[topLeftFixingLine+i][topLeftFixingColumn+j]));

      // If it turns out we're at the player coordinate, we plot it. The TopLeftFixing should make sure it happens ^^
      if(adventurer.lineCoordinate == topLeftFixingLine+i && adventurer.columnCoordinate == topLeftFixingColumn+j) {
        LEDMatrix[i][j] = adventurer.displayColour;
      }

      // We also check for ennemy presence on the display. 
      // This could probably be optimized to avoid going through the whole ennemy list for all leds of the display board.
      for(byte k = 0; k < numberOfEnnemies; k++) {
        if(ennemies[k].isAlive == 1) {
          if(ennemies[k].lineCoordinate == topLeftFixingLine+i && ennemies[k].columnCoordinate == topLeftFixingColumn+j) {
             LEDMatrix[i][j] = ennemies[k].displayColour;
          }
        }
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
