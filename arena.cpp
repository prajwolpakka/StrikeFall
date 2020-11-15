#include "arena.h"
#include <windows.h>
#include <GL/glut.h>

int minX = -9,maxX = 9,minZ = -9,maxZ = 9;
void drawTile(float x,float y,float z, float R,float G,float B) {
    glPushMatrix();
    glTranslatef(x,y,z);
    glColor3f(R/255,G/255,B/255);
    glutSolidCube(1);
    glPopMatrix();
}
void drawArena() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_DEPTH_TEST);
    for(int i = minX; i<=maxX; i++) { //left and right
        for(int j=-9; j<=9; j++) { // front and back
            if(i == minX ||j == minZ || i == maxX || j == maxZ) {//out line
                drawTile(i,-1.1,j,119, 51, 255);
            } else if((i % 2 == 0 && j % 2 == 0)|| (i % 2 != 0 && j % 2 != 0)) {
                drawTile(i,-1.1,j,255,255,255);//white tile
            } else {
                drawTile(i,-1.1,j,92,107,192);//blue tile
            }
        }
    }
}
