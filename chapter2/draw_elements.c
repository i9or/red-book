#include <stdlib.h>

#include <GLUT/glut.h>

void init(void);
void display(void);
void reshape(int, int);

static GLint vertices[] = {
	/* clang-format off */
	50, 50,
	350, 50,
	350, 350,
	50, 350
	/* clang-format on */
};

static GLfloat colors[] = {
	/* clang-format off */
	1.f, 0.2f, 0.2f,
	0.2f, 0.2f, 1.f,
	0.2f, 1.f, 0.2f,
	1.f, 1.f, 1.f
    /* clang-format on*/
};

static GLubyte indices[] = {
    /* clang-format off */
    0, 1, 2,
    0, 2, 3
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
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glColorPointer(3, GL_FLOAT, 0, colors);
	glVertexPointer(2, GL_INT, 0, vertices);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);

	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}
