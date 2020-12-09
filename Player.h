#ifndef PLAYER_
#define PLAYER_
#include "iostream"
#include "rlutil.h"

using namespace std;

class Player 
{
public:
    Player(int x,int y) 
     : x(x), y(y) 
     {}

    void draw();
    void clean();
    void move(int dir);
    
    int getX()
    {return x;}

    int getY()
    {return y;}


private:
    int x;
    int y;
};


#endif //PLAYER_