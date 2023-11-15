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

	bool state = false;

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2i(40, 40);
        glVertex2i(40, 320);
        glVertex2i(320, 320);
        glVertex2i(320, 40);
    glEnd();

	int box_size = 40;

	for(int i = 1; i <= 8; i++)
    {
        state = !state;
        for(int j = 1; j <= 8; j++)
        {
            if(state) glColor3f(0.0, 0.0, 0.0);
            else glColor3f(1.0, 1.0, 1.0);

            glBegin(GL_QUADS);
                glVertex2i(i * box_size, j * box_size);
                glVertex2i((i+1) * box_size, j * box_size);
                glVertex2i((i+1) * box_size, (j+1) * box_size);
                glVertex2i(i * box_size, (j+1) * box_size);
            glEnd();

            state = !state;
        }
    }

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

