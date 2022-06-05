#include<windows.h>
#include <gl/glut.h>
#include <math.h>
#define PI 3.14

// Coding By Arnanda Nuryasa / 191110227

int circle_points = 30;
int circle_covers =1000;

void Badan(GLfloat radius, GLfloat tinggi){
    GLint i;
	GLdouble theta, ntheta;
	for (i = 0;i < circle_points;i++) {
		glBegin(GL_POLYGON);
		theta = (2*PI*i/circle_points);
		ntheta = (2*PI*(i+1)/circle_points);

		glVertex3f(radius*cos(theta),0,radius*sin(theta));
		glVertex3f(radius*cos(ntheta),0,radius*sin(ntheta));
		glVertex3f(radius*cos(ntheta),tinggi,radius*sin(ntheta));
		glVertex3f(radius*cos(theta),tinggi,radius*sin(theta));
		glVertex3f(radius*cos(theta),0,radius*sin(theta));
		glEnd();
	}
}


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
void Tutup(GLfloat a, GLfloat b, GLfloat c, GLfloat r){
    GLint i;
    GLdouble sudut;
    glBegin(GL_LINE_STRIP);
    for (i = 0; i < circle_covers; i++){
        sudut = 2*PI*i/circle_covers;
        glColor3f(1,1,1);
        glVertex3f(0,-0.8,0);
        glVertex3f( a+r*cos(sudut),b ,c+r*sin(sudut));
    }
    glEnd();
}

void Draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,1,1);
    Badan(0.8,-0.9);
    Atap(1,0.6);
    Tutup(0,-0.9,0,0.8);
    glFlush();
}


void reshape(int w, int h)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glFrustum(-0.5*(GLfloat)w/h,0.5*(GLfloat)w/h,-0.5,0.5,1,50);
    gluLookAt(0,-0.5,3,0,0,-100,0,1,0);

}

void Initialize(void){
    glLineWidth(1.5);
    glPolygonMode(GL_FRONT, GL_LINE);
    glPolygonMode(GL_BACK, GL_LINE);
}


int main(int iArgc, char** cppArgv)
{
    glutInit(&iArgc, cppArgv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(460, 320);
    glutCreateWindow("Lingkaran 3D Arnanda N");
    Initialize();
    glutDisplayFunc(Draw);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
