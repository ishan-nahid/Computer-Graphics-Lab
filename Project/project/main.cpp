#include<windows.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

float personX = 60.0;
float personY = 50.0;
float busX = 1490.0;
float carX = 10.0;
float cloud1X = 1500.0;
float cloud2X = 0.0;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);

	gluOrtho2D(0.0, 1500.0, 0.0, 1000.0);
}

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void greenField(void)
{
    glColor3f(0, 128, 0);
	glBegin(GL_QUADS);
        glVertex2i(0, 0);
        glVertex2i(0, 200);
        glVertex2i(1500, 200);
        glVertex2i(1500, 0);
    glEnd();
}

void crossingZone(void)
{
    glColor3f(240/255.0, 210/255.0, 158/255.0);
    glBegin(GL_QUADS);
        glVertex2i(630, 155);
        glVertex2i(630, 205);
        glVertex2i(770, 205);
        glVertex2i(770, 155);
    glEnd();
}

void road(void)
{
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
        glVertex2i(0, 200);
        glVertex2i(0, 500);
        glVertex2i(1500, 500);
        glVertex2i(1500, 200);
    glEnd();

    int gap = 50;
    int x1 = 3, x2 = x1+40;
    for(int i = 0; i <= 30; i++)
    {
        glColor3f(255, 255, 255);
        glBegin(GL_QUADS);
            glVertex2i(x1, 350);
            glVertex2i(x1, 360);
            glVertex2i(x2, 360);
            glVertex2i(x2, 350);
        glEnd();

        x1 += gap;
        x2 = x1+40;
    }
}

void crossing(void)
{

    int gap = 20;
    int y1 = 205, y2 = y1+10;
    for(int i = 0; i < 15; i++)
    {
        glColor3f(255, 255, 255);
        glBegin(GL_QUADS);
            glVertex2i(650, y1);
            glVertex2i(650, y2);
            glVertex2i(750, y2);
            glVertex2i(750, y1);
        glEnd();

        y1 += gap;
        y2 = y1+10;
    }
}

void background(void)
{
    glColor3f(10/255.0, 251/255.0, 255/255.0);
	glBegin(GL_QUADS);
        glVertex2i(0, 500);
        glVertex2i(0, 1000);
        glVertex2i(1500, 1000);
        glVertex2i(1500, 500);
    glEnd();
}

void upperBlank(void)
{
    glColor3f(209 / 255.0, 102 / 255.0, 31 / 255.0);
	glBegin(GL_QUADS);
        glVertex2i(0, 500);
        glVertex2i(0, 520);
        glVertex2i(1500, 520);
        glVertex2i(1500, 500);
    glEnd();
}

void sun(void)
{
    glColor3f(251/255.0, 255/255.0, 0);
    circle(75, 75, 215, 875);
}

void bus(void)
{
    if((personX >= 600 && personX <= 700) && (personY >= 90 && personY <= 480))
    {
        // body
        glColor3f(255 / 255.0, 0, 0);
        glBegin(GL_QUADS);
            glVertex2i(busX, 470);
            glVertex2i(busX, 370);
            glVertex2i(busX - 160, 370);
            glVertex2i(busX - 160, 470);
        glEnd();

        // chakka shamnerta
        glColor3f(173 / 255.0, 196 / 255.0, 188 / 255.0);
        circle(10, 10, busX - 90, 370);

        // chakka pichonerta
        glColor3f(173 / 255.0, 196 / 255.0, 188 / 255.0);
        circle(10, 10, busX - 30, 370);

        // dorja
        glColor3f(0, 0, 0);
        glBegin(GL_QUADS);
            glVertex2i(busX - 150, 372);
            glVertex2i(busX - 150, 450);
            glVertex2i(busX - 110, 450);
            glVertex2i(busX - 110, 372);
        glEnd();

        // mid line
        glColor3f(0, 0, 0);
        glBegin(GL_QUADS);
            glVertex2i(busX - 105, 400);
            glVertex2i(busX - 105, 410);
            glVertex2i(busX-3, 410);
            glVertex2i(busX-3, 400);
        glEnd();

        // first window
        glColor3f(10/255.0, 251/255.0, 255/255.0);
        glBegin(GL_QUADS);
            glVertex2i(busX - 100, 415);
            glVertex2i(busX - 100, 455);
            glVertex2i(busX - 60, 455);
            glVertex2i(busX - 60, 415);
        glEnd();

        // second window
        glColor3f(10/255.0, 251/255.0, 255/255.0);
        glBegin(GL_QUADS);
            glVertex2i(busX - 50, 415);
            glVertex2i(busX - 50, 455);
            glVertex2i(busX - 10, 455);
            glVertex2i(busX - 10, 415);
        glEnd();

    }
    else
    {
        busX -= 0.8;

        glPushMatrix();
        // body
        glColor3f(255 / 255.0, 0, 0);
        glBegin(GL_QUADS);
            glVertex2i(busX, 470);
            glVertex2i(busX, 370);
            glVertex2i(busX - 160, 370);
            glVertex2i(busX - 160, 470);
        glEnd();

        // chakka shamnerta
        glColor3f(173 / 255.0, 196 / 255.0, 188 / 255.0);
        circle(10, 10, busX - 90, 370);

        // chakka pichonerta
        glColor3f(173 / 255.0, 196 / 255.0, 188 / 255.0);
        circle(10, 10, busX - 30, 370);

        // dorja
        glColor3f(0, 0, 0);
        glBegin(GL_QUADS);
            glVertex2i(busX - 150, 372);
            glVertex2i(busX - 150, 450);
            glVertex2i(busX - 110, 450);
            glVertex2i(busX - 110, 372);
        glEnd();

        // mid line
        glColor3f(0, 0, 0);
        glBegin(GL_QUADS);
            glVertex2i(busX - 105, 400);
            glVertex2i(busX - 105, 410);
            glVertex2i(busX-3, 410);
            glVertex2i(busX-3, 400);
        glEnd();

        // first window
        glColor3f(10/255.0, 251/255.0, 255/255.0);
        glBegin(GL_QUADS);
            glVertex2i(busX - 100, 415);
            glVertex2i(busX - 100, 455);
            glVertex2i(busX - 60, 455);
            glVertex2i(busX - 60, 415);
        glEnd();

        // second window
        glColor3f(10/255.0, 251/255.0, 255/255.0);
        glBegin(GL_QUADS);
            glVertex2i(busX - 50, 415);
            glVertex2i(busX - 50, 455);
            glVertex2i(busX - 10, 455);
            glVertex2i(busX - 10, 415);
        glEnd();

        glPopMatrix();

        if(busX > 1)
            glutPostRedisplay();
        else
            busX = 1490.0;
            glutPostRedisplay();
    }
}

void car(void)
{
    if((personX >= 600 && personX <= 700) && (personY >= 90 && personY <= 480))
    {

        // body - lower part
        glColor3f(150 / 255.0, 90 / 255.0, 230 / 255.0);
        glBegin(GL_POLYGON);
            glVertex2i(carX, 220);
            glVertex2i(carX, 250);
            glVertex2i(carX + 120, 250);
            glVertex2i(carX + 160, 240);
            glVertex2i(carX + 160, 220);
        glEnd();

        // body - upper part
        glColor3f(150 / 255.0, 90 / 255.0, 230 / 255.0);
        glBegin(GL_QUADS);
            glVertex2i(carX + 40, 250);
            glVertex2i(carX + 40, 280);
            glVertex2i(carX + 120, 280);
            glVertex2i(carX + 120, 250);
        glEnd();

        // chakka picherta
        glColor3f(173 / 255.0, 196 / 255.0, 188 / 255.0);
        circle(10, 10, carX + 40, 220);

        // chakka shamnerta
        glColor3f(173 / 255.0, 196 / 255.0, 188 / 255.0);
        circle(10, 10, carX + 120, 220);

        // second window
        glColor3f(10 / 255.0, 251 / 255.0, 255 / 255.0);
        glBegin(GL_QUADS);
            glVertex2i(carX + 50, 250);
            glVertex2i(carX + 50, 275);
            glVertex2i(carX + 80, 275);
            glVertex2i(carX + 80, 250);
        glEnd();

        // first window
        glColor3f(10 / 255.0, 251 / 255.0, 255 / 255.0);
        glBegin(GL_QUADS);
            glVertex2i(carX + 90, 250);
            glVertex2i(carX + 90, 275);
            glVertex2i(carX + 120, 275);
            glVertex2i(carX + 120, 250);
        glEnd();

    }
    else
    {
        carX += 1.0;

        glPushMatrix();

        // body - lower part
        glColor3f(150 / 255.0, 90 / 255.0, 230 / 255.0);
        glBegin(GL_POLYGON);
            glVertex2i(carX, 220);
            glVertex2i(carX, 250);
            glVertex2i(carX + 120, 250);
            glVertex2i(carX + 160, 240);
            glVertex2i(carX + 160, 220);
        glEnd();

        // body - upper part
        glColor3f(150 / 255.0, 90 / 255.0, 230 / 255.0);
        glBegin(GL_QUADS);
            glVertex2i(carX + 40, 250);
            glVertex2i(carX + 40, 280);
            glVertex2i(carX + 120, 280);
            glVertex2i(carX + 120, 250);
        glEnd();

        // chakka picherta
        glColor3f(173 / 255.0, 196 / 255.0, 188 / 255.0);
        circle(10, 10, carX + 40, 220);

        // chakka shamnerta
        glColor3f(173 / 255.0, 196 / 255.0, 188 / 255.0);
        circle(10, 10, carX + 120, 220);

        // second window
        glColor3f(10 / 255.0, 251 / 255.0, 255 / 255.0);
        glBegin(GL_QUADS);
            glVertex2i(carX + 50, 250);
            glVertex2i(carX + 50, 275);
            glVertex2i(carX + 80, 275);
            glVertex2i(carX + 80, 250);
        glEnd();

        // first window
        glColor3f(10 / 255.0, 251 / 255.0, 255 / 255.0);
        glBegin(GL_QUADS);
            glVertex2i(carX + 90, 250);
            glVertex2i(carX + 90, 275);
            glVertex2i(carX + 120, 275);
            glVertex2i(carX + 120, 250);
        glEnd();

        glPopMatrix();

        if(carX < 1500)
            glutPostRedisplay();
        else
            carX = 10.0;
            glutPostRedisplay();
    }
}

void handleKeypress(unsigned char key, int x, int y) {
    const float moveDistance = 5.0;  // You can adjust the movement distance

    switch (key) {
        case 'w':
            personY += moveDistance;  // Move upwards
            break;
        case 's':
            personY -= moveDistance;  // Move downwards
            break;
        case 'd':
            personX += moveDistance;  // Move right
            break;
        case 'a':
            personX -= moveDistance;  // Move left
            break;
        default:
            break;
    }

    glutPostRedisplay();  // Trigger a redraw
}

void person(void)
{
    // leg one
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(40 + personX, 20 + personY);
        glVertex2f(40 + personX, 22 + personY);
        glVertex2f(45 + personX, 22 + personY);
        glVertex2f(45 + personX, 20 + personY);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(43 + personX, 20 + personY);
        glVertex2f(43 + personX, 30 + personY);
        glVertex2f(45 + personX, 30 + personY);
        glVertex2f(45 + personX, 20 + personY);
    glEnd();

    // leg two
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(70 + personX, 20 + personY);
        glVertex2f(70 + personX, 22 + personY);
        glVertex2f(75 + personX, 22 + personY);
        glVertex2f(75 + personX, 20 + personY);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(73 + personX, 20 + personY);
        glVertex2f(73 + personX, 30 + personY);
        glVertex2f(75 + personX, 30 + personY);
        glVertex2f(75 + personX, 20 + personY);
    glEnd();

    // body
    glColor3f(232/255.0, 146/255.0, 149/255.0);
    glBegin(GL_QUADS);
        glVertex2f(35 + personX, 30 + personY);
        glVertex2f(35 + personX, 80 + personY);
        glVertex2f(85 + personX, 80 + personY);
        glVertex2f(85 + personX, 30 + personY);
    glEnd();

    // hand one
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(30 + personX, 73 + personY);
        glVertex2f(30 + personX, 75 + personY);
        glVertex2f(35 + personX, 75 + personY);
        glVertex2f(35 + personX, 73 + personY);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(30 + personX, 53 + personY);
        glVertex2f(30 + personX, 73 + personY);
        glVertex2f(32 + personX, 75 + personY);
        glVertex2f(32 + personX, 53 + personY);
    glEnd();

    // hand two
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(85 + personX, 73 + personY);
        glVertex2f(85 + personX, 75 + personY);
        glVertex2f(90 + personX, 75 + personY);
        glVertex2f(90 + personX, 73 + personY);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(90 + personX, 53 + personY);
        glVertex2f(90 + personX, 73 + personY);
        glVertex2f(92 + personX, 75 + personY);
        glVertex2f(92 + personX, 53 + personY);
    glEnd();

    // face
    glColor3f(255, 255, 255);
    circle(20, 20, 60 + personX, 90 + personY);
}

void clouds(void)
{
    glPushMatrix();
    glColor3f(1, 1, 1);
    circle(25, 35, cloud1X, 880);
    circle(25, 35, cloud1X + 35, 860);
    circle(25, 35, cloud1X + 60, 850);
    circle(25, 35, cloud1X + 90, 850);
    circle(25, 35, cloud1X + 120, 870);
    circle(20, 30, cloud1X + 10, 900);
    circle(30, 35, cloud1X + 25, 920);
    circle(25, 35, cloud1X + 60, 930);
    circle(30, 35, cloud1X + 90, 920);
    circle(25, 35, cloud1X + 120, 920);
    circle(25, 30, cloud1X + 140, 900);
    circle(35, 30, cloud1X + 30, 900);
    circle(35, 30, cloud1X + 60, 900);

    cloud1X -= 0.5;

    glPopMatrix();

    if(cloud1X > 1)
        glutPostRedisplay();
    else
        cloud1X = 1500.0;
        glutPostRedisplay();

    glColor3f(1, 1, 1);
    circle(25, 35, cloud2X, 870);
    circle(25, 35, cloud2X + 35, 850);
    circle(25, 35, cloud2X + 60, 840);
    circle(25, 35, cloud2X + 90, 840);
    circle(25, 35, cloud2X + 120, 860);
    circle(20, 30, cloud2X + 10, 890);
    circle(30, 35, cloud2X + 25, 910);
    circle(25, 35, cloud2X + 60, 920);
    circle(30, 35, cloud2X + 90, 910);
    circle(25, 35, cloud2X + 120, 910);
    circle(25, 30, cloud2X + 140, 890);
    circle(35, 30, cloud2X + 30, 890);
    circle(35, 30, cloud2X + 60, 890);

    cloud2X += 0.5;

    glPopMatrix();

    if(cloud2X < 1500)
        glutPostRedisplay();
    else
        cloud2X = 0;
        glutPostRedisplay();
}

void flag(void)
{
    // base

    glColor3f(209 / 255.0, 102 / 255.0, 31 / 255.0);
	glBegin(GL_QUADS);
        glVertex2i(1000, 520);
        glVertex2i(1000, 530);
        glVertex2i(1050, 530);
        glVertex2i(1050, 520);
    glEnd();

    glColor3f(209 / 255.0, 102 / 255.0, 31 / 255.0);
	glBegin(GL_QUADS);
        glVertex2i(1010, 530);
        glVertex2i(1010, 540);
        glVertex2i(1040, 540);
        glVertex2i(1040, 530);
    glEnd();

    // stand

    glColor3f(209 / 255.0, 102 / 255.0, 31 / 255.0);
	glBegin(GL_QUADS);
        glVertex2i(1020, 540);
        glVertex2i(1020, 840);
        glVertex2i(1030, 840);
        glVertex2i(1030, 540);
    glEnd();

    circle(5, 5, 1025, 845);


    // main
    glColor3f(17/255.0, 92/255.0, 10/255.0);
	glBegin(GL_QUADS);
        glVertex2i(1030, 730);
        glVertex2i(1030, 830);
        glVertex2i(1230, 830);
        glVertex2i(1230, 730);
    glEnd();

    glColor3f(255, 0, 0);
    circle(25, 25, 1130, 780);


}

void school(void)
{
    // first base
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
        glVertex2i(450, 520);
        glVertex2i(450, 530);
        glVertex2i(950, 530);
        glVertex2i(950, 520);
    glEnd();

    // main back body
    glColor3f(204/255.0, 235/255.0, 70/255.0);
	glBegin(GL_QUADS);
        glVertex2i(460, 530);
        glVertex2i(460, 740);
        glVertex2i(940, 740);
        glVertex2i(940, 530);
    glEnd();

    // chad
    glColor3f(21/255.0, 134/255.0, 209/255.0);
	glBegin(GL_QUADS);
        glVertex2i(440, 740);
        glVertex2i(510, 820);
        glVertex2i(890, 820);
        glVertex2i(960, 740);
    glEnd();

    // main front body
    glColor3f(164/255.0, 196/255.0, 24/255.0);
	glBegin(GL_POLYGON);
    	glBegin(GL_POLYGON);
        glVertex2i(610, 530);
        glVertex2i(610, 800);
        glVertex2i(700, 850);
        glVertex2i(790, 800);
        glVertex2i(790, 530);
    glEnd();

    //clock
    glColor3f(0, 0, 0);
    circle(35,38, 690, 720);
    glColor3f(1, 1, 1);
    circle(32,35, 690, 720);

    //clock kata
    glColor3f(0, 0, 0);
    circle(3,4, 690, 720);

    //boro kata
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    	glBegin(GL_POLYGON);
        glVertex2i(690, 720);
        glVertex2i(692, 720);
        glVertex2i(692, 750);
        glVertex2i(690, 750);
    glEnd();
    //choto kata
    glColor3f(0, 0, 0);
    	glBegin(GL_POLYGON);
        glVertex2i(690, 720);
        glVertex2i(695, 720);
        glVertex2i(710, 730);
        glVertex2i(708, 730);
    glEnd();

    // dorja
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2i(665, 532);
        glVertex2i(665, 632);
        glVertex2i(729, 632);
        glVertex2i(729, 532);
        glVertex2i(669, 532);
    glEnd();
    glColor3f(255/255.0, 165/255.0, 0);
    glBegin(GL_POLYGON);
        glVertex2i(667, 530);
        glVertex2i(667, 630);
        glVertex2i(727, 630);
        glVertex2i(727, 530);
        glVertex2i(667, 530);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2i(699, 530);
        glVertex2i(699, 630);
        glVertex2i(701, 630);
        glVertex2i(701, 530);
        glVertex2i(667, 530);
    glEnd();

    glColor3f(0, 0, 0);
    circle(3, 4, 695, 580);
    circle(3, 4, 705, 580);


    // janala 1
    glColor3f(10/255.0, 251/255.0, 255/255.0);
	glBegin(GL_QUADS);
        glVertex2i(880, 710);
        glVertex2i(920, 710);
        glVertex2i(920, 660);
        glVertex2i(880, 660);
    glEnd();

    // janala 2
    glColor3f(10/255.0, 251/255.0, 255/255.0);
	glBegin(GL_QUADS);
        glVertex2i(820, 710);
        glVertex2i(860, 710);
        glVertex2i(860, 660);
        glVertex2i(820, 660);
    glEnd();

    // janala 3
    glColor3f(10/255.0, 251/255.0, 255/255.0);
    glBegin(GL_QUADS);
        glVertex2i(820, 630);
        glVertex2i(860, 630);
        glVertex2i(860, 580);
        glVertex2i(820, 580);
    glEnd();
    // janala 4
    glColor3f(10/255.0, 251/255.0, 255/255.0);
	glBegin(GL_QUADS);
        glVertex2i(880, 630);
        glVertex2i(920, 630);
        glVertex2i(920, 580);
        glVertex2i(880, 580);
    glEnd();




     // janala 1
    glColor3f(10/255.0, 251/255.0, 255/255.0);
	glBegin(GL_QUADS);
        glVertex2i(480, 710);
        glVertex2i(520, 710);
        glVertex2i(520, 660);
        glVertex2i(480, 660);
    glEnd();

    // janala 2
    glColor3f(10/255.0, 251/255.0, 255/255.0);
	glBegin(GL_QUADS);
        glVertex2i(540, 710);
        glVertex2i(580, 710);
        glVertex2i(580, 660);
        glVertex2i(540, 660);
    glEnd();

    // janala 3
    glColor3f(10/255.0, 251/255.0, 255/255.0);
    glBegin(GL_QUADS);
        glVertex2i(540, 630);
        glVertex2i(580, 630);
        glVertex2i(580, 580);
        glVertex2i(540, 580);
    glEnd();
    // janala 4
    glColor3f(10/255.0, 251/255.0, 255/255.0);
	glBegin(GL_QUADS);
        glVertex2i(480, 630);
        glVertex2i(520, 630);
        glVertex2i(520, 580);
        glVertex2i(480, 580);
    glEnd();

}

void drawShapes(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	// Green Field
	greenField();

    //crossingZone
	crossingZone();

	// road
	road();

	// crossing
	crossing();

	// background
	background();

	// upper blank
	upperBlank();

	// sun
	sun();

    // bus origin right
	bus();

	// car origin left
	car();

	// cloud
	clouds();

	// flag
	flag();

	// school
	school();

    // person
	person();


glFlush();

}

int main(int argc, char* argv[])
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowPosition(200, 0);
	glutInitWindowSize(1500, 1000);
	glutCreateWindow("Road Crossing Simulation");

	init();
	glutDisplayFunc(drawShapes);
	glutKeyboardFunc(handleKeypress);

	glutMainLoop();

	return 0;
}


// person static code
/*
void person2(void)
{
    // leg one
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2i(40, 20);
        glVertex2i(40, 22);
        glVertex2i(45, 22);
        glVertex2i(45, 20);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2i(43, 20);
        glVertex2i(43, 30);
        glVertex2i(45, 30);
        glVertex2i(45, 20);
    glEnd();

    // leg two
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2i(70, 20);
        glVertex2i(70, 22);
        glVertex2i(75, 22);
        glVertex2i(75, 20);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2i(73, 20);
        glVertex2i(73, 30);
        glVertex2i(75, 30);
        glVertex2i(75, 20);
    glEnd();

    // body

    glColor3f(232/255.0, 146/255.0, 149/255.0);
    glBegin(GL_QUADS);
        glVertex2i(35, 30);
        glVertex2i(35, 80);
        glVertex2i(85, 80);
        glVertex2i(85, 30);
    glEnd();

    // hand one
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
        glVertex2i(30, 73);
        glVertex2i(30, 75);
        glVertex2i(35, 75);
        glVertex2i(35, 73);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_QUADS);
        glVertex2i(30, 53);
        glVertex2i(30, 73);
        glVertex2i(32, 75);
        glVertex2i(32, 53);
    glEnd();

    // hand two
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
        glVertex2i(85, 73);
        glVertex2i(85, 75);
        glVertex2i(90, 75);
        glVertex2i(90, 73);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_QUADS);
        glVertex2i(90, 53);
        glVertex2i(90, 73);
        glVertex2i(92, 75);
        glVertex2i(92, 53);
    glEnd();

    // face
    glColor3f(255,255,255);
    circle(20, 20, 60, 90);
}
*/

// car static code
/*
void car2(void)
{
    // body - lower part
    glColor3f(150/255.0, 90/255.0, 230/255.0);
    glBegin(GL_POLYGON);
        glVertex2i(10, 220);
        glVertex2i(10, 250);
        glVertex2i(130, 250);
        glVertex2i(170, 240);
        glVertex2i(170, 220);
    glEnd();

    // body - upper part
    glColor3f(150/255.0, 90/255.0, 230/255.0);
    glBegin(GL_QUADS);
        glVertex2i(50, 250);
        glVertex2i(50, 280);
        glVertex2i(130, 280);
        glVertex2i(130, 250);
    glEnd();

    // chakka picherta
    glColor3f(173 / 255.0, 196 / 255.0, 188 / 255.0);
    circle(10, 10, 50, 220);

    // chakka shamnerta
    glColor3f(173 / 255.0, 196 / 255.0, 188 / 255.0);
    circle(10, 10, 130, 220);

    // second window
    glColor3f(10/255.0, 251/255.0, 255/255.0);
    glBegin(GL_QUADS);
        glVertex2i(60, 250);
        glVertex2i(60, 275);
        glVertex2i(90, 275);
        glVertex2i(90, 250);
    glEnd();

    // first window
    glColor3f(10/255.0, 251/255.0, 255/255.0);
    glBegin(GL_QUADS);
        glVertex2i(100, 250);
        glVertex2i(100, 275);
        glVertex2i(130, 275);
        glVertex2i(130, 250);
    glEnd();
}
*/
// bus static code
/*
void bus(void)
{
    // body
    glColor3f(255/255.0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2i(1490, 470);
        glVertex2i(1490, 370);
        glVertex2i(1330, 370);
        glVertex2i(1330, 470);
    glEnd();

    // chakka shamnerta
    glColor3f(173/255.0, 196/255.0, 188/255.0);
    circle(10,10, 1400, 370);

    // chakka pichonerta
    glColor3f(173/255.0, 196/255.0, 188/255.0);
    circle(10,10, 1460, 370);

    // dorja
    glColor3f(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2i(1340, 372);
        glVertex2i(1340, 450);
        glVertex2i(1380, 450);
        glVertex2i(1380, 372);
    glEnd();

    // mid line
    glColor3f(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2i(1380, 400);
        glVertex2i(1380, 410);
        glVertex2i(1490, 410);
        glVertex2i(1490, 400);
    glEnd();

    // first window
    glColor3f(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2i(1390, 415);
        glVertex2i(1390, 455);
        glVertex2i(1430, 455);
        glVertex2i(1430, 415);
    glEnd();

    // second window
    glColor3f(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2i(1440, 415);
        glVertex2i(1440, 455);
        glVertex2i(1480, 455);
        glVertex2i(1480, 415);
    glEnd();
}*/
// Define a global variable to store the X-coordinate of the bus
