//
//  main.c
//  example_2_13_draw_elements_from_file
//
//  Created by Igor on 12/06/2023.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <GLUT/glut.h>

unsigned int numberOfVertices;
unsigned int numberOfFaces;
GLfloat* vertices;
GLubyte* colors;
GLuint* indices;
GLfloat angle = 0.f;

void init(void);
void display(void);
void reshape(int, int);
void idle(void);
void terminate(void);
bool parseModel(const char*, unsigned int*, unsigned int*, GLfloat**, GLubyte**, GLuint**);
void freeModel(GLfloat*, GLubyte*, GLuint*);

int main(int argc, char** argv) {
  if (!parseModel("../assets/stanford_dragon.txt",
                  &numberOfVertices, &numberOfFaces,
                  &vertices, &colors, &indices)) {
    return EXIT_FAILURE;
  };

  atexit(terminate);

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(400, 400);
  glutCreateWindow("Vertex Arrays From File");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(idle);
  glutMainLoop();

  return EXIT_SUCCESS;
}

void init(void) {
  glClearColor(0.f, 0.f, 0.f, 0.f);
  glEnable(GL_DEPTH_TEST);
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();

  glRotatef(angle, 0.0f, 1.0f, 0.0f);

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);

  glVertexPointer(3, GL_FLOAT, 0, vertices);
  glColorPointer(4, GL_UNSIGNED_BYTE, 0, colors);

  glDrawElements(GL_TRIANGLES, (GLsizei)numberOfFaces * 3, GL_UNSIGNED_INT, indices);

  glPopMatrix();

  glutSwapBuffers();
}

void idle(void) {
  angle = angle + 2.f;

  if (angle > 360.f) {
    angle = 0.f;
  }

  glutPostRedisplay();
}

void reshape(int w, int h) {
  double width = (double)w;
  double height = h == 0 ? 1.0 : (double)h;

  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, width / height, 0.1, 100.0);
  gluLookAt(-25.0, 25.0, -25.0,
            0.0, 0.0, 0.0,
            0.0, 1.0, 0.0);
}

void terminate(void) {
  freeModel(vertices, colors, indices);
}

bool parseModel(const char* filepath,
                unsigned int* nv, unsigned int* nf,
                GLfloat** v, GLubyte** c, GLuint** i) {
  FILE* file = fopen(filepath, "r");
  if (file == NULL) {
    printf("Failed to open the file.\n");
    return false;
  }

  char line[256] = "\0";
  fgets(line, sizeof(line), file);
  sscanf(line, "nv %u", nv);

  fgets(line, sizeof(line), file);
  sscanf(line, "nf %u", nf);

  *v = (GLfloat*)malloc(*nv * sizeof(GLfloat) * 3);
  *c = (GLubyte*)malloc(*nv * sizeof(GLubyte) * 4);
  *i = (GLuint*)malloc(*nf * sizeof(GLuint) * 3);

  for (unsigned int j = 0; j < *nv; ++j) {
    fgets(line, sizeof(line), file);
    sscanf(line, "%f %f %f %hhu %hhu %hhu %hhu",
           &(*v)[j * 3], &(*v)[j * 3 + 1], &(*v)[j * 3 + 2],
           &(*c)[j * 4], &(*c)[j * 4 + 1], &(*c)[j * 4 + 2], &(*c)[j * 4 + 3]);
  }

  for (unsigned int j = 0; j < *nf; ++j) {
    fgets(line, sizeof(line), file);
    sscanf(line, "%u %u %u",
           &(*i)[j * 3], &(*i)[j * 3 + 1], &(*i)[j * 3 + 2]);
  }

  fclose(file);
  return true;
}

void freeModel(GLfloat* v, GLubyte* c, GLuint* i) {
  free(v);
  free(c);
  free(i);
}
