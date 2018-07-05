#include "entity.hpp"

void Entity::render () {
  drawCube({posX, posY, 0}, materialGreen);
}

void Entity::spawn (double x, double y) {
  posX = x;
  posY = y;
}
