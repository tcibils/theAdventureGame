void automaticallyMoveEnnemies() {
  for(byte i = 0; i < numberOfEnnemies; i++) {
    automaticallyMoveEnnemy(ennemies[i]);
  }
}

void automaticallyMoveEnnemy(Ennemy ennemyToMove) {
  // Horizontal distance will be negative if the ennemy is on the left, positive if he's on the right
  int horizontalDistance = adventurer.columnCoordinate - ennemyToMove.columnCoordinate;
  
  // Vertical distance will be negative if the played is above the ennemy, positive if he's under
  int verticalDistance = adventurer.lineCoordinate - ennemyToMove.lineCoordinate;


  // Checking if it's better to move horizontally or vertically
  // If there's a greater horizontal distance
  if(abs(horizontalDistance) > abs(verticalDistance)) {
    // and if this distance is negative, meaning the player is far on the left
    if(horizontalDistance < 0) {
      moveEnnemyLeft(ennemyToMove);
    }

    else if(horizontalDistance > 0) {
      moveEnnemyRight(ennemyToMove);
    }
  }

  else if(abs(horizontalDistance) <= abs(verticalDistance)) {
    if(verticalDistance < 0) {
      moveEnnemyUp(ennemyToMove);
    }
    else if(verticalDistance > 0){
      moveEnnemyDown(ennemyToMove);
    } 
  }
}

void moveEnnemyLeft(Ennemy ennemyToMove) {
  if(ennemyToMove.isAlive == 1) {
    // We don't want the player getting outside of the frame
    if(ennemyToMove.columnCoordinate > 0){
      byte temp = ennemyToMove.columnCoordinate;
      ennemyToMove.columnCoordinate = temp - 1;    
    }
  }
}

void moveEnnemyRight(Ennemy ennemyToMove) {
  if(ennemyToMove.isAlive == 1) {
    // We don't want the player getting outside of the frame
    if(ennemyToMove.columnCoordinate < mapNumberOfColumns-1){
      byte temp = ennemyToMove.columnCoordinate;
      ennemyToMove.columnCoordinate = temp + 1;
    }
  }
}

void moveEnnemyUp(Ennemy ennemyToMove) {
  if(ennemyToMove.isAlive == 1) {
    // We don't want the player getting outside of the frame
    if(ennemyToMove.lineCoordinate > 0){
      byte temp = ennemyToMove.lineCoordinate;
      ennemyToMove.lineCoordinate = temp - 1;  
    }
  }
}

void moveEnnemyDown(Ennemy ennemyToMove) {
  if(ennemyToMove.isAlive == 1) {
    // We don't want the player getting outside of the frame
    if(ennemyToMove.lineCoordinate < mapNumberOfRows   - 1){
      byte temp = ennemyToMove.lineCoordinate;
      ennemyToMove.lineCoordinate = temp + 1;    
    }
  }
}
