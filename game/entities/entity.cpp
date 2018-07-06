#include "entity.hpp"

Entity::Entity () {
  moveSpeed = .005;
  moveDistance = 0;
  moveDirection = ENTITY_MOVE_NONE;
  posX = 0;
  posY = 0;
  posZ = 0;
}

void Entity::render () {
  drawCube({posX, posY, posZ}, materialGreen);
}

void Entity::spawn (double x, double y) {
  posX = x;
  posY = y;
}

void Entity::entityUpdate (int delta) {
  moveEffect(delta);
  idleEffect(delta);
  update(delta);
}

void Entity::move (int direction) {
  if (moveDirection == ENTITY_MOVE_NONE) {
    moveDirection = direction;
    moveDistance = 1;
  }
}

void Entity::moveEffect (int delta) {
  double deltaSpeed = moveSpeed * delta;

  if (moveDirection != ENTITY_MOVE_NONE) {
    if (moveDistance <= 0) {
      moveDirection = ENTITY_MOVE_NONE;
      moveDistance = 0;
    }
    else if (moveDirection == ENTITY_MOVE_FORWARD) {
      posY += deltaSpeed;
    }
    else if (moveDirection == ENTITY_MOVE_BACKWARD) {
      posY -= deltaSpeed;
    }
    else if (moveDirection == ENTITY_MOVE_LEFT) {
      posX -= deltaSpeed;
    }
    else if (moveDirection == ENTITY_MOVE_RIGHT) {
      posX += deltaSpeed;
    }

    if (moveDistance <= .5) {
      posZ -= deltaSpeed;
      if (posZ < 0) {
        posZ = 0;
      }
    }
    else {
      posZ += deltaSpeed;
    }

    moveDistance -= deltaSpeed;
  }
}

void Entity::idleEffect (int delta) {
  
}
