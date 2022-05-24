
#include<windows.h>
#include <gl/glut.h>
#include <math.h>
#define PI 3.14

// Coding By Arnanda Nuryasa / 191110227

int jumlah_titik = 1000;

void CircleX(GLfloat a, GLfloat b, GLfloat c, GLfloat r){
    GLint i;
    GLdouble sudut;
    glBegin(GL_LINE_STRIP);
    for (i = 0; i < jumlah_titik; i++){
        sudut = 2*PI*i/jumlah_titik;
        glColor3f(0,1,0);
        glVertex3f(a, b+r*cos(sudut),c+r*sin(sudut));
    }
    glEnd();
}

void CircleZ(GLfloat a, GLfloat b, GLfloat c, GLfloat r){
    GLint i;
    GLdouble sudut;
    glBegin(GL_LINE_STRIP);
    for (i = 0; i < jumlah_titik; i++){
        sudut = 2*PI*i/jumlah_titik;
        glColor3f(0,1,0);
        glVertex3f(a+r*cos(sudut), c+r*sin(sudut), b);
    }
    glEnd();
}

void CircleY(GLfloat a, GLfloat b, GLfloat c, GLfloat r){
    GLint i;
    GLdouble sudut;
    glBegin(GL_LINE_STRIP);
    for (i = 0; i < jumlah_titik; i++){
        sudut = 2*PI*i/jumlah_titik;
        glColor3f(0,1,0);
        glVertex3f( a+r*cos(sudut),c ,b+r*sin(sudut));
    }
    glEnd();
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    CircleX(0,0,0,0.8);
    CircleZ(0,0,0,0.8);
    CircleY(0,0,0,0.8);
    glFlush();
}


void reshape(int w, int h)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(60, (GLfloat)w/h, 1, 20);
    gluLookAt(0.5,0.5,3.5,0,0,-300,0,1,0);

}


int main(int iArgc, char** cppArgv)
{
    glutInit(&iArgc, cppArgv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(560, 560);
    glutCreateWindow("Lingkaran 3D Arnanda N");
    //Initialize();
    glutDisplayFunc(Draw);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
