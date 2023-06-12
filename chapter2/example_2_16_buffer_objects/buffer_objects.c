//
//  main.c
//  example_2_16_buffer_objects
//
//  Created by Igor on 12/06/2023.
//

#include <stdlib.h>

#include <GLUT/glut.h>

#define VERTICES 0
#define INDICES 1
#define NUM_BUFFERS 2

GLuint buffers[NUM_BUFFERS];

GLfloat vertices[][3] = {
  /* clang-format off */
  { -1.f, -1.f, -1.f },
  {  1.f, -1.f, -1.f },
  {  1.f,  1.f, -1.f },
  { -1.f,  1.f, -1.f },
  { -1.f, -1.f,  1.f },
  {  1.f, -1.f,  1.f },
  {  1.f,  1.f,  1.f },
  { -1.f,  1.f,  1.f }
  /* clang-format on */
};

GLubyte indices[][4] = {
  /* clang-format off */
  { 0, 1, 2, 3 },
  { 4, 7, 6, 5 },
  { 0, 4, 5, 1 },
  { 3, 2, 6, 7 },
  { 0, 3, 7, 4 },
  { 1, 5, 6, 2 }
  /* clang-format on */
};

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0.2f, 0.5f, 0.8f);

  glBindBuffer(GL_ARRAY_BUFFER, buffers[VERTICES]);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[INDICES]);

  glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, NULL);

  glFlush();
}

void init(void) {
  glClearColor(0.f, 0.f, 0.f, 1.f);

  glGenBuffers(NUM_BUFFERS, buffers);

  glBindBuffer(GL_ARRAY_BUFFER, buffers[VERTICES]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexPointer(3, GL_FLOAT, 0, NULL);
  glEnableClientState(GL_VERTEX_ARRAY);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[INDICES]);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-3.0, 3.0, -3.0, 3.0);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(250, 250);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("hello");
  init();
  glutDisplayFunc(display);
  glutMainLoop();

  return EXIT_SUCCESS;
}
