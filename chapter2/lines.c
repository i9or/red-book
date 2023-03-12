#include <stdlib.h>

#include <GLUT/glut.h>

#define drawOneLine(x1, y1, x2, y2) \
  glBegin(GL_LINES);                \
  glVertex2f((x1), (y1));           \
  glVertex2f((x2), (y2));           \
  glEnd();

void init(void);
void display(void);
void reshape(int, int);

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(400, 150);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Lines");
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

  glEnable(GL_LINE_STIPPLE);

  glColor3f(1.f, 0.f, 0.f);
  glLineStipple(1, 0x0101); /* dotted */
  drawOneLine(50.f, 125.f, 150.f, 125.f);
  glLineStipple(1, 0x00FF); /* dashed */
  drawOneLine(150.f, 125.f, 250.f, 125.f);
  glLineStipple(1, 0x1C47); /* dash-dot-dash */
  drawOneLine(250.f, 125.f, 350.f, 125.f);

  glColor3f(0.f, 1.f, 0.f);
  glLineWidth(5.f);
  glLineStipple(1, 0x0101); /* dotted */
  drawOneLine(50.f, 100.f, 150.f, 100.f);
  glLineStipple(1, 0x00FF); /* dashed */
  drawOneLine(150.f, 100.f, 250.f, 100.f);
  glLineStipple(1, 0x1C47); /* dash-dot-dash */
  drawOneLine(250.f, 100.f, 350.f, 100.f);
  glLineWidth(1.f);

  glLineStipple(1, 0x1C47);
  glColor3f(0.f, 0.f, 1.f);
  glBegin(GL_LINE_STRIP);
  for (int i = 0; i < 7; ++i) {
    glVertex2f(50.f + ((GLfloat) i * 50.f), 75.f);
  }
  glEnd();

  glColor3f(1.f, 1.f, 0.f);
  for (int i = 0; i < 6; ++i) {
    drawOneLine(50.f + ((GLfloat) i * 50.f), 50.f,
                50.f + ((GLfloat) (i + 1) * 50.f), 50.f);
  }

  glLineStipple(5, 0x1C47);
  glColor3f(1.f, 0.f, 1.f);
  drawOneLine(50.f, 25.f, 350.f, 25.f);

  glDisable(GL_LINE_STIPPLE);
  glFlush();
}

void reshape(int w, int h) {
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble) h);
}