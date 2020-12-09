#include "rlutil.h"
#include <iostream>
#include <stdlib.h>
#include "Player.h"

using namespace std;
#define startkey rlutil::anykey("Pulse cualquier tecla para comenzar...\n\n")

void drawMap();

int main()
{
    rlutil::cls();
    rlutil::hidecursor();
    drawMap();
    gotoxy(62,12);
    startkey;
    gotoxy(62,12); cout << "Consigue 7 puntos para ganar!         ";
    Player j1(5,12); j1.draw();
    Player j2(55,12);j2.draw();
    

    while(true)
    {
        if(kbhit())
        {
            rlutil::cls();
            drawMap();
            char tecla = getch();
            if(tecla == 'q')
            {
                rlutil::showcursor();
                exit(0);   
            }
            else if(tecla == 'w' && j1.getY() > 3)
                j1.move(1);
            else if(tecla == 's' && j1.getY() < 22)
                j1.move(0);
            else if (tecla == 'i' && j2.getY() > 3)
                j2.move(1);
            else if (tecla == 'k' && j2.getY() < 22)
                j2.move(0);

            j1.draw(); j2.draw();
        }
        cout.flush();
        //rlutil::msleep(5);
    }
}

void drawMap()
{
    for(int i = 2; i < 60; i++)
    {
        gotoxy(i, 1);
        cout << "#";

        gotoxy(i, 24);
        cout << "#";
    }

    for (int i =2; i < 24; i++)
    {
        gotoxy(1,i);
        cout << "#";

        gotoxy(60,i);
        cout << "#";
    }

    for (int i = 2; i < 24;i++)
    {
        gotoxy(30,i); cout << "|";
    }

    gotoxy(25,5); cout << "0";
    gotoxy(35,5); cout << "0";
    
}

