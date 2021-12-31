#include <iostream>
#include <cstring>
#include <GL/glut.h>
#include <math.h>

bool isOrtho = true;
double x_rotate = 0;
double y_rotate = 0;

void drawAxes()
{
    //To draw X and Y axis

    glColor3d(1, 0, 0);

    glBegin(GL_LINES);

    glVertex2f(-2, 0);
    glVertex2f(2, 0);

    glVertex2f(0, -2);
    glVertex2f(0, 2);

    glEnd();
    glFlush();
}

void initializeDisplay() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    //Apply the transformations & drawing on the model view matrix
    glMatrixMode(GL_MODELVIEW);

    //Draw the X and Y axis
    drawAxes();

    //Transform only the drawn object, so use the matrix stack accordingly
    glPushMatrix();

    if (isOrtho) {
        //Parallel Projection
        glOrtho(-2, 2, -2, 2, -2, 2);
    }
    else {
        //Perspective Projection
        gluPerspective(120, 1, 0.5, 50);//FoVy = 120, Aspect Ratio = 1
    }

    gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);  //Camera, Center & Up Vector
    glRotatef(x_rotate, 1, 0, 0);         //Keyboard based rotations
    glRotatef(y_rotate, 0, 1, 0);

    glColor4f(0, 0, 1, 0.3); //Draw the object
    glutWireTeapot(0.5);
    glPopMatrix();
    glFlush();
}

void keyboardKeys(unsigned char key, int x, int y)
{
    //Callback function for keyboard interactivity
    key = tolower(key);
    switch (key)
    {
    case 'u':
    {
        x_rotate += 5;
        break;
    }
    case 'd':
    {
        x_rotate -= 5;
        break;
    }
    case 'r':
    {
        y_rotate += 5;
        break;
    }
    case 'l':
    {
        y_rotate -= 5;
        break;
    }
    case 32:
    {
        //Spacebar for changing projections
        isOrtho = !isOrtho;
        break;
    }
    }

    //Update the display
    glutPostRedisplay();
}

int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 500);
    glutCreateWindow("3D Projections");

    //Register the callback functions
    glutDisplayFunc(initializeDisplay);
    glutKeyboardFunc(keyboardKeys);

    //Change to projection mode before applying glOrtho()/gluPerspective()
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glutMainLoop();

    return 0;
}
