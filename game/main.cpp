#include <iostream>
#include <GL/glut.h>
#include "utils/vector3f.cpp"
#include "utils/dimension.cpp"
#include "utils/materials.cpp"
#include "camera.cpp"
#include "game.cpp"

// Config
Dimension window;
Dimension screen;

// Objects
Camera camera;
Game game;

// Proptypes
void display();
void init();
void displayIsometricView();
void displayWithLighting();


void display () {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  displayIsometricView();
  displayWithLighting();

  camera.render(window);
  game.render(screen);
 
  glutSwapBuffers();
}

void displayIsometricView () {
  glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, window.width, 0.0f, window.height, -1000.0f, 1000.0f);

  glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(35.264f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0, window.height/2, 0.0f);
	glRotatef(-45.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glScalef(50.0f, 50.0f, 50.0f);
}

void displayWithLighting () {
  float position[] = { 200.0f, 300.0f, 100.0f, 0.0f };
  glLightfv(GL_LIGHT0, GL_POSITION, position);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
}

void init () {
  glEnable(GL_MULTISAMPLE);
}

int main (int argc, char** argv) {
  glutInit(&argc, argv);

  window = { 1024, 768 };
  screen = { (double)glutGet(GLUT_SCREEN_WIDTH), (double)glutGet(GLUT_SCREEN_HEIGHT) };

  init();

  glutInitWindowSize(window.width, window.height);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
  glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);
  glutCreateWindow("The Whispering Shadows Caverns");
  glutInitWindowPosition((screen.width-window.width)/2, (screen.height-window.height)/2);
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}
