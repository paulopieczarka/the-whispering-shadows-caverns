#include "entity.cpp"

class Player : public Entity {
  public:
    void update (int) override;
};

void Player::update (int delta) {
  if (keyboard.isKeyPressed(KEY_W)) {
    move(ENTITY_MOVE_FORWARD);
  }
  else if (keyboard.isKeyPressed(KEY_S)) {
    move(ENTITY_MOVE_BACKWARD);
  }
  else if (keyboard.isKeyPressed(KEY_A)) {
    move(ENTITY_MOVE_LEFT);
  }
  else if (keyboard.isKeyPressed(KEY_D)) {
    move(ENTITY_MOVE_RIGHT);
  }
}
