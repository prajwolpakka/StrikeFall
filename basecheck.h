#ifndef BASECHECK_H
#define BASECHECK_H

#include"player.h"

bool baseCheck(player p1) {
    if(p1.xPosition<minX || p1.xPosition>maxX ||p1.zPosition< minZ|| p1.zPosition>maxZ) {
        return false;
    } else {
        if(p1.motion == true || p1.tagCPU == true) {
            p1.velocity-=1;
            if(velocity<0) {
                velocity = 0;
            }
        }
        return true;
    }
}
#endif // BASECHECK_H
