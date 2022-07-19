#include<windows.h>
#include <gl/glut.h>
#include <math.h>
#define PI 3.14

// Coding By Arnanda Nuryasa / 191110227

int circle_points = 23;
int circle_covers =1000;


void Tutup(GLfloat a, GLfloat b, GLfloat c, GLfloat r){
    GLint i;
    GLdouble sudut;
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    for (i = 0; i < circle_covers; i++){
        sudut = 2*PI*i/circle_covers;
        glVertex3f(0,1.3,0);
        glVertex3f( a+r*cos(sudut),b ,c+r*sin(sudut));
    }
    glEnd(); 
}

void Botol(GLfloat r1, GLfloat r2){
	GLint i;
	GLdouble theta, ntheta;
	for	(i = 0;i < circle_points;i++){
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBegin(GL_POLYGON);
		glColor3ub(243,243,243);
		theta = (2*PI*i/circle_points);
		ntheta = (2*PI*(i+1)/circle_points);
		glVertex3f(0,0,0);
		glVertex3f(r1*cos(theta),0,r1*sin(theta));
		glVertex3f(r1*cos(ntheta),0,r1*sin(ntheta));
		glVertex3f(0.5*cos(ntheta),0.15,0.5*sin(ntheta));
		glVertex3f(0.54*cos(ntheta),0.3,0.54*sin(ntheta));
		glVertex3f(0.58*cos(ntheta),0.45,0.58*sin(ntheta));
		glVertex3f(0.6*cos(ntheta),0.6,0.6*sin(ntheta));
		glVertex3f(0.6*cos(ntheta),0.75,0.6*sin(ntheta));
		glVertex3f(0.58*cos(ntheta),0.9,0.58*sin(ntheta));
		glVertex3f(0.54*cos(ntheta),1.05,0.54*sin(ntheta));
		glVertex3f(0.5*cos(ntheta),1.2,0.5*sin(ntheta));
		glVertex3f(r1*cos(ntheta),1.35,r1*sin(ntheta));
		glVertex3f(r1*cos(theta),1.35,r1*sin(theta));
		glVertex3f(0.5*cos(ntheta),1.2,0.5*sin(ntheta));
		glVertex3f(0.54*cos(ntheta),1.05,0.54*sin(ntheta));
		glVertex3f(0.58*cos(ntheta),0.9,0.58*sin(ntheta));
		glVertex3f(0.6*cos(ntheta),0.75,0.6*sin(ntheta));
		glVertex3f(0.6*cos(ntheta),0.6,0.6*sin(ntheta));
		glVertex3f(0.58*cos(ntheta),0.45,0.58*sin(ntheta));
		glVertex3f(0.54*cos(ntheta),0.3,0.58*sin(ntheta));
		glVertex3f(0.5*cos(ntheta),0.15,0.5*sin(ntheta));
		glVertex3f(r1*cos(theta),0,r1*sin(theta));
		glEnd();
	}
	
}

void SegitigaBadan(GLfloat r1, GLfloat r2){
	GLint i;
	GLdouble theta, ntheta;
	for	(i = 0;i < circle_points;i++){
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glBegin(GL_POLYGON);
		glColor3ub(243,243,243);
		theta = (2*PI*i/circle_points);
		ntheta = (2*PI*(i+1)/circle_points);
		glVertex3f(0,0,0);
		glVertex3f(r2*cos(ntheta),2.4,r2*sin(ntheta));
		glVertex3f(r2*cos(theta),2.4,r2*sin(theta));
		glVertex3f(r2*cos(theta),2.3,r2*sin(theta));
		glVertex3f(r1*cos(theta),1.35,r1*sin(theta));
		glEnd();
	}
	
	
	
}

void KotakAtas(GLfloat radius, GLfloat tinggi){
    GLint i;
	GLdouble theta, ntheta;
	for (i = 0;i < circle_points;i++) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBegin(GL_POLYGON);
		theta = (2*PI*i/circle_points);
		ntheta = (2*PI*(i+1)/circle_points);
		glColor3ub(243,243,243);
		glVertex3f(radius*cos(theta),2.5,radius*sin(theta));
		glVertex3f(radius*cos(ntheta),2.5,radius*sin(ntheta));
		glVertex3f(radius*cos(ntheta),tinggi,radius*sin(ntheta));
		glVertex3f(radius*cos(theta),tinggi,radius*sin(theta));
		glVertex3f(radius*cos(theta),2.5,radius*sin(theta));
		glEnd();
	}
}

void Draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

	Botol(0.4,0.05);
	Tutup(0,1.3,0,0.4 );
	SegitigaBadan(0.4,0.03);
    KotakAtas(1,3.65);
	glFlush();
}


void reshape(int w, int h)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glFrustum(-0.5*(GLfloat)w/h,0.5*(GLfloat)w/h,-0.5,0.5,1,50);
    gluLookAt(0,2,5,0,0,-100,0,1,0);

}

void Initialize(void){
    glLineWidth(1.5);
    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_FILL);
}


int main(int iArgc, char** cppArgv)
{
    glutInit(&iArgc, cppArgv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Project UAS Arnanda");
    Initialize();
    glutDisplayFunc(Draw);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
