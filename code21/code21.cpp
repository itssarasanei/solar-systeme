#include <GL/glut.h>
#include <corecrt_math.h>
#define PI 3.14159
float angle = 0.0;
float angle1 = 0.0;
float angle2 = 0.0;
float angle3 = 0.0;
float angle4 = 0.0;
float angle5 = 0.0;
static float Xangle = 150.0, Yangle = 150.0, Zangle = 0.0; //Angles to rotate the torus.
float camrot[2] = { 0.0, 0.0 };
float distance = 30.0;

void drawOrbit(float radius) {
    const int numSegments = 100;
    const float angleStep = 2.0 * 3.14159 / numSegments;


    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; ++i) {
        float theta = i * angleStep;
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        glVertex3f(x, y, 0.0);
    }
    glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    float pos[3];
    pos[2] = distance * cos(camrot[0]) * cos(camrot[1]);
    pos[0] = distance * sin(camrot[0]) * cos(camrot[1]);
    pos[1] = distance * sin(camrot[1]);

    gluLookAt(pos[0], pos[1], pos[2],
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0);

    // ??? ??????
    glColor3f(255, 192, 203); // ??? ???
    glutWireSphere(1.2, 20, 20);

    // ??? ??????
    glPushMatrix();
    glColor3f(75.0, 0.0, 130.0); // ??? ???
    drawOrbit(3.0);
    glRotatef(angle, 0.0, 0.0, 1.0); // ???? ????? ??? (????)
    glTranslatef(3.0, 0.0, 0.0);
    glutWireSphere(0.4, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(255, 192, 203); // ??? ?????????
    drawOrbit(5.0);
    glRotatef(angle1, 0.0, 0.0, 1.0); // ???? ????? ??? (????)
    glTranslatef(5.0, 0.0, 0.0);
    glutWireSphere(0.6, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(75.0, 0.0, 130.0); // ??? ????
    drawOrbit(7.0);
    glRotatef(angle2, 0.0, 0.0, 1.0); // ???? ????? ??? (????)
    glTranslatef(7.0, 0.0, 0.0);
    glutWireSphere(0.7, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(255, 192, 203); // ??? ???
    drawOrbit(9.0);
    glRotatef(angle3, 0.0, 0.0, 1.0); // ???? ????? ???? (??????)
    glTranslatef(9.0, 0.0, 0.0);
    glutWireSphere(0.8, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(75.0, 0.0, 130.0); // ??? ???
    drawOrbit(12.0);
    glRotatef(angle4, 0.0, 0.0, 1.0); // ???? ????? ???? (??????)
    glTranslatef(12.0, 0.0, 0.0);
    glutWireSphere(1.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(255, 192, 203); // ??? ???
    drawOrbit(15.0);
    glRotatef(angle5, 0.0, 0.0, 1.0); // ???? ????? ???? (??????)
    glTranslatef(15.0, 0.0, 0.0);
    glutWireSphere(1.1, 20, 20);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)width / (float)height, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void idle() {
    angle += 0.065; // ????? ???? ??????
    angle1 += 0.05;
    angle2 += 0.07;
    angle3 += 0.06;
    angle4 += 0.03;
    angle5 += 0.025;

    glutPostRedisplay();
}
void keyboard(unsigned char k, int x, int y)
{
    switch (k)
    {
    case 'a':
        camrot[0] += 0.1;
        break;
    case 'd':
        camrot[0] -= 0.1;
        break;
    case 'q':
        distance += 0.1;
        break;
    case 'e':
        distance -= 0.1;
        break;
    case 's':
        if (camrot[1] < PI / 2 - 0.1)
            camrot[1] += 0.1;
        break;
    case 'w':
        if (camrot[1] > -PI / 2 + 0.1)
            camrot[1] -= 0.1;
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Solar System Simulation");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}