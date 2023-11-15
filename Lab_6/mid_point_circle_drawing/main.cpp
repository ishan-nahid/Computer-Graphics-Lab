#include<windows.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

int r;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);

	gluOrtho2D(-400.0, 400.0, -400.0, 400.0);
}

void drawShapes(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	int x = 0, y = r;

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
        int p = 1-r;

        while(x <= y)
        {
            if(p < 0)
            {
                x++;

                p = p + (2*x) + 1;
            }
            else
            {
                x++;
                y--;

                p = p+(2*x)-(2*y);
            }
            glVertex2f(x,y);
            glVertex2f(y,x);
            glVertex2f(-x,-y);
            glVertex2f(-x,y);
            glVertex2f(x,-y);
            glVertex2f(y,-x);
            glVertex2f(-y,-x);
            glVertex2f(-y,x);
        }
	glEnd();

glFlush();

}
int main(int argc, char* argv[])
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowPosition(1200, 100);
	glutInitWindowSize(900, 900);
	glutCreateWindow("Mid Point Circle Drawing Algorithm");

	init();
	glutDisplayFunc(drawShapes);

    cout << "Enter Radious " << endl;

	cout << "r: ";
	cin >> r;

	glutMainLoop();

	return 0;
}

