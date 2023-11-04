#include<windows.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

int ax, ay, bx, by, cx, cy, dx, dy, theta;
#define PI acos(-1.0)

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);

	gluOrtho2D(-300.0, 300.0, -300.0, 300.0);
}

void drawShapes(void)
{
	glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(1, 0, 0);
	glBegin(GL_QUADS);
        glVertex2i(ax, ay);
        glVertex2i(bx, by);
        glVertex2i(cx, cy);
        glVertex2i(dx, dy);
    glEnd();

    double r = PI*(theta)/180.0;
    double aX, aY, bX, bY, cX, cY, dX, dY;
    aX = ax*cos(r) - ay*sin(r);
    aY = ax*sin(r) + ay*cos(r);
    bX = bx*cos(r) - by*sin(r);
    bY = bx*sin(r) + by*cos(r);
    cX = cx*cos(r) - cy*sin(r);
    cY = cx*sin(r) + cy*cos(r);
    dX = dx*cos(r) - dy*sin(r);
    dY = dx*sin(r) + dy*cos(r);

    glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
        glVertex2i(aX, aY);
        glVertex2i(bX, bY);
        glVertex2i(cX, cY);
        glVertex2i(dX, dY);
    glEnd();

glFlush();

}
int main(int argc, char* argv[])
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowPosition(1200, 100);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Translation");

	init();
	glutDisplayFunc(drawShapes);

	cout << "Enter value for first shape " << endl;
	cout << "ax ";
	cin >> ax;
	cout << endl;
	cout << "ay ";
	cin >> ay;
	cout << endl;

    cout << "bx ";
	cin >> bx;
	cout << endl;
	cout << "by ";
	cin >> by;
	cout << endl;

	cout << "cx ";
	cin >> cx;
	cout << endl;
	cout << "cy ";
	cin >> cy;
	cout << endl;

    cout << "dx ";
	cin >> dx;
	cout << endl;
	cout << "dy ";
	cin >> dy;
	cout << endl;


	cout << "Enter rotation constant " << endl;
	cout << "theta ";
	cin >> theta;
	cout << endl;



	glutMainLoop();

	return 0;
}

