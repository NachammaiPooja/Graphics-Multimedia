#include<gL/glut.h>
#include<math.h>
#include<stdio.h>
#include<iostream>
float x_1, y_1, x_2, y_2;

void init() {
    glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.9, 0.8, 0.8, 0.9);
	glColor3f(0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y) {
    glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void bresen_line(int x1, int x2, int y1, int y2) {
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x, y;

	dx = x2 - x1;
	dy = y2 - y1;

	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;

	incx = 1;
	if (x2 < x1) incx = -1;

	incy = 1;
	if (y2 < y1) incy = -1;

	x = x1; y = y1;
	if (dx > dy) {
		draw_pixel(x, y);
		e = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (i = 0; i < dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			draw_pixel(x, y);
		}
	}
	else {
		draw_pixel(x, y);
		e = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (i = 0; i < dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			draw_pixel(x, y);
		}
	}
}

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
    //left to right m<1
    bresen_line(10, 200, 200, 300);
	//right to left m<1
	bresen_line(100, 200, 300, 100);
    //left to right m>1
    bresen_line(100, 50, 400, 300);
	//right to left m>1
	bresen_line(80, 90, 120, 150);
    
    //letter A
    bresen_line(300, 350, 130, 320);
    bresen_line(350, 400, 320, 130);
    bresen_line(325, 375, 225, 225);
    
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1024, 1024);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham's Line Algorithm");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
