#ifndef PLAYER_
#define PLAYER_
#include "Graphic.h"


using namespace std;

class Player : public  Graphic
{
public:
    Player(int x,int y) 
     : Graphic(x,y) 
     {}

    void draw();
    void clean();
    void move(int dir);
};


#endif //PLAYER_