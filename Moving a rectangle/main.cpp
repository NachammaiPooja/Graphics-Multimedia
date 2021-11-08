#include<glut.h>
#include<math.h>
#include<stdio.h>

int xc = 10, yc = 250;
void myInit() {
	glClearColor(1, 1, 1, 0);
	glColor3f(1, 0, 0);
	glPointSize(2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
}
void drawscene(int state) {
	xc += 5;
	if (xc >= 500)
		xc = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_POLYGON);
	glVertex2d(xc, 250);
	glVertex2d(xc + 20, 250);
	glVertex2d(xc +20, 200);
	glVertex2d(xc, 200);
	glEnd();

	glFlush();
	glutTimerFunc(70, drawscene, state);

}
void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT );
	glutTimerFunc(70, drawscene, 0);
}

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Practicals");
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();

	return 1;
}
