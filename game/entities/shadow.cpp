class Shadow : public Entity {
  public:
    void update (int) override;
};

void Shadow::update (int delta) {
  int k = std::rand()%6000;
  if (k == 5) {
    move(ENTITY_MOVE_LEFT);
  }
  else if (k == 6) {
    move(ENTITY_MOVE_RIGHT);
  }
  else if (k == 7) {
    move(ENTITY_MOVE_FORWARD);
  }
  else if (k == 8) {
    move(ENTITY_MOVE_BACKWARD);
  }
}
