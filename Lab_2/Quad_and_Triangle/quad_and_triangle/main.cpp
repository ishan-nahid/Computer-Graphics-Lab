#include<windows.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);

	gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}

void drawShapes(void)
{
	glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(1, 0, 0);
	glBegin(GL_QUADS);
        glVertex2i(70, 170);
        glVertex2i(160, 170);
        glVertex2i(190, 60);
        glVertex2i(50, 90);
    glEnd();

    glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLES);
        glVertex2i(330, 370);
        glVertex2i(270, 260);
        glVertex2i(180, 260);
    glEnd();

glFlush();

}
int main(int argc, char* argv[])
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowPosition(1200, 100);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Quad Shape and Triangle Shape");

	init();
	glutDisplayFunc(drawShapes);


	glutMainLoop();

	return 0;
}

