//2-A

//#include <gl/glut.h>
//#include <stdio.h>
//#include <iostream>
//using namespace std;
//const float PI = 3.14;
//
//void drawLine(int x0, int y0, int x1, int y1) {
//    glBegin(GL_POINTS);
//    glColor3f(1.0, 1.0, 1.0);
//    int tempx, tempy;
//    if (x1 < x0) {
//        tempx = x0;
//        tempy = y0;
//        y0 = y1;
//        x0 = x1;
//        x1 = tempx;
//        y1 = tempy;
//    }
//    double m = (double)(y1 - y0) / (x1 - x0);
//    double y = (double)y0;
//    double x = (double)x0;
//    if (m < 1) {
//        while (x <= x1) {
//            glColor3d(1, 0, 0);
//            if (-m > 1) {
//                glColor3d(0, 0, 1);
//            }
//            glVertex2d(x, floor(y));
//            //printf("%f %f\n", floor(y), x);
//            y = y + m;
//            x++;
//        }
//    }
//    else {
//        double m1 = 1 / m;
//        while (y <= y1) {
//            glColor3d(0, 0, 1);
//            glVertex2d(floor(x), y);
//            y++;
//            x = x + m1;
//        }
//    }
//    glEnd();
//}
//
//void init(void) {
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-1000, 1000, -1000, 1000);
//}
//void display(void)
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    printf("\nEnter x0 y0:");
//    int x1, y1, x0, y0;
//    cin >> x0 >> y0;
//    printf("\nEnter x1 y1:");
//    cin >> x1 >> y1;
//    drawLine(x0, y0, x1, y1);
//    glutSwapBuffers();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(500, 500);
//    glutInitWindowPosition(50, 50);
//    glutCreateWindow("DDA Line Drawing!");
//    init();
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}

//2-B

#include<stdlib.h>
#include<gl/glut.h>
#include<math.h>
#include<stdio.h>
#include<time.h>
void myInit() {
    glClearColor(1.0, 1.0, 2.0, 1.0);
    glColor3f(0.23, 0.26, 0.14);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPointSize(1);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}
int round(float num) {
    return floor(num + 0.5);
}
void lineDDA(int x1, int y1, int x2, int y2) {
    float x = x1, y = y1;
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xi = dx / (float)steps;
    float yi = dy / (float)steps;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; ++i) {
        glVertex2d(round(x), round(y));
        x += xi;
        y += yi;
    }
    glEnd();
}
void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    srand((unsigned)time(NULL));
    int x1, y1, x2, y2, dis;
    for (int i = 0; i < 200; ++i) {
        x1 = abs(rand() % 500 + 1);
        y1 = abs(rand() % 500 + 1);
        dis = abs(rand() % 130 + 10);
        x2 = int(sqrt((dis * dis) / 2)) + x1;
        y2 = int(sqrt((dis * dis) / 2)) + y1;
        lineDDA(x1, y1, x2, y2);
    }
    glFlush();
}
int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Line Exercise");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 1;
}
