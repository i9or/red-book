#include <stdbool.h>
#include <stdlib.h>

#include <GLUT/glut.h>

static GLfloat spin = 0.f;
static bool isSpinning = false;

void init(void);
void display(void);
void spinDisplay(void);
void reshape(int, int);
void mouse(int, int, int, int);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutCreateWindow("Double Buffering");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutIdleFunc(spinDisplay);
	glutMainLoop();

	return EXIT_SUCCESS;
}

void init(void) {
	glClearColor(0.f, 0.f, 0.f, 0.f);
	glShadeModel(GL_FLAT);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(spin, 0.f, 0.f, 1.f);
	glColor3f(0.f, 1.f, 0.f);
	glRectf(-25.f, -25.f, 25.f, 25.f);
	glPopMatrix();
	glutSwapBuffers();
}

void spinDisplay(void) {
	if (isSpinning) {
		spin = spin + 2.f;

		if (spin > 360.f) {
			spin = 0.f;
		}
	}

	glutPostRedisplay();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-50.0, 50.0, -50.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button, int state, int x, int y) {
	switch (button) {
		case GLUT_LEFT_BUTTON:
			if (state == GLUT_DOWN) {
				isSpinning = true;
			}
			break;
		case GLUT_RIGHT_BUTTON:
			if (state == GLUT_DOWN) {
				isSpinning = false;
			}
			break;
		default:
			break;
	}
}