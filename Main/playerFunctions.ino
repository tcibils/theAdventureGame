
// --------------- Movement functions ---------------------------------
void moveAdventurerLeft() {
  byte adjacent = pgm_read_byte(&(gameMap[adventurerPosition.lineCoordinate][adventurerPosition.columnCoordinate -1]));
  if(adjacent != Wall && adjacent != Tree && adjacent != Water) {
    adventurerPosition.columnCoordinate--;
  }
}

void moveAdventurerUp() {
  byte adjacent = pgm_read_byte(&(gameMap[adventurerPosition.lineCoordinate -1][adventurerPosition.columnCoordinate]));
  if(adjacent != Wall && adjacent != Tree && adjacent != Water) {
    adventurerPosition.lineCoordinate--;
  }
}

void moveAdventurerRight() {
  byte adjacent = pgm_read_byte(&(gameMap[adventurerPosition.lineCoordinate][adventurerPosition.columnCoordinate +1]));
  if(adjacent != Wall && adjacent != Tree && adjacent != Water) {
    adventurerPosition.columnCoordinate++;
  }
}

void moveAdventurerDown() {
  byte adjacent = pgm_read_byte(&(gameMap[adventurerPosition.lineCoordinate +1][adventurerPosition.columnCoordinate]));
  if(adjacent != Wall && adjacent != Tree && adjacent != Water) {
    adventurerPosition.lineCoordinate++;
  }
}
