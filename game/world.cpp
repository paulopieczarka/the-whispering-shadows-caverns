#define TILE_DIRT 0

struct Tile {
  int id;
  Material material;
  bool isSolid;
};

class World {
  private:
    int **grid;

  protected:
    void generate ();

  public:
    const int size = 16;

    World();
    void render ();
    void update (int);
};

World::World () {
  grid = (int **)malloc(size * sizeof(int*));
  for (int i=0; i < size; i++) {
    grid[i] = (int *)malloc(size * size * sizeof(int));
  }

  std::vector<Tile> tiles;
  tiles.push_back({ 0, materialBronze, false });

  generate();
}

void World::generate () {
  for (int i=0; i < size; i++) {
    for (int j=0; j < size; j++) {
      grid[i][j] = TILE_DIRT;
    }
  }
}

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
