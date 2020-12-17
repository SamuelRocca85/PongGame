#ifndef PLAYER_
#define PLAYER_
#include "Graphic.h"

using namespace std;

class Player : public  Graphic
{
public:
    Player(int x,int y) 
     : Graphic(x,y) , puntos(0)
     {}

    void draw();
    void clean();
    void reset();
    void move(int dir);
    void anotar()
    {puntos++;}
    int getPuntos() const 
    { return puntos; }
private:
    int puntos;
};


#endif //PLAYER_