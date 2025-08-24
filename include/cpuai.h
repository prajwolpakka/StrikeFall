#ifndef CPUAI_H
#define CPUAI_H
#include "player.h"

float distance(player hero,player villain);
void cpuAI(player &hero,player villain1,player villain2, player villain3);
float slope(player hero, player villain);
#endif // CPUAI_H
