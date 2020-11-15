#include <windows.h>
#include <GL/glut.h>
#include <time.h>
#include "globals.h"
#include "image.h"
#include "screens.h"

void Resize(int w, int h) {
    glViewport(0,0,(GLsizei) w,(GLsizei) w * 3/4);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0,4/3, 1.0,2000.0);
    glMatrixMode(GL_MODELVIEW);
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 20.0f, 0.0f, -20.0f, 1.0f };

void init() {
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
//    glEnable(GL_BLEND);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //transparency
    glClearColor(0.30,0.56,1.0,1);
}

int main(int argc, char **argv) {
    glutInit(&argc,argv); // initialize

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutCreateWindow("Strike Fall");

    glutFullScreen();
    glutReshapeFunc(Resize);
    glutDisplayFunc(welcomeScreen);
    init();
    initKeyboardAndMouse();
    glutTimerFunc(1000 / 100,renderer,0);
    glutMainLoop();
    return 0;
}


