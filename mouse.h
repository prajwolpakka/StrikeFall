#ifndef MOUSE_H
#define MOUSE_H
#include "screens.h"
#include <stdio.h>

bool mouseEnabled = false;
bool optionsScreen = false;
bool musicEnabled = true;

void mouseCallback(int btn, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        if(mouseEnabled) {
            switch(btn) {
            case GLUT_LEFT_BUTTON:
                printf("X= %d Y= %d \n",x,y);
                if((x > 582 && x < 948) && (y < 351 && y > 302) && !optionsScreen) {
                    PlaySound(TEXT("mouseClick.wav"),NULL,SND_FILENAME|SND_ASYNC );
                    mouseEnabled = false;
                    chooseFirstPlayerMode(musicEnabled);
                    printf("Player 1 mode selected \n");
                } else if((x > 577 && x < 957) && (y < 424 && y > 377) && !optionsScreen) {
                    PlaySound(TEXT("mouseClick.wav"),NULL,SND_FILENAME|SND_ASYNC );
                    mouseEnabled = false;
                    chooseSecondPlayerMode(musicEnabled);
                    printf("Player 2 mode selected \n");
                } else if((x > 669 && x < 868) && (y < 496 && y > 449) && !optionsScreen) {
                    if(!musicEnabled) {
                        PlaySound(TEXT("mouseClick.wav"),NULL,SND_FILENAME|SND_ASYNC );
                    }
                    printf("Options Menu selected \n");
                    optionsScreen = true;
                    glutDisplayFunc(viewOptions);
                    glutPostRedisplay();
                } else if((x > 598 && x < 931) && (y < 564 && y > 514) && !optionsScreen) {
                    if(!musicEnabled) {
                        PlaySound(TEXT("mouseClick.wav"),NULL,SND_FILENAME|SND_ASYNC );
                    }
                    printf("Instructions Menu Selected \n");
                    glutDisplayFunc(viewInstructions);
                    glutPostRedisplay();
                } else if((x > 666 && x < 858) && (y < 636 && y > 585) && !optionsScreen) {
                    if(!musicEnabled) {
                        PlaySound(TEXT("mouseClick.wav"),NULL,SND_FILENAME|SND_ASYNC );
                    }
                    printf("Credits Menu Selected \n");
                    glutDisplayFunc(viewCredits);
                    glutPostRedisplay();
                } else if((x > 243 && x < 353) && (y < 831 && y > 770) && mouseEnabled) {
                    if(!musicEnabled) {
                        PlaySound(TEXT("mouseClick.wav"),NULL,SND_FILENAME|SND_ASYNC );
                    }
                    optionsScreen = false;
                    printf("Back Pressed \n");
                    glutDisplayFunc(menuScreen);
                    glutPostRedisplay();
                } else if((x > 655 && x < 746) && (y < 469 && y > 406) && optionsScreen) {
                    if(!musicEnabled) {
                        PlaySound(TEXT("mouseClick.wav"),NULL,SND_FILENAME|SND_ASYNC );
                    }
                    printf("Music On \n");
                    musicEnabled = true;
                    PlaySound(TEXT("welcomeScreenMusic.wav"),NULL,SND_FILENAME|SND_ASYNC );
                } else if((x > 787 && x < 883) && (y < 468 && y > 406) && optionsScreen) {
                    PlaySound(TEXT("mouseClick.wav"),NULL,SND_FILENAME|SND_ASYNC );
                    printf("Music Off \n");
                    musicEnabled = false;
                }
                break;
            default:
                break;
            }
        }
    }
}

#endif // MOUSE_H
