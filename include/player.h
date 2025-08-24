#ifndef PLAYER_H
#define PLAYER_H

class player {
public:
    bool tagCPU;
    float xPosition;
    float yPosition;
    float zPosition;
    float radius;
    float R;
    float G;
    float B;
    int death;
    char previousState;
    float velocity;
//    bool fall;
//    float speedAttribute;

    void draw();
    void respawn();
    void moveInside(float angle,float repeat);
    void moveOutside(float angle,float repeat);
    void moveLeft(float angle,float repeat);
    void moveRight(float angle,float repeat);
    void fall();
    bool baseCheck();
//    bool motion();
    player(bool tag, float x, float z, float red, float green, float blue,float r = 0.6,float y = 0,float v = 0.035) {
        tagCPU = tag;
        xPosition = x;
        yPosition = y;
        zPosition = z;
        radius = r;
        R = red;
        G = green;
        B = blue;
        velocity = v;
        death = 0;
//        fall = false;
    }
    ~player();
} ;

#endif // PLAYER_H
