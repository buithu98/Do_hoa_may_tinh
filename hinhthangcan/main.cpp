#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

void myInit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 0.0);
    glPointSize(3.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

}
void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex3f(-0.5, 0.0, 0.0);
    glVertex3f(0.5, 0.0, 0.0);
    glVertex3f(0.2, 0.4, 0.0);
    glVertex3f(-0.2, 0.4, 0.0);
    glEnd();
    glFlush();
    glutSwapBuffers();
}
int main(int argc, char** argv) {
    glutInit(& argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("hinhThangCan");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
