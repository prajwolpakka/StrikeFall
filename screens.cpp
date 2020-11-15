#include "screens.h"
#include <windows.h>
#include <GL/glut.h>
#include "image.h"
#include "stdio.h"
#define FPS 100

#include "arena.h"
#include "player.h"
#include "keyboard.h"
#include "mouse.h"
#include "collisiondetection.h"
#include "cpuai.h"
#include "utilities.h"
#include <time.h>

bool player2Mode,audio,gameOver,respawner = false;
float arenaRotation=0,starterCubePos = -0.5,starterCubeOpacity = 1;
player p1(false,-8,-8,1,0,0),p2(false,8,8,0,1,0),cpu1(true,8,-8,0.5,0.8,1),cpu2(true,-8,8,0,0,1);
bool callBackHandlers;
int second;
bool gameStart = true;
int cpuHandicap = 0;
int initialTime,finalTime,respawnInitialTime;
void setInitialPosition() {
    p1.xPosition = -8;
    p1.zPosition = -8;
    p1.yPosition = 0;

    p2.xPosition = 8;
    p2.zPosition = 8;
    p2.yPosition = 0;

    cpu1.xPosition = 8;
    cpu1.zPosition = -8;
    cpu1.yPosition = 0;

    cpu2.xPosition = -8;
    cpu2.zPosition = 8;
    cpu2.yPosition = 0;

    p1.death = 0;
    p2.death = 0;
    cpu1.death = 0;
    cpu2.death = 0;
    gameStart = true;
}
void timer(int) {
    finalTime = time(NULL);
    if((finalTime - initialTime)>1) {
        gameStart = false;
    }
    if((finalTime - respawnInitialTime)>1) {
        respawner = false;
    }
    glutTimerFunc(1000,timer,0);
    second--;
    if(second == 12) {
//        printf("Here is the countdown \n");
        if(audio) {
            PlaySound(TEXT("countDown.wav"),NULL,SND_FILENAME | SND_ASYNC);
        }
    }
}
void welcomeScreen() {
    glDisable(GL_LIGHTING);
    glClearColor(0.30,0.56,1.0,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glLoadIdentity();
    glTranslated(0,-4,-35);
    PlaySound(TEXT("welcomeScreenMusic.wav"),NULL,SND_FILENAME | SND_ASYNC );
    image("welcomeScreen.jpg");
    callBackHandlers = true;
    glPopMatrix();
    glutSwapBuffers();
    glEnable(GL_LIGHTING);
}
void menuScreen() {
    glDisable(GL_LIGHTING);
    glClearColor(0.30,0.56,1.0,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glLoadIdentity();
    glTranslated(0,-4,-35);
    image("menuScreen.jpg");
    glPopMatrix();
    glutSwapBuffers();
    glEnable(GL_LIGHTING);
}

void chooseFirstPlayerMode(bool musicSetting) {
    player2Mode = false;
    p2.tagCPU = true;
    audio = musicSetting;
    second = 62;
    arenaRotation = 0;
    gameOver = false;
    gameStart = true;
    respawner = false;
    starterCubePos = -0.5;
    starterCubeOpacity = 1;
    initialTime = time(NULL);
    if(audio) {
        PlaySound(TEXT("player1GamePlay.wav"),NULL,SND_FILENAME|SND_ASYNC);
    }
    if(callBackHandlers) {
        callBackHandlers = false;
        glutTimerFunc(1000/FPS,renderer,0);
        glutTimerFunc(1400,timer,0);
    }
    cpu2.velocity = cpu1.velocity+0.01;
    glutDisplayFunc(displayScreen);
}
void chooseSecondPlayerMode(bool musicSetting) {
    player2Mode = true;
    audio = musicSetting;
    second = 59;
    arenaRotation = 0;
    gameOver = false;
    gameStart = true;
    respawner = false;
    starterCubePos = -0.5;
    starterCubeOpacity = 1;
    initialTime = time(NULL);
    if(audio) {
        PlaySound(TEXT("player2GamePlay.wav"),NULL,SND_FILENAME|SND_ASYNC);
    }
    if(callBackHandlers) {
        callBackHandlers = false;
        glutTimerFunc(1000/FPS,renderer,0);
        glutTimerFunc(1400,timer,0);
    }
    cpu2.velocity = cpu1.velocity+0.01;
    glutDisplayFunc(displayScreen);
}
void viewOptions()  {
    glDisable(GL_LIGHTING);
    glClearColor(0.27,0.41,0.6,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glLoadIdentity();
    glTranslated(0,-4,-35);
    image("viewOptions.jpg");
    glPopMatrix();
    glutSwapBuffers();
    glEnable(GL_LIGHTING);
}
void viewCredits() {
    glDisable(GL_LIGHTING);
    glClearColor(0.27,0.41,0.6,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glLoadIdentity();
    glTranslated(0,-3.5,-35);
    image("viewCredits.jpg");
    glPopMatrix();
    glutSwapBuffers();
    glEnable(GL_LIGHTING);
}
void viewInstructions(void) {
    glDisable(GL_LIGHTING);
    glClearColor(0.27,0.41,0.6,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glLoadIdentity();
    glTranslated(0,-4,-35);
    image("viewInstructions.jpg");
    glPopMatrix();
    glutSwapBuffers();
    glEnable(GL_LIGHTING);
}
void respawnAnimation() {

    glEnable(GL_BLEND);
    glPushMatrix();

    glLoadIdentity();
    glTranslatef(-0.5,-2,-27);
    glRotatef(49,1,0,0);
    glRotatef(arenaRotation,0,1,0);

    glTranslatef(0,starterCubePos,0);
    glColor4f(0,0,0,starterCubeOpacity);
    glutSolidCube(1.1);

    glPopMatrix();
    glDisable(GL_BLEND);
    starterCubePos+=0.05;
    starterCubeOpacity-=0.015;
}

void gameStartAnimation() {
    glEnable(GL_BLEND);
    setInitialPosition();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.5,-2,-27);
    glRotatef(49,1,0,0);
    glRotatef(arenaRotation,0,1,0);

    glPushMatrix();
    glTranslatef(8,starterCubePos,8);
    glColor4f(0,0,0,starterCubeOpacity);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-8,starterCubePos,-8);
    glColor4f(0,0,0,starterCubeOpacity);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-8,starterCubePos,8);
    glColor4f(0,0,0,starterCubeOpacity);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(8,starterCubePos,-8);
    glColor4f(0,0,0,starterCubeOpacity);
    glutSolidCube(1);
    glPopMatrix();

    glPopMatrix();

    glDisable(GL_BLEND);
    starterCubePos+=0.03;
    starterCubeOpacity-=0.015;
}
void displayScreen() {
    glClearColor(0.30,0.56,1.0,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.5,-2,-27);
    glRotatef(49,1,0,0);
    glRotatef(arenaRotation,0,1,0);
    drawArena();
    glPushMatrix();
    p1.draw();
    p2.draw();
    cpu1.draw();
    cpu2.draw();
    glPopMatrix;
    if(gameStart) {
        gameStartAnimation();
//        glutPostRedisplay();
    }
    if(respawner) {
        respawnAnimation();
    }
    glPopMatrix();
    glDisable(GL_LIGHTING);
    glColor3f(0.0,0.0,0.0);
    if(second > 0) {
        displayTimer(second);
    } else {
        gameOver = true;
        replay = false;
    }
    if(gameOver) {
        handleGameOver(p2.tagCPU,p1.death,p2.death,cpu1.death,cpu2.death);
    }   else {
        displayStatusBar(p2.tagCPU,12,6.3,-26,p1.death,p2.death,cpu1.death,cpu2.death,false);
    }
    glEnable(GL_LIGHTING);
    glutSwapBuffers();
    glFlush();
}

void renderer(int) {
    glutTimerFunc(1000 / FPS,renderer,0);
    arenaRotation+=0.05;
    if(arenaRotation > 360) {
        arenaRotation = 0;
    }
    if(!gameOver && !gameStart) {
        if(p1Up) {
            p1.moveInside(arenaRotation,p1RepeatedUp);
        }
        if(p1Down) {
            p1.moveOutside(arenaRotation,p1RepeatedDown);
        }
        if(p1Left) {
            p1.moveLeft(arenaRotation,p1RepeatedLeft);
        }
        if(p1Right) {
            p1.moveRight(arenaRotation,p1RepeatedRight);
        }
        if(player2Mode) {
            if(p2Up) {
                p2.moveInside(arenaRotation,p2RepeatedUp);
            }
            if(p2Down) {
                p2.moveOutside(arenaRotation,p2RepeatedDown);
            }
            if(p2Left) {
                p2.moveLeft(arenaRotation,p2RepeatedLeft);
            }
            if(p2Right) {
                p2.moveRight(arenaRotation,p2RepeatedRight);
            }
        }
        if(detectCollision(p1,p2)) {
            handleCollision(p1,p2);
        }
        if(detectCollision(p1,cpu1)) {
            handleCollision(p1,cpu1);
        }
        if(detectCollision(p1,cpu2)) {
            handleCollision(p1,cpu2);
        }
        if(detectCollision(p2,cpu1)) {
            handleCollision(p2,cpu1);
        }
        if(detectCollision(p2,cpu2)) {
            handleCollision(p2,cpu2);
        }
        if(detectCollision(cpu1,cpu2)) {
            handleCollision(cpu1,cpu2);
        }
        if(!p1.baseCheck()) {
            p1.fall();
            respawner = true;
            starterCubePos = -1;
            starterCubeOpacity = 0.8;
            respawnInitialTime = time(NULL);
        }
        if(!p2.baseCheck()) {
            p2.fall();
            respawner = true;
            starterCubePos = -1;
            starterCubeOpacity = 0.8;
            respawnInitialTime = time(NULL);
        }
        if(!cpu1.baseCheck()) {
            cpu1.fall();
            respawner = true;
            starterCubePos = -1;
            starterCubeOpacity = 0.8;
            respawnInitialTime = time(NULL);
        }
        if(!cpu2.baseCheck()) {
            cpu2.fall();
            respawner = true;
            starterCubePos = -1;
            starterCubeOpacity = 0.8;
            respawnInitialTime = time(NULL);
        }
        if(cpuHandicap % 1000 == 0) {
            cpuAI(cpu1,cpu2,p1,p2);
            cpuAI(cpu2,cpu1,p1,p2);
            if(!player2Mode) {
                cpuAI(p2,cpu1,cpu2,p1);
            }
        }
    }
    if(gameOver && replay) {
        if(player2Mode && audio)  {
            PlaySound(TEXT("player2GamePlay.wav"),NULL,SND_FILENAME|SND_ASYNC);
        } else if(!player2Mode && audio) {
            PlaySound(TEXT("player1GamePlay.wav"),NULL,SND_FILENAME|SND_ASYNC);
        }
        gameOver = false;
        replay = false;
        second = 61;
        initialTime = time(NULL);
        setInitialPosition();
        starterCubePos = 0;
        starterCubeOpacity = 1;
    }
    glutPostRedisplay();
}
void initKeyboardAndMouse() {
//    Other functions will be here
    glutKeyboardFunc(player1KeyPressed);//Telling glut what function to call when the event occurs
    glutKeyboardUpFunc(player1KeyRelease);//Telling glut what function to call when the event occurs

    glutSpecialFunc(player2KeyPressed);//Telling glut what function to call when the event occurs
    glutSpecialUpFunc(player2KeyRelease);//Telling glut what function to call when the event occurs
    glutMouseFunc(mouseCallback);
}
