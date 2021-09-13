#include<windows.h>
#include<GL/glut.h>
#include<math.h>

void myInit() {// initialize colors
    glClearColor(0.9, 0.8, 0.8, 0.9);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(10);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void myDisplay() {
    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT);

    //1.Points:
    glBegin(GL_POINTS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2d(150, 100);
    glVertex2d(100, 230);
    glVertex2d(170, 130);
    glVertex2d(300, 350);
    glEnd();

    //2.LINES
    glBegin(GL_LINES);
    glVertex2d(580, 80);
    glVertex2d(500, 80);
    glVertex2d(670, 80);
    glVertex2d(800, 40);
    glEnd();

    //3.LINE STRIP
    glBegin(GL_LINE_STRIP);
    glColor3f(0.1, 0.2, 0.1);
    glVertex2d(270, 100);
    glVertex2d(100, 230);
    glVertex2d(270, 150);
    glVertex2d(300, 350);
    glEnd();
        
    //4.QUADS : Square
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.5, 0.6);
    glVertex2d(200, 200);
    glVertex2d(300, 200);
    glVertex2d(300, 300);
    glVertex2d(200, 300);
    glEnd();

    //5.Triangle:
    glBegin(GL_TRIANGLES);
    glColor3f(0.2, 0.5, 0.4);
    glVertex2d(100, 200);
    glVertex2d(50, 150);
    glVertex2d(150, 150);
    glEnd();

    //6. MULTIPLE TRIANGLES
    glBegin(GL_TRIANGLES);
    glColor3f(0.5, 0.5, 0.6);
    glVertex2d(350, 90);
    glVertex2d(90, 90);
    glVertex2d(170, 60);
    glVertex2d(100, 100);
    glVertex2d(290, 190);
    glVertex2d(200, 200);
    glEnd();

    //7.Quad strip :
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.1, 0.5, 0.1);
    glVertex2d(600, 600);
    glVertex2d(750, 600);
    glVertex2d(750, 750);
    glVertex2d(600, 750);

    glVertex2d(350, 350);
    glVertex2d(450, 350);
    glVertex2d(450, 450);
    glVertex2d(350, 450);
    glEnd();

    //8.polygon:
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.5, 0.6);
    glVertex2i(230, 350);//Top left
    glVertex2i(250, 350);//Top Right
    glVertex2i(250, 296);//Bottom Right
    glVertex2i(230, 318);//Bottom Left
    glEnd();

    /*flush GL buffers*/
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1540, 1540);//set window size
    glutCreateWindow("primitives");//create window and set title to house
    glutDisplayFunc(myDisplay);//call the displaying function
    myInit();//call the displaying function
    glutMainLoop();//keep displaying until program is closed.
    return 1;
}
