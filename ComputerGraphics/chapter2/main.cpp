#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>


void init(){
	glClearColor(1.0, 1.0 ,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,200.0,0.0,150.0);
}

void lineSegment(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(180,15);
		glVertex2i(10,145);
	glEnd();

	glFlush();
}

int main(int argv, char* argc[]){
	glutInit(&argv, argc);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(400,300);
	glutCreateWindow("Example OpenGL Window");

	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();
}