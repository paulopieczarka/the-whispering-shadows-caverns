#include "prefabs/tile.cpp"
#include "prefabs/cube.cpp"

class Game {
  public:
    int size = 16;

    void render (Dimension);
    void update (double);
};

void Game::render (Dimension screen) {
  for (int i=0; i < size; i++){
    for (int j=0; j < size; j++){
      drawTile({(double)i, (double)j, 0}, materialBronze);

      if (i == 0 || j == 0 || i == size-1 || j == size-1) {
        drawCube({(double)i, (double)j, 0}, materialGreen);
      }
    }
  }
}

void Game::update (double delta) {
  if (keyboard.isKeyDown(KEY_W)) {
    std::cout << "WWWW\n";
  }

  if (mouse.isButtonPressed(MOUSE_LEFT_BUTTON)) {
    std::cout << "Click\n";
  }
}
