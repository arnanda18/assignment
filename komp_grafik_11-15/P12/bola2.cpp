
#include<windows.h>
#include <gl/glut.h>
#include <math.h>
#define PI 3.14

void Bola(GLfloat radius){
    GLdouble inc = PI/12;
    GLdouble theta, phi;

    for(theta=-PI/2; theta<(PI/2-inc); theta+=inc){
        for(phi = 0; phi < 2* PI; phi+=inc){
            glBegin(GL_POLYGON);
            glVertex3f(radius*cos(theta)*cos(phi), radius*sin(theta), radius*cos(theta)*sin(phi));
            glVertex3f(radius*cos(theta+inc)*cos(phi), radius*sin(theta+inc), radius*cos(theta+inc)*sin(phi));
            glVertex3f(radius*cos(theta+inc)*cos(phi+inc), radius*sin(theta+inc), radius*cos(theta+inc)*sin(phi+inc));
            glVertex3f(radius*cos(theta)*cos(phi+inc), radius*sin(theta), radius*cos(theta)*sin(phi+inc));
            glEnd();
        }
    }
    glFlush();
}

void Draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    //glTranslatef(0.,0.,-0.5);
    Bola(0.5);
    //glRotatef(0.5,0,1,0);
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}


void reshape(int w, int h)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.5*(GLfloat)w/h,0.5*(GLfloat)w/h,-0.5,0.5,1,20);
    glLoadIdentity();
    gluLookAt(0,0.1,0.5,0,0,-100,0,1,0);

}

void Initialize(void){
    glLineWidth(1.5);
    glPolygonMode(GL_FRONT, GL_LINE);
    glPolygonMode(GL_BACK, GL_LINE);
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);
    //glPolygonMode(GL_FRONT, GL_FILL);
}


int main(int iArgc, char** cppArgv)
{
    glutInit(&iArgc, cppArgv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(460, 320);
    glutCreateWindow("Rumah Burung 3D Arnanda");
    Initialize();
    glutDisplayFunc(Draw);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
