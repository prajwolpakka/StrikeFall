#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H
#include <windows.h>
#include <GL/glut.h>
#include "player.h"
#include <stdio.h>

float calculateAbs(float m) {
    return (m<0)?-m:m;
}
bool detectCollision(player p1,player p2) {
    if(calculateAbs(p1.xPosition-p2.xPosition)<(p1.radius+p2.radius)*0.6 && calculateAbs(p1.zPosition - p2.zPosition)<(p1.radius+p2.radius)*0.6 && calculateAbs(p1.yPosition-p2.yPosition)<0.5) {
        return true;
    } else {
        return false;
    }
}
void handleCollision(player &p1,player &p2) {
    printf("%f %f \n", p1.velocity,p2.velocity);
    if(p1.xPosition>p2.xPosition) {
        if(p1.tagCPU) {
            p2.xPosition-= 0.8;
        } else {
            p2.xPosition-= (1+p1.velocity);
        }
        if(p2.tagCPU) {
            p1.xPosition+= 0.8;
        } else {
            p1.xPosition+= (1+p1.velocity);
        }
    } else {
        if(p1.tagCPU) {
            p2.xPosition+= 0.8;
        } else {
            p2.xPosition+= (1+p1.velocity);
        }
        if(p2.tagCPU) {
            p1.xPosition-= 0.8;
        } else {
            p1.xPosition-= (1+p1.velocity);
        }
    }
    if(p1.zPosition>p2.zPosition) {
        if(p1.tagCPU) {
            p2.zPosition-= 0.8;
        } else {
            p2.zPosition-= (0.1+p1.velocity);
        }
        if(p2.tagCPU) {
            p1.zPosition+= 0.8;
        } else {
            p1.zPosition+= (1+p1.velocity);
        }
    } else {
        if(p1.tagCPU) {
            p2.zPosition+= 0.8;
        } else {
            p2.zPosition+= (1+p1.velocity);
        }
        if(p2.tagCPU) {
            p1.zPosition-= 0.8;
        } else {
            p1.zPosition-= (1+p1.velocity);
        }
    }//    if(!p1.tagCPU) {
//        p1.velocity = 0;
//    }
//    if(!p2.tagCPU) {
//        p2.velocity = 0;
//    }
}
#endif // COLLISIONDETECTION_H
