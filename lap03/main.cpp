/*Bùi Thị Hoài Thu - Táo*/
/*16021424*/
/*Tweening*/
// A la mang toa do cua ngoi nha
//B la mang toa do cua chu T

//#include <GL/gl.h>
//#include <GL/glu.h>

#include <windows.h>
#include <GL/glut.h> // gl.h and glu.h are already included in glut.h
float A[9][2]={{-20,10}, {-20,-20}, {-10,-20}, {-10,-10}, {10,-10}, {10,-20}, {20,-20}, {20,10}, {0,20}};;
float B[9][2]={{-20,10}, {-20,0}, {-10,0}, {-10,-20}, {10,-20}, {10,0}, {20,0}, {20,10}, {0,10}};
int numberOfPoint = 9;

void init() {
	// select clearing (background) color
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-50.0, 50.0, -50.0, 50.0);
}


float tweening(float a, float b, float t) {
	return (1-t)*a + t*b;
}

void drawTweening(float A[9][2], float B[9][2], int n, float t) {
	glBegin(GL_LINE_LOOP);
	// Tx, Ty chua toa do tweening cua A va B
	for (int i = 0; i < n; ++i) {
		float Tx = tweening(A[i][0], B[i][0], t);
		float Ty = tweening(A[i][1], B[i][1], t);
		glVertex2f(Tx, Ty);
	}
	glEnd();
	glFlush();
}

void display(void) {
	for (float t = 0.0, deltaT = 0.01; ; t += deltaT) {
		glClear(GL_COLOR_BUFFER_BIT);
		drawTweening(A, B, numberOfPoint, t);
		glutSwapBuffers();
		if (t >= 1.0 || t < 0.0) deltaT = -deltaT;
		Sleep(100);
	}
}

int main(int argc, char** argv) {

   	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tweening");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

