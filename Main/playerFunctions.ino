
// --------------- Movement functions ---------------------------------
void moveAdventurerLeft() {
  if(gameMap[adventurerPosition.lineCoordinate][adventurerPosition.columnCoordinate -1] != Wall) {
    adventurerPosition.columnCoordinate--;
  }
}

void moveAdventurerUp() {
  if(gameMap[adventurerPosition.lineCoordinate -1][adventurerPosition.columnCoordinate] != Wall) {
    adventurerPosition.lineCoordinate--;
  }
}

void moveAdventurerRight() {
  if(gameMap[adventurerPosition.lineCoordinate][adventurerPosition.columnCoordinate +1] != Wall) {
    adventurerPosition.columnCoordinate++;
  }
}

void moveAdventurerDown() {
  if(gameMap[adventurerPosition.lineCoordinate +1][adventurerPosition.columnCoordinate] != Wall) {
    adventurerPosition.lineCoordinate++;
  }
}
