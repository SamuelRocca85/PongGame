#ifndef GRAPHIC_
#define GRAPHIC_
#include "iostream"
#include "rlutil.h"

using namespace std;

class Graphic
{
protected:
    Graphic(int x, int y)
        : x(x) , y(y)
    {}

    virtual void draw() = 0;
    virtual void clean() = 0;
    virtual void reset() = 0;
    
    int x;
    int y;
    
public:
    void setCoordinates(int _x, int _y)
    { x = _x; y = _y;}

    int getX()
    {return x;}

    int getY()
    {return y;}
};


#endif //GRAPHIC_