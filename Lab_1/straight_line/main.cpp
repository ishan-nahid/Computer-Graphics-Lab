#include<windows.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

int x1, y1, x2, y2;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);

	gluOrtho2D(0.0, 700.0, 0.0, 700.0);
}

void drawShapes(void)
{
	glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(1, 0, 0);
	glBegin(GL_QUADS);
        glVertex2i(100, 100);
        glVertex2i(100, 200);
        glVertex2i(200, 200);
        glVertex2i(200, 100);
    glEnd();

glFlush();

}
int main(int argc, char* argv[])
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowPosition(1200, 100);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Lab Evaluation 2");

	init();
	glutDisplayFunc(drawShapes);


	glutMainLoop();

	return 0;
}

