#include "prefabs/tile.cpp"
#include "prefabs/cube.cpp"
#include "entities/player.cpp"

class Game {
  public:
    int size = 16;
    double playerX = 2;
    double playerY = 2;

    Player player;

    void init ();
    void render (Dimension);
    void update (double);
};

void Game::init () {
  player.spawn(2, 2);
}

void Game::render (Dimension screen) {
  for (int i=0; i < size; i++){
    for (int j=0; j < size; j++){
      drawTile({(double)i, (double)j, 0}, materialBronze);

      if (i == 0 || j == 0 || i == size-1 || j == size-1) {
        drawCube({(double)i, (double)j, 0}, materialGreen);
      }
    }
  }
  
  player.render();
}

void Game::update (double delta) {
  player.update(delta);

  if (mouse.isButtonPressed(MOUSE_LEFT_BUTTON)) {
    std::cout << "Click\n";
  }
}
