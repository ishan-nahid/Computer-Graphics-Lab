#include<windows.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);

	gluOrtho2D(0.0, 800.0, 0.0, 800.0);
}

void drawShapes(void)
{
	glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
        glVertex2i(220, 260);
        glVertex2i(120, 300);
        glVertex2i(220, 340);
        glVertex2i(260, 440);
        glVertex2i(300, 340);
        glVertex2i(400, 300);
        glVertex2i(300, 260);
        glVertex2i(260, 160);
        glVertex2i(220, 260);
    glEnd();

    glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
        glVertex2i(360, 400);
        glVertex2i(260, 440);
        glVertex2i(360, 480);
        glVertex2i(400, 580);
        glVertex2i(440, 480);
        glVertex2i(540, 450);
        glVertex2i(440, 400);
        glVertex2i(400, 300);
        glVertex2i(360, 400);
    glEnd();

    glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
        glVertex2i(360, 120);
        glVertex2i(260, 160);
        glVertex2i(360, 200);
        glVertex2i(400, 300);
        glVertex2i(440, 200);
        glVertex2i(540, 160);
        glVertex2i(440, 120);
        glVertex2i(400, 20);
        glVertex2i(360, 120);
    glEnd();

    glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
        glVertex2i(500, 260);
        glVertex2i(400, 300);
        glVertex2i(500, 340);
        glVertex2i(540, 450);
        glVertex2i(580, 340);
        glVertex2i(680, 300);
        glVertex2i(580, 260);
        glVertex2i(540, 160);
        glVertex2i(500, 260);
    glEnd();

glFlush();

}
int main(int argc, char* argv[])
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowPosition(1200, 100);
	glutInitWindowSize(900, 900);
	glutCreateWindow("Four Stars");

	init();
	glutDisplayFunc(drawShapes);


	glutMainLoop();

	return 0;
}

