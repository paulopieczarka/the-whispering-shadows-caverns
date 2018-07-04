class Game {
  public:
    void render (Dimension);
    void update (double);
};

void Game::render (Dimension screen) {
  glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f( 0.5f, -0.5f);
    glVertex2f( 0.5f,  0.5f);
    glVertex2f(-0.5f,  0.5f);
  glEnd();
}

void Game::update (double delta) {
  
}
