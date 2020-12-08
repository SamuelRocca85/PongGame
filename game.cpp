#include "rlutil.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

#define startkey rlutil::anykey("Pulse cualquier tecla para comenzar...\n\n")


void drawMap();

int main()
{
    rlutil::cls();
    drawMap();
    startkey;
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

    gotoxy(62,12);
}

