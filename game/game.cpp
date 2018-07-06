#include "prefabs/tile.cpp"
#include "prefabs/cube.cpp"
#include "entities/player.cpp"
#include "entities/shadow.cpp"
#include "world.cpp"

class Game {
  public:
    int size = 16;
    int monstersLength = 1;
    double playerX = 2;
    double playerY = 2;

    World world;
    Player player;
    Shadow monsters[16];

    void init ();
    void render (Dimension);
    void update (double);
};

void Game::init () {
  player.spawn(2, 2);
  monsters[0].spawn(std::rand()%size, std::rand()%size);
}

void Game::render (Dimension screen) {
  world.render();

  for (int i=0; i < monstersLength; i++) {
    monsters[i].render();
  }
  
  player.render();
}

void Game::update (double delta) {
  world.update(delta);

  for (int i=0; i < monstersLength; i++) {
    monsters[i].entityUpdate(delta);
  }

  player.entityUpdate(delta);

  if (mouse.isButtonPressed(MOUSE_LEFT_BUTTON)) {
    std::cout << "Click\n";
  }
}
