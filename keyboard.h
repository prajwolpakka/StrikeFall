#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "screens.h"
#include <stdio.h>
#include "mouse.h"

bool p1Up = false, p1Down = false, p1Left = false, p1Right = false;
bool p2Up = false, p2Down = false, p2Left = false, p2Right = false;
float p1RepeatedUp = 0,p1RepeatedDown = 0,p1RepeatedLeft = 0,p1RepeatedRight = 0;
float p2RepeatedUp = 0,p2RepeatedDown = 0,p2RepeatedLeft = 0,p2RepeatedRight = 0;
bool replay = false;
void player1KeyPressed(unsigned char key, int xpos, int ypos) {
    switch(key) {
    case 'w':
        p1Up = true;
        p1RepeatedUp+=0.1;
        break;
    case 's':
        p1Down = true;
        p1RepeatedDown+=0.1;
        break;
    case 'd':
        p1Right = true;
        p1RepeatedRight+=0.1;
        break;
    case 'a':
        p1Left = true;
        p1RepeatedLeft+=0.1;
        break;
    case 13:
        replay = true;
        break;
    case 27:
        exit(0);
        break;
    case 32:
        printf("Space pressed \n");
        mouseEnabled = true;
        PlaySound(TEXT("mouseClick.wav"),NULL,SND_FILENAME|SND_ASYNC);
        glutDisplayFunc(menuScreen);
        glutPostRedisplay();
        break;
    default:
        printf("%c %d", key,key);
        break;
    }
}
void player1KeyRelease(unsigned char key, int xpos, int ypos) {
    if(key == 'w') {
        p1Up = false;
        p1RepeatedUp=0;
    } else if (key == 's') {
        p1Down = false;
        p1RepeatedDown=0;
    } else if (key == 'a') {
        p1Left = false;
        p1RepeatedLeft=0;
    } else if (key == 'd') {
        p1Right = false;
        p1RepeatedRight=0;
    }
}
void player2KeyPressed(int key, int xpos, int ypos) {
    switch(key) {
    case 101:
        p2Up = true;
        p2RepeatedUp+=0.1;
        break;
    case 103:
        p2Down = true;
        p2RepeatedDown+=0.1;
        break;
    case 102:
        p2Right = true;
        p2RepeatedRight+=0.1;
        break;
    case 100:
        p2Left = true;
        p2RepeatedLeft+=0.1;
        break;
    }
}
void player2KeyRelease(int key, int xpos, int ypos) {
    if(key == 101) {
        p2Up = false;
        p2RepeatedUp = 0;
    } else if (key == 103) {
        p2Down = false;
        p2RepeatedDown = 0;
    } else if (key == 100) {
        p2Left = false;
        p2RepeatedLeft = 0;
    } else if (key == 102) {
        p2Right = false;
        p2RepeatedRight = 0;
    }//    }else if()
}

#endif // KEYBOARD_H
