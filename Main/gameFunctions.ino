void checkIfDead() {
  // We check that the player isn't at the same spot as an ennemy
  for(byte i = 0; i < numberOfEnnemies; i++) {
    // So for all alive ennemies
    if(ennemies[i].isAlive == 1) {
      // We check if the ennemy is over the player
      if(ennemies[i].lineCoordinate == adventurer.lineCoordinate && ennemies[i].columnCoordinate == adventurer.columnCoordinate) {
        // In which case yes we're dead
        if(displayNumberOfColumns == 6 && displayNumberOfRows == 10) {
          gameOverSixTimeTen();
        }
        else {
          Serial.print("Game over, but the matrix isn't 6 by 10, so no display");
        }
      }
    }
  }
}

void gameOverSixTimeTen() {
  
  static const PROGMEM byte spriteOne[displayNumberOfRows][displayNumberOfColumns] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  clearLEDMatrix();
  for(byte i = 0; i<displayNumberOfRows; i++) {
    for(byte j = 0; j<displayNumberOfColumns; j++) {
      LEDMatrix[i][j] = pgm_read_byte(&(spriteOne[i][j]));
    }
  }
  outputDisplay();
  delay(1000);

  static const PROGMEM byte spriteTwo[displayNumberOfRows][displayNumberOfColumns] = {
    {3, 3, 3, 3, 3, 3},
    {3, 3, 3, 3, 3, 3},
    {3, 3, 0, 0, 0, 0},
    {3, 3, 0, 0, 2, 0},
    {3, 3, 0, 2, 2, 2},
    {3, 3, 0, 0, 2, 0},
    {3, 3, 0, 2, 0, 2},
    {3, 3, 0, 0, 0, 0},
    {3, 3, 3, 3, 3, 3},
    {3, 3, 3, 3, 3, 3}
  };

  clearLEDMatrix();
  for(byte i = 0; i<displayNumberOfRows; i++) {
    for(byte j = 0; j<displayNumberOfColumns; j++) {
      LEDMatrix[i][j] = pgm_read_byte(&(spriteTwo[i][j]));
    }
  }
  outputDisplay();
  delay(1500);

    static const PROGMEM byte spriteThree[displayNumberOfRows][displayNumberOfColumns] = {
    {0, 0, 0, 0, 0, 0},
    {3, 3, 3, 3, 3, 3},
    {3, 3, 3, 3, 3, 3},
    {3, 3, 0, 0, 2, 0},
    {3, 3, 0, 2, 2, 2},
    {3, 3, 0, 0, 2, 0},
    {3, 3, 0, 2, 0, 2},
    {3, 3, 3, 3, 3, 3},
    {3, 3, 3, 3, 3, 3},
    {0, 0, 0, 0, 0, 0}
  };

  clearLEDMatrix();
  for(byte i = 0; i<displayNumberOfRows; i++) {
    for(byte j = 0; j<displayNumberOfColumns; j++) {
      LEDMatrix[i][j] = pgm_read_byte(&(spriteThree[i][j]));
    }
  }
  outputDisplay();
  delay(500);

  static const PROGMEM byte spriteFour[displayNumberOfRows][displayNumberOfColumns] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {3, 3, 3, 3, 3, 3},
    {3, 3, 3, 3, 3, 3},
    {3, 3, 0, 2, 2, 2},
    {3, 3, 0, 0, 2, 0},
    {3, 3, 3, 3, 3, 3},
    {3, 3, 3, 3, 3, 3},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  clearLEDMatrix();
  for(byte i = 0; i<displayNumberOfRows; i++) {
    for(byte j = 0; j<displayNumberOfColumns; j++) {
      LEDMatrix[i][j] = pgm_read_byte(&(spriteFour[i][j]));
    }
  }
  outputDisplay();
  delay(500);

  static const PROGMEM byte spriteFive[displayNumberOfRows][displayNumberOfColumns] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {3, 3, 3, 3, 3, 3},
    {3, 3, 3, 3, 3, 3},
    {3, 3, 3, 3, 3, 3},
    {3, 3, 3, 3, 3, 3},
    {3, 3, 3, 3, 3, 3},
    {3, 3, 3, 3, 3, 3},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  clearLEDMatrix();
  for(byte i = 0; i<displayNumberOfRows; i++) {
    for(byte j = 0; j<displayNumberOfColumns; j++) {
      LEDMatrix[i][j] = pgm_read_byte(&(spriteFive[i][j]));
    }
  }
  outputDisplay();
  delay(2250);

    static const PROGMEM byte spriteSix[displayNumberOfRows][displayNumberOfColumns] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {3, 3, 3, 3, 3, 3},
    {3, 3, 3, 3, 3, 3},
    {3, 3, 0, 0, 0, 0},
    {3, 3, 0, 0, 0, 0},
    {3, 3, 3, 3, 3, 3},
    {3, 3, 3, 3, 3, 3},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  clearLEDMatrix();
  for(byte i = 0; i<displayNumberOfRows; i++) {
    for(byte j = 0; j<displayNumberOfColumns; j++) {
      LEDMatrix[i][j] = pgm_read_byte(&(spriteSix[i][j]));
    }
  }
  outputDisplay();
  delay(500);

      static const PROGMEM byte spriteSeven[displayNumberOfRows][displayNumberOfColumns] = {
    {0, 0, 0, 0, 0, 0},
    {3, 3, 3, 3, 3, 3},
    {3, 3, 3, 3, 3, 3},
    {3, 3, 0, 0, 0, 0},
    {3, 3, 0, 0, 0, 0},
    {3, 3, 0, 0, 0, 0},
    {3, 3, 0, 0, 0, 0},
    {3, 3, 3, 3, 3, 3},
    {3, 3, 3, 3, 3, 3},
    {0, 0, 0, 0, 0, 0}
  };

  clearLEDMatrix();
  for(byte i = 0; i<displayNumberOfRows; i++) {
    for(byte j = 0; j<displayNumberOfColumns; j++) {
      LEDMatrix[i][j] = pgm_read_byte(&(spriteSeven[i][j]));
    }
  }
  outputDisplay();
  delay(2500);
}

}
