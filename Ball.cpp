#include "Ball.h"

void Ball::draw()
{
    gotoxy(x,y); printf("%c" , 79);
}

void Ball::clean()
{
    gotoxy(x,y); printf(" ");
}

void Ball::move()
{
    clean();
    x += dx;
    y += dy;
    draw();

    if(x + dx == 1 || x + dx == 60)
    {   
        clean();
        dx = -dx;
    }
    if(y + dy == 2 || y + dy == 24 )
    {
        dy = -dy;
    }

}