#include <stdio.h>
#include <iostream>
#include<gl/glut.h>
using namespace std;

int xc, yc, r;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x + xc, y + yc);
	glEnd();
}

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 2.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);

}

void midPointCircleAlgo(int xc, int yc, int r)
{
	glBegin(GL_POINTS);
	//glPointSize(6.0);
	int x = 0;
	int y = r;
	float p = 5 / 4 - r;
	glVertex2i(x + xc, y + yc);

	while (y > x)
	{
		if (p < 0)
		{
			x++;
			p += 2 * x + 1;
		}
		else
		{
			y--;
			x++;
			p += 2 * (x - y) + 1;
		}

		glVertex2i(x + xc, y + yc);
		glVertex2i(x + xc, -y + yc);
		glVertex2i(-x + xc, y + yc);
		glVertex2i(-x + xc, -y + yc);

		glVertex2i(y + xc, x + yc);
		glVertex2i(-y + xc, x + yc);
		glVertex2i(y + xc, -x + yc);
		glVertex2i(-y + xc, -x + yc);
	}
	glEnd();
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	//4b
	glPointSize(5.0);
	midPointCircleAlgo(230, 230, 15);
	midPointCircleAlgo(190, 200, 15);
	midPointCircleAlgo(190, 280, 15);
	midPointCircleAlgo(280, 190, 15);
	midPointCircleAlgo(280, 240, 15);
	midPointCircleAlgo(299, 270, 15);
	midPointCircleAlgo(260, 260, 15);
	//4a
	glColor3f(0.7, 0.4, 0.1);
	glPointSize(8.0);
	midPointCircleAlgo(240, 250, 100);


	glFlush();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Midpoint Circle Drawing!");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
