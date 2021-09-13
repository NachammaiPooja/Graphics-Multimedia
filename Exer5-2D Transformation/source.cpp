//5b- Reflection, Shearing

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <gl/glut.h>
using namespace std;

int pntx1, pnty1, choice = 0, edges;
vector<int> pntx;
vector<int> pnty;
int transx, transy;
double scalex, scaley;
double angle, anglerad;
char reflectionaxis, shearingaxis;
int shearingx, shearingy;

double round(double d)
{
	return floor(d + 0.5);
}

void drawPolygon()
{
	glBegin(GL_POLYGON);
	glColor3f(0.4, 0, 0.2);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(pntx[i], pnty[i]);
	}
	glEnd();
}

void reflection(char reflectionaxis)
{
	glBegin(GL_POLYGON);
	glColor3f(6.08, 0.67, 1.0);

	if (reflectionaxis == 'x' || reflectionaxis == 'X')
	{
		for (int i = 0; i < edges; i++)
		{
			glVertex2i(round(pntx[i]), round(pnty[i] * -1));

		}
	}
	else if (reflectionaxis == 'y' || reflectionaxis == 'Y')
	{
		for (int i = 0; i < edges; i++)
		{
			glVertex2i(round(pntx[i] * -1), round(pnty[i]));
		}
	}
	else if (reflectionaxis == 'o' || reflectionaxis == 'O')
	{
		for (int i = 0; i < edges; i++)
		{
			glVertex2i(round(pntx[i] * -1), round(pnty[i] * -1));
		}
	}
	else if (reflectionaxis == 's' || reflectionaxis == 'S')
	{
		for (int i = 0; i < edges; i++)
		{
			glVertex2i(round(pnty[i]+100), round(pntx[i]));
		}
	}
	glEnd();
}

void shearing()
{
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.4, 0.7);

	if (shearingaxis == 'x' || shearingaxis == 'X')
	{
		glVertex2i(pntx[0]+200, pnty[0]);

		glVertex2i(pntx[1] + shearingx+200, pnty[1]);
		glVertex2i(pntx[2] + shearingx+200, pnty[2]);

		glVertex2i(pntx[3]+200, pnty[3]);
	}
	else if (shearingaxis == 'y' || shearingaxis == 'Y')
	{
		glVertex2i(pntx[0]+200, pnty[0]);
		glVertex2i(pntx[1]+200, pnty[1]);

		glVertex2i(pntx[2]+200, pnty[2] + shearingy);
		glVertex2i(pntx[3]+200, pnty[3] + shearingy);
	}
	glEnd();
}

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}

void myDisplay(void)
{
	while (true) {
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0.0, 0.0, 0.0);
		drawPolygon();

		glBegin(GL_LINES);
		glVertex2d(-640, 0);
		glVertex2d(640, 0);
		glVertex2d(0, 480);
		glVertex2d(0, -480);
		glEnd();

		cout << "\nSelect the required transformation:\n";
		cout << "1. Reflection\n";
		cout << "2. Shearing\n";
		cout << "3. Exit\n";
		cout << "Enter your choice : ";
		
		cin >> choice;

		if (choice == 3) {
			return;
		}
		if (choice == 1)
		{
			cout << "Enter reflection axis ( x / y / origin(O) / same(s)): "; cin >> reflectionaxis;
			reflection(reflectionaxis);
		}
		else if (choice == 2)
		{ 
			cout << "Enter shearing axis ( x or y ): "; cin >> shearingaxis;
			if (shearingaxis == 'x' || shearingaxis == 'X')
			{
				cout << "Enter the shearing factor for X: "; cin >> shearingx;
				shearing();
			}
			else if (shearingaxis == 'y' || shearingaxis == 'Y')
			{
				cout << "Enter the shearing factor for Y: "; cin >> shearingy;
				shearing();
			}
		}
		glFlush();
	}
}

void main(int argc, char** argv)
{
	cout << "\n2D-Transformations\n" << endl;
	cout << "Enter no of edges: "; cin >> edges;
	cout << "\nEnter Polygon Coordinates : \n";

	for (int i = 0; i < edges; i++) {
		cout << "Vertex  " << i + 1 << " : "; cin >> pntx1 >> pnty1;
		pntx.push_back(pntx1);
		pnty.push_back(pnty1);
	}
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("2D-Transformations");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}

//
////5A-Translation,Scaling,Rotation
//#include <stdio.h>
//#include <math.h>
//#include <iostream>
//#include <vector>
//#include <GL/glut.h>
//using namespace std;
//
//int pntX1, pntY1, op = 0, edges;
//vector<int> pntX;
//vector<int> pntY;
//int transX, transY, lineX1, lineX2, lineY1, lineY2;
//double scaleX, scaleY;
//double angle, angleRad;
//char reflectionAxis, shearingAxis;
//int shearingX, shearingY;
//
//double round(double d)
//{
//	return floor(d + 0.5);
//}
//
//void drawPolygon()
//{
//	glBegin(GL_POLYGON);
//	glColor3f(0.4, 0, 0.2);
//	for (int i = 0; i < edges; i++)
//	{
//		glVertex2i(pntX[i], pntY[i]);
//	}
//	glEnd();
//
//	glBegin(GL_LINES);
//	glVertex2d(lineX1, lineY1);
//	glVertex2d(lineX2, lineY2);
//	glEnd();
//}
//
//
//void translate(int x, int y)
//{
//	glBegin(GL_POLYGON);
//	glColor3f(0.08, 4.67, 0.23);
//	for (int i = 0; i < edges; i++)
//	{
//		glVertex2i(pntX[i] + x, pntY[i] + y);
//	}
//	glEnd();
//	glBegin(GL_LINES);
//	glVertex2d(lineX1 + x, lineY1 + y);
//	glVertex2d(lineX2 + x, lineY2 + y);
//	glEnd();
//}
//
//void scale(double x, double y)
//{
//	glBegin(GL_POLYGON);
//	glColor3f(0.3, 0.4, 0.7);
//	for (int i = 0; i < edges; i++)
//	{
//		glVertex2i(round(pntX[i] * x) + 300, round(pntY[i] * y));
//	}
//	glEnd();
//	glBegin(GL_LINES);
//	glVertex2d(round(lineX1 * x), round(lineY1 * y));
//	glVertex2d(round(lineX2 * x), round(lineY2 * y));
//	//glVertex2d(round((lineX1 * x)+ 60), round((lineY1 * y)+10));
//	//glVertex2d(round((lineX2 * x)-10), round((lineY2 * y)-10));
//	glEnd();
//}
//
//void rotate(double theta)
//{
//	glBegin(GL_POLYGON);
//	glColor3f(9.08, 0.67, 2);
//	for (int i = 0; i < edges; i++)
//	{
//		glVertex2i(round((pntX[i] * cos(theta)) - (pntY[i] * sin(theta))), round((pntX[i] * sin(theta)) + (pntY[i] * cos(theta))));
//	}
//	glEnd();
//
//	glBegin(GL_LINES);
//	glVertex2d(round((lineX1 * cos(theta)) - (lineY1 * sin(theta))), round((lineX1 * sin(theta)) + (lineY1 * cos(theta))));
//	glVertex2d(round((lineX2 * cos(theta)) - (lineY2 * sin(theta))), round((lineX2 * sin(theta)) + (lineY2 * cos(theta))));
//	glEnd();
//}
//
//void MirrorReflection(char reflectionAxis)
//{
//	glBegin(GL_POLYGON);
//	glColor3f(9.08, 0.67, 1.0);
//
//	if (reflectionAxis == 'x' || reflectionAxis == 'X')
//	{
//		for (int i = 0; i < edges; i++)
//		{
//			glVertex2i(round(pntX[i]), round(pntY[i] * -1));
//
//		}
//	}
//	else if (reflectionAxis == 'y' || reflectionAxis == 'Y')
//	{
//		for (int i = 0; i < edges; i++)
//		{
//			glVertex2i(round(pntX[i] * -1), round(pntY[i]));
//		}
//	}
//	else if (reflectionAxis == 'O' || reflectionAxis == 'o')
//	{
//		for (int i = 0; i < edges; i++)
//		{
//			glVertex2i(round(pntX[i] * -1), round(pntY[i] * -1));
//		}
//	}
//	else if (reflectionAxis == 'S' || reflectionAxis == 's')
//	{
//		for (int i = 0; i < edges; i++)
//		{
//			glVertex2i(round(pntY[i]), round(pntX[i]-10));
//		}
//	}
//	glEnd();
//}
//
//void Polyshearing()
//{
//	glBegin(GL_POLYGON);
//	glColor3f(0.0, 0.0, 1.0);
//
//	if (shearingAxis == 'x' || shearingAxis == 'X')
//	{
//		glVertex2i(pntX[0], pntY[0]);
//
//		glVertex2i(pntX[1] + shearingX, pntY[1]);
//		glVertex2i(pntX[2] + shearingX, pntY[2]);
//
//		glVertex2i(pntX[3], pntY[3]);
//	}
//	else if (shearingAxis == 'y' || shearingAxis == 'Y')
//	{
//		glVertex2i(pntX[0], pntY[0]);
//		glVertex2i(pntX[1], pntY[1]);
//
//		glVertex2i(pntX[2], pntY[2] + shearingY);
//		glVertex2i(pntX[3], pntY[3] + shearingY);
//	}
//	glEnd();
//}
//
//void myInit(void)
//{
//	glClearColor(1.0, 1.0, 1.0, 0.0);
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glPointSize(4.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
//}
//
//void myDisplay(void)
//{
//	while (true) {
//		glClear(GL_COLOR_BUFFER_BIT);
//		glColor3f(0.0, 0.0, 0.0);
//		drawPolygon();
//		cout << "\nSelect the required transformation:\n";
//		cout << "1. Translation\n";
//		cout << "2. Scaling\n";
//		cout << "3. Rotation\n";
//		//cout << "4. Mirror Reflection\n";
//		//cout << "5. Shearing\n";
//		cout << "4. Exit\n";
//		cout << "Enter your choice : ";
//
//		cin >> op;
//
//		if (op == 4) {
//			break;
//		}
//
//		if (op == 1)
//		{
//			cout << "Enter the translation factor for X and Y: "; cin >> transX >> transY;
//			translate(transX, transY);
//		}
//		else if (op == 2)
//		{
//			cout << "Enter the scaling factor for X and Y: "; cin >> scaleX >> scaleY;
//			scale(scaleX, scaleY);
//		}
//		else if (op == 3)
//		{
//			cout << "Enter the angle for rotation: "; cin >> angle;
//			angleRad = angle * 3.1416 / 180;
//			rotate(angleRad);
//		}
//		//else if (op == 4)
//		//{
//		//	cout << "Enter reflection axis ( x / y / origin(O) / same(s)): "; cin >> reflectionAxis;
//		//	MirrorReflection(reflectionAxis);
//		//}
//		//else if (op == 5)
//		//{
//		//	cout << "Enter shearing axis ( x or y ): "; cin >> shearingAxis;
//		//	if (shearingAxis == 'x' || shearingAxis == 'X')
//		//	{
//		//		cout << "Enter the shearing factor for X: "; cin >> shearingX;
//		//		glVertex2i(pntX[0], pntY[0]);
//
//		//		glVertex2i(pntX[1] + shearingX, pntY[1]);
//		//		glVertex2i(pntX[2] + shearingX, pntY[2]);
//
//		//		glVertex2i(pntX[3], pntY[3]);
//		//	}
//		//	else
//		//	{
//		//		cout << "Enter the shearing factor for Y: "; cin >> shearingY;
//		//		glVertex2i(pntX[0], pntY[0]);
//		//		glVertex2i(pntX[1], pntY[1]);
//
//		//		glVertex2i(pntX[2], pntY[2] + shearingY);
//		//		glVertex2i(pntX[3], pntY[3] + shearingY);
//		//	}
//		//	//Polyshearing();
//		//}
//
//		glFlush();
//	}
//
//}
//
//int main(int argc, char** argv)
//{
//	cout << "\n2D-Transformations\n" << endl;
//	cout << "\ni)Polygon:\n" << endl;
//	cout << "Enter no of edges: "; cin >> edges;
//	cout << "\nEnter Polygon Coordinates : \n";
//
//	for (int i = 0; i < edges; i++) {
//		cout << "Vertex  " << i + 1 << " : "; cin >> pntX1 >> pntY1;
//		pntX.push_back(pntX1);
//		pntY.push_back(pntY1);
//	}
//
//	cout << "\nii)Line:\n" << endl;
//	cout << "\nEnter Line Coordinates : \n";
//	cout << "Point 1 : "; cin >> lineX1 >> lineY1;
//	cout << "Point 2 : "; cin >> lineX2 >> lineY2;
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(640, 480);
//	glutInitWindowPosition(100, 150);
//	glutCreateWindow("2D-Transformations");
//	glutDisplayFunc(myDisplay);
//	myInit();
//	glutMainLoop();
//
//}
//

