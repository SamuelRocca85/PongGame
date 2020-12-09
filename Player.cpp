#include "Player.h"

void Player::draw()
{
    gotoxy(x,y-1); printf("%c", 124);
    gotoxy(x,y); printf("%c", 124);
    gotoxy(x,y+1); printf("%c", 124);
}

void Player::clean()
{
    gotoxy(x,y-1); printf(" ");
    gotoxy(x,y); printf(" ");
    gotoxy(x,y+1); printf(" ");
}

void Player::move(int dir)
{
    clean();
    if (dir)
        y--;
    else
        y++;
}