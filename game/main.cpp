#include <iostream>
#include <GL/glut.h>

struct Dimension {
  double width;
  double height;
};

Dimension window;
Dimension screen;

void display () {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  // Viewport
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  double ar = screen.width / screen.height;
  glOrtho( -2 * ar, 2 * ar, -2, 2, -1, 1);
  
  // Render stuff.
  glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f( 0.5f, -0.5f);
    glVertex2f( 0.5f,  0.5f);
    glVertex2f(-0.5f,  0.5f);
  glEnd();
 
  glutSwapBuffers();
}

int main (int argc, char** argv) {
  glutInit(&argc, argv);

  screen = { 1024, 768 };
  window = { (double)glutGet(GLUT_SCREEN_WIDTH), (double)glutGet(GLUT_SCREEN_HEIGHT) };

  glutInitWindowSize(screen.width, screen.height);
  glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE );
  glutCreateWindow("The Whispering Shadows Caverns");
  glutInitWindowPosition((window.width-screen.width)/2, (window.height-screen.height)/2);
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}
