#include<windows.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

int ax, ay, bx, by, cx, cy, dx, dy, sx, sy;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);

	gluOrtho2D(-300.0, 300.0, -300.0, 300.0);
}

void drawShapes(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
        glVertex2i(ax*sx, ay*sy);
        glVertex2i(bx*sx, by*sy);
        glVertex2i(cx*sx, cy*sy);
        glVertex2i(dx*sx, dy*sy);
    glEnd();

    glColor3f(1, 0, 0);
	glBegin(GL_QUADS);
        glVertex2i(ax, ay);
        glVertex2i(bx, by);
        glVertex2i(cx, cy);
        glVertex2i(dx, dy);
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


	cout << "Enter scalling constants " << endl;
	cout << "sx ";
	cin >> sx;
	cout << endl;

	cout << "sy ";
	cin >> sy;
	cout << endl;


	glutMainLoop();

	return 0;
}

