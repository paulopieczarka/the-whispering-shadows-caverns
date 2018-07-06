class World {
  public:
    const int size = 16;

    void render ();
    void update (int);
};

void World::render () {
  for (int i=0; i < size; i++){
    for (int j=0; j < size; j++){
      drawTile({(double)i, (double)j, 0}, materialBronze);

      if (i == 0 || j == 0 || i == size-1 || j == size-1) {
        drawCube({(double)i, (double)j, 0}, materialGreen);
      }
    }
  }
}

void World::update (int delta) {

}
