#include <iostream>
#include <GL/glut.h>
#include "utils/dimension.cpp"
#include "camera.cpp"
#include "game.cpp"

Dimension window;
Dimension screen;

Camera camera;
Game game;

void display () {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  // Isometric viewport
  glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, window.width, 0.0f, window.height, -1000.0f, 1000.0f);
  
  glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(35.264f, 1.0f, 0.0f, 0.0f);
	glTranslatef(window.width/2, window.height/2, 0.0f);
	glRotatef(-45.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glScalef(50.0f, 50.0f, 50.0f);

  camera.onRender(window);
  
  // Render stuff.
  game.render(screen);
 
  glutSwapBuffers();
}

int main (int argc, char** argv) {
  glutInit(&argc, argv);

  window = { 1024, 768 };
  screen = { (double)glutGet(GLUT_SCREEN_WIDTH), (double)glutGet(GLUT_SCREEN_HEIGHT) };

  glutInitWindowSize(window.width, window.height);
  glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE );
  glutCreateWindow("The Whispering Shadows Caverns");
  glutInitWindowPosition((screen.width-window.width)/2, (screen.height-window.height)/2);
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}
