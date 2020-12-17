#include "Ball.h"

void Ball::draw()
{
    gotoxy(x,y); printf("%c" , 79);
}

void Ball::clean()
{
    gotoxy(x,y); printf(" ");
}

int Ball::move(Player *p1, Player *p2)
{
    int point = 0;
    clean();
    x += dx;
    y += dy;
    draw();

    if(x + dx == 1) //Punto para el jugador 2
    {   
        p2->anotar();
        point = 1;
    }else if (x + dx == 60) // Punto para el jugador 1
    {
        p1->anotar();
        point = 1;
    }
    
    //Colision en los bordes horizontales del mapa
    if(y + dy == 2 || y + dy == 24 )
        dy = -dy;

    //Colision con los jugadores
    if ((x + dx == p1->getX() && y >= p1->getY() -2 && y <= p1->getY()+2) || (x + dx == p2->getX() && y >= p2->getY() -2 && y <= p2->getY()+2))
            dx = -dx;

    return point;
}

void Ball::reset()
{
    setCoordinates(30,12);
}