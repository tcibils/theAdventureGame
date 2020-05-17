
// --------------- Movement functions ---------------------------------
void moveAdventurerLeft() {
  if(adventurer.columnCoordinate > 0) {
    byte adjacent = pgm_read_byte(&(gameMap[adventurer.lineCoordinate][adventurer.columnCoordinate -1]));
    if(adjacent != Wall && adjacent != Tree && adjacent != Water) {
      adventurer.columnCoordinate--;
    }
  }
}

void moveAdventurerUp() {
  if(adventurer.lineCoordinate > 0) {
    byte adjacent = pgm_read_byte(&(gameMap[adventurer.lineCoordinate -1][adventurer.columnCoordinate]));
    if(adjacent != Wall && adjacent != Tree && adjacent != Water) {
      adventurer.lineCoordinate--;
    }
  }
}

void moveAdventurerRight() {
  if(adventurer.columnCoordinate < mapNumberOfColumns - 1) {
    byte adjacent = pgm_read_byte(&(gameMap[adventurer.lineCoordinate][adventurer.columnCoordinate +1]));
    if(adjacent != Wall && adjacent != Tree && adjacent != Water) {
      adventurer.columnCoordinate++;
    }
  }
}

void moveAdventurerDown() {
  if(adventurer.lineCoordinate < mapNumberOfRows - 1) {
    byte adjacent = pgm_read_byte(&(gameMap[adventurer.lineCoordinate +1][adventurer.columnCoordinate]));
    if(adjacent != Wall && adjacent != Tree && adjacent != Water) {
      adventurer.lineCoordinate++;
    }
  }
}
