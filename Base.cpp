//#include<GLUT/GLUT.h>
#include<GL/glut.h>
#include<iostream>
#include<vector>
#include<utility>
#include<math.h>
#include<cstring>
using namespace std;

int pntX1, pntY1;
vector <int> pntX, pntY;
void myinit() {
	glClearColor(1, 1, 1, 0);
	glColor3f(0, 0, 0);
	glPointSize(3);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-640, 640, -480, 480);
}

void mydisp() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glVertex2d(10, 10);
	glVertex2d(110, 10);
	glVertex2d(110, 100);
	glVertex2d(10, 100);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2d(10, 10);
	glVertex2d(60, 10);
	glVertex2d(30, 60);
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int k = 0; k < 4; k++) {
		glVertex2i(pntX[k], pntY[k]);
	}
	glEnd();
	glFlush();
}

int main(int argc, char *argv[]) {
	int n;
	cout << "please enter side num";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Enter val" << (i + 1) << ":";
		cin >> pntX1 >> pntY1;
		pntX.push_back(pntX1);
		pntY.push_back(pntY1);
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutCreateWindow("TRIALS");
	glutDisplayFunc(mydisp);
	myinit();
	glutMainLoop();
	return 1;
}
