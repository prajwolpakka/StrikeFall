#include "player.h"
#include <windows.h>
#include <GL/glut.h>
#include "arena.h"
#include <stdio.h>
#include <math.h>

float A,B,C;
void player::moveInside(float angle,float repeat) {
    A = 0.0004,B = 0.008,C = 0.04;
    player::previousState = 'I';
    if(repeat>15) {
        repeat = 15;
    }
    player::velocity = (A*repeat*repeat+B*repeat+C);
    printf("%f \n", player::velocity);
    player::xPosition += player::velocity*sin(angle * 0.0174533);
    player::zPosition -= player::velocity *cos(angle * 0.0174533);
}
void player::moveOutside(float angle,float repeat) {
    A = 0.0004,B = 0.008,C = 0.04;
    player::previousState = 'O';
    if(repeat>15) {
        repeat = 15;
    }
    player::velocity = (A*repeat*repeat+B*repeat+C);
    player::xPosition -= player::velocity*sin(angle * 0.0174533);
    player::zPosition += player::velocity*cos(angle * 0.0174533);
}
void player::moveLeft(float angle,float repeat) {
    A = 0.0004,B = 0.008,C = 0.04;
    player::previousState = 'L';
    if(repeat>15) {
        repeat = 15;
    }
    player::velocity = (A*repeat*repeat+B*repeat+C);
    player::xPosition -= player::velocity*cos(angle * 0.0174533);
    player::zPosition -= player::velocity*sin(angle * 0.0174533);
}
void player::moveRight(float angle,float repeat) {
    A = 0.0004,B = 0.008,C = 0.04;
    player::previousState = 'R';
    if(repeat>15) {
        repeat = 15;
    }
    player::velocity = (A*repeat*repeat+B*repeat+C);
    player::xPosition += player::velocity*cos(angle * 0.0174533);
    player::zPosition += player::velocity*sin(angle * 0.0174533);
}
void player::draw() {
    const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
    const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
    const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_BLEND);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);

//    glDisable(GL_DEPTH_TEST);
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glPushMatrix();
    glColor4f(player::R,player::G,player::B,0.8);
    glTranslatef(player::xPosition,player::yPosition,player::zPosition);
    glutSolidSphere(player::radius,25,25);
    glPopMatrix();
    glDisable(GL_BLEND);

//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_LIGHTING);
}
bool player :: baseCheck() {
    if(player::xPosition<-9 || player::xPosition>9 || player::zPosition< -9 || player::zPosition>9) {
        return false;
    }
    if(player::yPosition != 0) {
        return false;
    } else {
        return true;
    }
}
void player::respawn() {
    player::yPosition = 0;
    player::zPosition = 0;
    player::xPosition = 0;
    player::death++;
}
void player::fall() {
    for(int i = 0; i<5; i++) {
        player::yPosition-=0.05;
        glutPostRedisplay();
    }
    if(player::yPosition<-100) {
        player::respawn();
    }
}
player::~player() {
    //dtor
}
