void automaticallyMoveEnnemies() {
  for(byte i = 0; i < numberOfEnnemies; i++) {
    automaticallyMoveEnnemy(i);
  }
}

void automaticallyMoveEnnemy(byte ennemyToMoveIndex) {
  // "Vanilla" ennemy
  if(ennemies[ennemyToMoveIndex].ennemyType == 0) {
    basicPathFindingEnnemy(ennemyToMoveIndex);
    }

  // Slightly random ennemy
  else if(ennemies[ennemyToMoveIndex].ennemyType == 1) {
    byte temp = random(10);
    if     (temp < 6)  {basicPathFindingEnnemy(ennemyToMoveIndex);}
    else if(temp == 6) {moveEnnemyLeft(ennemyToMoveIndex);}
    else if(temp == 7) {moveEnnemyRight(ennemyToMoveIndex);}
    else if(temp == 8) {moveEnnemyUp(ennemyToMoveIndex);}
    else if(temp == 9) {moveEnnemyDown(ennemyToMoveIndex);}
  }
}

void basicPathFindingEnnemy(byte ennemyToMoveIndex) {
    // Horizontal distance will be negative if the ennemy is on the left, positive if he's on the right
  int horizontalDistance = adventurer.columnCoordinate - ennemies[ennemyToMoveIndex].columnCoordinate;
  
  // Vertical distance will be negative if the played is above the ennemy, positive if he's under
  int verticalDistance = adventurer.lineCoordinate - ennemies[ennemyToMoveIndex].lineCoordinate;

  // Checking if it's better to move horizontally or vertically
  // If there's a greater horizontal distance
  if(abs(horizontalDistance) > abs(verticalDistance)) {
    // and if this distance is negative, meaning the player is far on the left
    if(horizontalDistance < 0) {
      moveEnnemyLeft(ennemyToMoveIndex);
    }

    else if(horizontalDistance > 0) {
      moveEnnemyRight(ennemyToMoveIndex);
    }
  }

  else if(abs(horizontalDistance) <= abs(verticalDistance)) {
    if(verticalDistance < 0) {
      moveEnnemyUp(ennemyToMoveIndex);
    }
    else if(verticalDistance > 0){
      moveEnnemyDown(ennemyToMoveIndex);
    } 
  }
}


void moveEnnemyLeft(byte ennemyToMoveIndex) {
  if(ennemies[ennemyToMoveIndex].isAlive == 1) {
    byte adjacent = pgm_read_byte(&(gameMap[ennemies[ennemyToMoveIndex].lineCoordinate][ennemies[ennemyToMoveIndex].columnCoordinate -1]));
    if(adjacent != Wall && adjacent != Tree && adjacent != Water) {
      // We don't want the player getting outside of the frame
      if(ennemies[ennemyToMoveIndex].columnCoordinate > 0){
        byte temp = ennemies[ennemyToMoveIndex].columnCoordinate;
        ennemies[ennemyToMoveIndex].columnCoordinate = temp - 1;    
      }
    }
  }
}

void moveEnnemyRight(byte ennemyToMoveIndex) {
  if(ennemies[ennemyToMoveIndex].isAlive == 1) {
    byte adjacent = pgm_read_byte(&(gameMap[ennemies[ennemyToMoveIndex].lineCoordinate][ennemies[ennemyToMoveIndex].columnCoordinate +1]));
    if(adjacent != Wall && adjacent != Tree && adjacent != Water) {
      // We don't want the player getting outside of the frame
      if(ennemies[ennemyToMoveIndex].columnCoordinate < mapNumberOfColumns-1){
        byte temp = ennemies[ennemyToMoveIndex].columnCoordinate;
        ennemies[ennemyToMoveIndex].columnCoordinate = temp + 1;
      }
    }
  }
}

void moveEnnemyUp(byte ennemyToMoveIndex) {
  if(ennemies[ennemyToMoveIndex].isAlive == 1) {
    byte adjacent = pgm_read_byte(&(gameMap[ennemies[ennemyToMoveIndex].lineCoordinate -1][ennemies[ennemyToMoveIndex].columnCoordinate]));
    if(adjacent != Wall && adjacent != Tree && adjacent != Water) {
      // We don't want the player getting outside of the frame
      if(ennemies[ennemyToMoveIndex].lineCoordinate > 0){
        byte temp = ennemies[ennemyToMoveIndex].lineCoordinate;
        ennemies[ennemyToMoveIndex].lineCoordinate = temp - 1;  
      }
    }
  }
}

void moveEnnemyDown(byte ennemyToMoveIndex) {
  if(ennemies[ennemyToMoveIndex].isAlive == 1) {
    byte adjacent = pgm_read_byte(&(gameMap[ennemies[ennemyToMoveIndex].lineCoordinate +1][ennemies[ennemyToMoveIndex].columnCoordinate]));
    if(adjacent != Wall && adjacent != Tree && adjacent != Water) {
      // We don't want the player getting outside of the frame
      if(ennemies[ennemyToMoveIndex].lineCoordinate < mapNumberOfRows   - 1){
        byte temp = ennemies[ennemyToMoveIndex].lineCoordinate;
        ennemies[ennemyToMoveIndex].lineCoordinate = temp + 1;    
      }
    }
  }
}
