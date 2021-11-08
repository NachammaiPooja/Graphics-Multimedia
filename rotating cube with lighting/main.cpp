#include <gl/glut.h>
#include <stdio.h>

void myInit() {
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 2, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 3, 0, 0, 0, 0, 1, 0);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

}

GLfloat T = 0;
void Spin() {
	T = T + 0.0001;
	if (T > 360)
		T = 0;
	glutPostRedisplay();
}

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	float t = T * (3.14 / 180);
	glRotatef(t, 1, 0, 0);
	glutSolidCube(1);
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Projections");
	myInit();
	glutDisplayFunc(Draw);
	glutIdleFunc(Spin);
	glutMainLoop();
	return 0;
}
