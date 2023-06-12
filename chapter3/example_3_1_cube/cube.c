//
//  main.c
//  example_3_1_cube
//
//  Created by Igor on 12/06/2023.
//

#include <stdlib.h>

#include <GLUT/GLUT.h>

void init(void) {
  glClearColor(0.f, 0.f, 0.f, 0.f);
  glShadeModel(GL_FLAT);
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.f, 1.f, 1.f);
  glLoadIdentity();
  gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glScalef(1.f, 2.f, 1.f);
  glutWireCube(1.0);
  glFlush();
}

void reshape(int w, int h) {
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char * argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Cube");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();

  return EXIT_SUCCESS;
}
