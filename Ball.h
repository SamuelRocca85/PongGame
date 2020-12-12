#ifndef BALL_
#define BALL_
#include "Graphic.h"


class Ball : public Graphic
{
public:
    Ball(int x, int y, int dx, int dy)
     : Graphic(x,y), dx(dx), dy(dy)
    {}

    void draw();
    void clean();
    void move();

private:
    int dx;
    int dy;
};


#endif //BALL_