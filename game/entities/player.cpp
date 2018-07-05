#include "entity.cpp"

class Player : public Entity {
  public:
    void update (int) override;
};

void Player::update (int delta) {
  if (keyboard.isKeyPressed(KEY_W)) {
    posY++;
  }
  else if (keyboard.isKeyPressed(KEY_S)) {
    posY--;
  }
  else if (keyboard.isKeyPressed(KEY_A)) {
    posX--;
  }
  else if (keyboard.isKeyPressed(KEY_D)) {
    posX++;
  }
}
