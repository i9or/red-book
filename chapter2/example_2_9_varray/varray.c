//
//  main.c
//  example_2_9_varray
//
//  Created by Igor on 12/06/2023.
//

#include <stdlib.h>

#include <GLUT/glut.h>

void init(void);
void display(void);
void reshape(int, int);

static GLint vertices[] = {
  /* clang-format off */
  25, 25,
  100, 325,
  175, 25,
  175, 325,
  250, 25,
  325, 325
  /* clang-format on */
};

static GLfloat colors[] = {
  /* clang-format off */
  1.f, 0.2f, 0.2f,
  0.2f, 0.2f, 1.f,
  0.8f, 1.f, 0.2f,
  0.75f, 0.75f, 0.75f,
  0.35f, 0.35f, 0.35f,
  0.5f, 0.5f, 0.5f
  /* clang-format on */
};

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(400, 400);
  glutCreateWindow("Vertex Arrays");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();

  return EXIT_SUCCESS;
}

void init(void) {
  glClearColor(0.f, 0.f, 0.f, 0.f);
  glShadeModel(GL_FLAT);
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);

  glColorPointer(3, GL_FLOAT, 0, colors);
  glVertexPointer(2, GL_INT, 0, vertices);

  glBegin(GL_TRIANGLES);
  glArrayElement(0);
  glArrayElement(1);
  glArrayElement(2);
  glArrayElement(3);
  glArrayElement(4);
  glArrayElement(5);
  glEnd();

  glFlush();
}

void reshape(int w, int h) {
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}
