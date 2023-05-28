#include <stdlib.h>

#include <GLUT/glut.h>

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.2f, 0.5f, 0.8f);
	glBegin(GL_POLYGON);

	glVertex3f(0.25f, 0.25f, 0.f);
	glVertex3f(0.75f, 0.25f, 0.f);
	glVertex3f(0.75f, 0.75f, 0.f);
	glVertex3f(0.25f, 0.75f, 0.f);

	glEnd();

	glFlush();
}

void init(void) {
	glClearColor(0.f, 0.f, 0.f, 1.f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1.0, 0.0, 1.0);
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
