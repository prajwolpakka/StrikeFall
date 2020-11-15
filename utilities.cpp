#include "utilities.h"
#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>

void displayString(char data[],int length,float x,float y,float z,float R,float G,float B) {
    glLoadIdentity();
    glColor3f(R,G,B);
    glRasterPos3f(x,y,z);
    for(int i=0; i<length; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,data[i]);
    }
}
void displayStatusBar(bool player1mode, float xPosStatBar,float yPosStart,float zPosition, int p1Death,int p2Death, int p3Death, int p4Death,bool resultMode) {
    char player1Text[] = "Player1 - ";
    char player2Text[] = "Player2 - ";
    char cpu1Text[] = "Cpu 1   - ";
    char cpu2Text[] = "Cpu 2   - ";
    char cpu3Text[] = "Cpu 3   - ";
    char winnerText[] = "Winner";

    char p1Val[2];
    char p2Val[2];
    char p3Val[2];
    char p4Val[2];

    sprintf(p1Val,"%d",p1Death);
    sprintf(p2Val,"%d",p2Death);
    sprintf(p3Val,"%d",p3Death);
    sprintf(p4Val,"%d",p4Death);

    displayString(player1Text,10,xPosStatBar,yPosStart,zPosition,1,0,0);
    displayString(p1Val,2,xPosStatBar+2,yPosStart,zPosition,1,0,0);
    displayString(p2Val,2,xPosStatBar+2,yPosStart -1,zPosition,0,1,0);
    displayString(p3Val,2,xPosStatBar+2,yPosStart -2,zPosition,0.7,0.7,0.75);
    displayString(p4Val,2,xPosStatBar+2,yPosStart -3,zPosition,0,0,1);

    if(player1mode) {
        displayString(cpu1Text,10,xPosStatBar,yPosStart -1,zPosition,0,1,0);  // cpu1
        displayString(cpu2Text,10,xPosStatBar,yPosStart -2,zPosition,0.7,0.7,0.75); // cpu2
        displayString(cpu3Text,10,xPosStatBar,yPosStart -3,zPosition,0,0,1); //cpu3
    } else {
        displayString(player2Text,10,xPosStatBar,yPosStart -1,zPosition,0,1,0);
        displayString(cpu1Text,10,xPosStatBar,yPosStart -2,zPosition,0.9,0.9,0.9);
        displayString(cpu2Text,10,xPosStatBar,yPosStart -3,zPosition,0,0,1);
    }
    if(resultMode) {
        if(p1Death<=p2Death && p1Death<=p3Death && p1Death<=p4Death) {
            displayString(winnerText,6,xPosStatBar+4,yPosStart,zPosition,1,0,0);
        }
        if(p2Death<=p1Death && p2Death<=p3Death && p2Death <= p4Death) {
            displayString(winnerText,6,xPosStatBar+4,yPosStart -1,zPosition,0,1,0);
        }
        if(p3Death<=p1Death && p3Death<=p2Death && p3Death<=p4Death) {
            displayString(winnerText,6,xPosStatBar+4,yPosStart -2,zPosition,0.7,0.7,0.75);
        }
        if(p4Death<=p1Death && p4Death<=p2Death && p4Death<=p1Death) {
            displayString(winnerText,6,xPosStatBar+4,yPosStart -3,zPosition,0,0,1);
        }
    }
}
void displayTimer(int second) {
    char charSecond[2];
    sprintf(charSecond,"%d",second);
    glTranslatef(0,10,-27);
    glRasterPos3f(-1,3.5,-27);
    for(int i=0; i<2; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,charSecond[i]);
    }
}

void handleGameOver(bool player1mode,int p1Death,int p2Death,int p3Death,int p4Death) {
    //results
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    int temp,winners[4]= {p1Death,p2Death,p3Death,p4Death};
    displayStatusBar(player1mode,-4,0,-25,winners[0],winners[1],winners[2],winners[3],true);
    //Transparent background
    glEnable(GL_BLEND);
    glTranslatef(-0.5,-1,-26);
    glColor4f(0.878,0.878,0.878,0.2);
    glutSolidCube(20);
    glDisable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);

}
