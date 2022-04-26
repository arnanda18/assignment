#include <windows.h>
#include <gl/glut.h>
#include <math.h>
#define PI 3.1415926535898

// Coding By Arnanda Nuryasa / 191110227

int jumlah_titik=200;

void lingkaran(){
    GLint i;
    GLdouble sudut;
    glBegin(GL_POLYGON);
    for(i=0;i<jumlah_titik; i++){
        sudut = 2*PI*i/jumlah_titik;
        glVertex2f(120+20*cos(sudut),210+20*sin(sudut));
    }
    glEnd();
}
void badan(){
    GLint i;
    GLdouble sudut;
    glBegin(GL_POLYGON);
    for(i=0;i<jumlah_titik; i++){
        sudut = 2*PI*i/jumlah_titik;
        glVertex2f(170+58.5*cos(sudut),140+83.5*sin(sudut));
    }
    glEnd();
}
void gar_badan(){
    GLint i;
    GLdouble sudut;
    glBegin(GL_POLYGON);
    for(i=0;i<jumlah_titik; i++){
        sudut = 2*PI*i/jumlah_titik;
        glVertex2f(170+60*cos(sudut),140+85*sin(sudut));
    }
    glEnd();
}
void mata(){
    GLint i;
    GLdouble sudut;
    glBegin(GL_POLYGON);
    for(i=0;i<jumlah_titik; i++){
        sudut = 2*PI*i/jumlah_titik;
        glVertex2f(135+5*cos(sudut),180+10*sin(sudut));
    }
    glEnd();
}
void kantong(){
    GLint i;
    GLdouble sudut;
    glBegin(GL_POLYGON);
    for(i=0;i<jumlah_titik; i++){
        sudut = 2*PI*i/jumlah_titik;
        glVertex2f(170+22*cos(sudut),100+32*sin(sudut));
    }
    glEnd();
}

void mulut(){
    glBegin(GL_POLYGON);
    glPointSize(5);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(160,150);
    glVertex2f(170,157);
    glVertex2f(170,140);
    glEnd();
    glBegin(GL_POLYGON);
    glPointSize(5);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(170,157);
    glVertex2f(180,150);
    glVertex2f(170,140);
    glEnd();
    GLint i;
    GLdouble sudut;
    glColor3f(0.0, 0.2, 0.0);
    glBegin(GL_POLYGON);
    for(i=0;i<jumlah_titik; i++){
        sudut = 2*PI*i/jumlah_titik;
        glVertex2f(170+5*cos(sudut),162+3*sin(sudut));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glPointSize(5);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(180,150);
    glVertex2f(200,162);
    glVertex2f(196,157);
    glVertex2f(177,152);
    glEnd();
    glBegin(GL_POLYGON);
    glPointSize(5);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(160,150);
    glVertex2f(140,162);
    glVertex2f(145,157);
    glVertex2f(163,152);
    glEnd();
    glBegin(GL_POLYGON);
    glPointSize(5);
    glVertex2f(169,158);
    glVertex2f(169,142);
    glVertex2f(171,142);
    glVertex2f(171,158);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(15);
    glVertex2f(160,150);
    glVertex2f(170,157);
    glVertex2f(180,150);
    glVertex2f(170,140);
    glVertex2f(160,150);
    glEnd();
}

void kaki(){
    glBegin(GL_POLYGON);
    glColor3ub(147, 152,152);
    glVertex2f(100,55);
    glVertex2f(170,55);
    glVertex2f(170,75);
    glVertex2f(110,63);
    glVertex2f(105,59);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(147, 152,152);
    glVertex2f(170,55);
    glVertex2f(170,75);
    glVertex2f(230,63);
    glVertex2f(235,59);
    glVertex2f(140,55);
    glEnd();
}
void telinga(){
    GLint i;
    GLdouble sudut;
    glBegin(GL_POLYGON);
    for(i=0;i<jumlah_titik; i++){
        sudut = 2*PI*i/jumlah_titik;
        glVertex2f(120+10*cos(sudut),210+10*sin(sudut));
    }
    glEnd();
}
void ekor(){
    glBegin(GL_LINE_STRIP);
    glPointSize(10);
    glColor3ub(147, 152,152);
    glVertex2f(210,85);
    glVertex2f(220,80);
    glVertex2f(225,78);
    glVertex2f(240,80);
    glVertex2f(259,85);
    glVertex2f(267,95);
    glVertex2f(280,110);
    glVertex2f(290,120);
    glVertex2f(305,125);
    glVertex2f(330,110);
    glVertex2f(305,130);
    glVertex2f(300,130);
    glVertex2f(293,128);
    glVertex2f(285,123);
    glVertex2f(275,113);
    glVertex2f(265,98);
    glVertex2f(255,88);
    glVertex2f(235,83);
    glVertex2f(220,83);
    glVertex2f(215,87);
    glVertex2f(205,87);
    glVertex2f(210,85);
    glEnd();
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(147, 152,152);
    lingkaran();
    glColor3ub(147, 152,152);
    glLoadIdentity();
    glTranslatef(100,0,0);
    lingkaran();
    glLoadIdentity();
    glRotatef(0,12,23,0);
    glScalef(1.5,0.5,0);
    glTranslatef(-50,70,0);  //TAngan
    lingkaran();
    glLoadIdentity();
    glScalef(1.5,0.5,0);
    glTranslatef(35,70,0);  //Tangan
    lingkaran();
    glLoadIdentity();
    glColor3ub(252, 199,241);
    telinga();
    glLoadIdentity();
    glTranslatef(100,0,0);
    glColor3ub(252, 199,241);
    telinga();
    glLoadIdentity();
    glutSwapBuffers();
    glEnd();
    kaki();
    glLoadIdentity();
    glEnd();
    glColor3ub(0, 0,0);
    gar_badan();
    glLoadIdentity();
    glColor3ub(147, 152,152);
    badan();
    glLoadIdentity();
    glEnd();
    glColor3f(0.0, 0.0,0.0);
    mata();
    glLoadIdentity();
    glTranslatef(70,0,0);
    mata();
    glLoadIdentity();
    glEnd();
    glColor3ub(252, 199,241);
    kantong();
    glLoadIdentity();
    glEnd();
    mulut();
    glLoadIdentity();
    glEnd();
    ekor();
    glLoadIdentity();
    glEnd();
    glFlush();
}

void Initialize()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    gluOrtho2D(0, 360.0, 0, 280.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int iArgc, char** cppArgv)
{
    glutInit(&iArgc, cppArgv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(360, 280);
    glutCreateWindow("UTS ARNANDA NURYASA");
    Initialize();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}

