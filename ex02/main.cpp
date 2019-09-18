

/* -- INCLUDE FILES ------------------------------------------------------ */
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>


static GLfloat spin = 0.0;
static GLint myCount = 0;
void myInit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}
void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(spin, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glRectf(0.0, 0.0, 25.0, 25.0);
    glPopMatrix();
    glutSwapBuffers();
}
void myReshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void myDisplayYellow() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    glRectf(0.0, 0.0, 25.0, 25.0);
    glutSwapBuffers();

}
void spinDisplay(void)
{
    spin = spin + 2.0;
    if (spin > 360.0)
    spin = spin - 360.0;
    glutPostRedisplay();
}
void changeColor() {

    if(myCount == 0) myDisplay();
    else myDisplayYellow();
}
void myMouse(int button, int state, int x, int y) {
    switch (button) {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            myCount = (++myCount)%2;
            glutIdleFunc(changeColor);
        }

    break;
    case GLUT_MIDDLE_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
    break;
    case GLUT_RIGHT_BUTTON:
        if(state == GLUT_DOWN)
            glutIdleFunc(spinDisplay);
    break;
    }
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("spinning rectangle");
    myInit();
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(myReshape);
    glutMouseFunc(myMouse);
    glutMainLoop();
return 0;
}
/* ----------------------------------------------------------------------- */

