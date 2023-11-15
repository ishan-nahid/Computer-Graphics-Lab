#include<windows.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

int x1, y1, x2, y2;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);

	gluOrtho2D(0.0, 800.0, 0.0, 800.0);
}

void drawShapes(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	int dx = x2 - x1;
	int dy = y2 - y1;

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
        int p = (2*dy) - dx;

        for(int i = x1, j = y1; i <= x2, j <= y2;)
        {
            if(p < 0)
            {
                i++;
                if(i > x2 || j > y2) break;

                glVertex2f(i, j);
                p = p + (2*dy);
            }
            else
            {
                i++;
                j++;

                if(i > x2 || j > y2) break;

                glVertex2f(i, j);

                p = p + (2*dy) - (2*dx);
            }
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
	glutCreateWindow("Bresenham Line drawing algorithm");

	init();
	glutDisplayFunc(drawShapes);

    cout << "Enter value of starting and end points " << endl;

	cout << "x1: ";
	cin >> x1;
	cout << endl;
	cout << "y1: ";
	cin >> y1;
	cout << endl;

	cout << "x2: ";
	cin >> x2;
	cout << endl;
	cout << "y2: ";
	cin >> y2;
	cout << endl;

	glutMainLoop();

	return 0;
}

