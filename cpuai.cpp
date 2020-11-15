#include "cpuai.h"
#include <math.h>
#include <stdio.h>
float distance(player hero,player villain) {
    return pow(pow(hero.xPosition-villain.xPosition,2)+pow(hero.zPosition-villain.zPosition,2)+pow(hero.yPosition-villain.yPosition,2),0.5);
}
float slope(player hero, player villain) {
    float result = atan2(villain.zPosition-hero.zPosition,villain.xPosition - hero.xPosition); // radian result
    result *= 57.2958; //converting to degrees
//    printf(" angle = %f \n",result);
    return result;
}
float minimum(float d1,float d2,float d3) {
    float result = d1>d2?d2:d1;
    return result>d3?d3:result;
}
float maximum(float d1,float d2,float d3) {
    float result = d1<d2?d2:d1;
    return result<d3?d3:result;
}
void cpuAI(player &hero,player p1,player p2, player p3) {
    float angle,distanceP1,distanceP2,distanceP3,result,x,z;
    distanceP1 = distance(hero,p1);
    distanceP2 = distance(hero,p2);
    distanceP3 = distance(hero,p3);
    result = minimum(distanceP1,distanceP2,distanceP3);
    if(result == distanceP1) {
        angle = slope(hero,p1);
        x=p1.xPosition;
        z=p1.zPosition;
    } else if(result == distanceP2) {
        angle = slope(hero,p2);
        x=p2.xPosition;
        z=p2.zPosition;
    } else {
        angle = slope(hero,p3);
        x=p3.xPosition;
        z=p3.zPosition;
    }
    if(x>=-9 && x<= 9 && z>=-9 && z<=9) {
        hero.xPosition = hero.xPosition + hero.velocity*cos(angle*0.01745);
        hero.zPosition = hero.zPosition + hero.velocity*sin(angle*0.01745);
    } else {
        result=maximum(distanceP1,distanceP2,distanceP3);
        if(result == distanceP1) {
            angle = slope(hero,p1);
            x=p1.xPosition;
            z=p1.zPosition;
        } else if(result == distanceP2) {
            angle = slope(hero,p2);
            x=p2.xPosition;
            z=p2.zPosition;
        } else {
            angle = slope(hero,p3);
            x=p3.xPosition;
            z=p3.zPosition;
        }
        hero.xPosition = hero.xPosition + hero.velocity*cos(angle*0.01745);
        hero.zPosition = hero.zPosition + hero.velocity*sin(angle*0.01745);
    }
}
