
// --------------- Movement functions ---------------------------------
void moveAdventurerLeft() {
  byte adjacent = pgm_read_byte(&(gameMap[adventurer.lineCoordinate][adventurer.columnCoordinate -1]));
  if(adjacent != Wall && adjacent != Tree && adjacent != Water) {
    adventurer.columnCoordinate--;
  }
}

void moveAdventurerUp() {
  byte adjacent = pgm_read_byte(&(gameMap[adventurer.lineCoordinate -1][adventurer.columnCoordinate]));
  if(adjacent != Wall && adjacent != Tree && adjacent != Water) {
    adventurer.lineCoordinate--;
  }
}

void moveAdventurerRight() {
  byte adjacent = pgm_read_byte(&(gameMap[adventurer.lineCoordinate][adventurer.columnCoordinate +1]));
  if(adjacent != Wall && adjacent != Tree && adjacent != Water) {
    adventurer.columnCoordinate++;
  }
}

void moveAdventurerDown() {
  byte adjacent = pgm_read_byte(&(gameMap[adventurer.lineCoordinate +1][adventurer.columnCoordinate]));
  if(adjacent != Wall && adjacent != Tree && adjacent != Water) {
    adventurer.lineCoordinate++;
  }
}
