/*Bùi Thị Hoài Thu - Táo*/
/*16021424*/

/*Vẽ hình chữ nhật*/
 #include <gl/gl.h>
 #include <gl/glu.h>
 #include <gl/glut.h>
void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex3f(0.25, 0.25, 0);
    glVertex3f(0.75, 0.25, 0);
    glVertex3f(0.75, 0.75, 0);
    glVertex3f(0.25, 0.75, 0);
    glEnd();
    glFlush();
    glutSwapBuffers();
}
void myInit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 0.0);
    glPointSize(3.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Rectangle");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
 }
