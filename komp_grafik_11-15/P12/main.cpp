#include<windows.h>
#include <gl/glut.h>
#include <math.h>
#define PI 3.14

// Coding By Arnanda Nuryasa / 191110227

int circle_points = 30;
int circle_covers =1000;

void Atap(GLfloat radius, GLfloat tinggi){
    GLint i;
	GLdouble theta, ntheta;
	for	(i = 0;i < circle_points;i++) {
		glBegin(GL_POLYGON);
		theta = (2*PI*i/circle_points);
		ntheta = (2*PI*(i+1)/circle_points);
		glVertex3f(radius*cos(theta),0,radius*sin(theta));
		glVertex3f(0,tinggi,0);
		glVertex3f(radius*cos(ntheta),0,radius*sin(ntheta));
		glEnd();
	}
}


void Draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,1,1);
    Atap(0.8,1);
    glRotatef(0.05,0,0,1);
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}


void reshape(int w, int h)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glFrustum(-0.5*(GLfloat)w/h,0.5*(GLfloat)w/h,-0.5,0.5,1,50);
    gluLookAt(0,-0.3,3,0,0,-100,0,1,0);

}

void Initialize(void){
    glLineWidth(1.5);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glPolygonMode(GL_FRONT, GL_FILL);
}


int main(int iArgc, char** cppArgv)
{
    glutInit(&iArgc, cppArgv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(460, 320);
    glutCreateWindow("3D Arnanda");
    Initialize();
    glutDisplayFunc(Draw);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
