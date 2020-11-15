#ifndef UTILITIES_H
#define UTILITIES_H

void displayString(char data[],int length,float x,float y,float z,float R,float G,float B);
void displayStatusBar(bool player1mode, float xPosStatBar,float yPosStart,float zPosition, int p1Death,int p2Death, int p3Death, int p4Death,bool resultMode);
void displayTimer(int second);
void handleGameOver(bool player1mode,int p1Death,int p2Death,int p3Death,int p4Death);
#endif // UTILITIES_H
