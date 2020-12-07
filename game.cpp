#include "rlutil.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

//#define waitkey rlutil::anykey("Presiona cualquier tecla para continuar...\n")
#define startkey rlutil::anykey("Pulse cualquier tecla para comenzar...\n\n")
#define mapC 28
#define mapF 10

struct object
{
    int x;
    int y;
    char val;
};


void showMap(int m[mapF][mapC]);

int main()
{
    rlutil::cls();
    int map[mapF][mapC] = 
    {1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1,
     1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,2 ,0 ,3 ,0 ,2 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1,
     1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1,
     1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,3 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1,
     1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,4 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1,
     1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,3 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1,
     1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1,
     1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,3 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1,
     1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1,
     1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1};
    
    //rlutil::hidecursor();
    int option = 0;

    do{
        rlutil::showcursor();
        rlutil::setColor(5);
        cout <<"    * * * PONG * * *\n";
        rlutil::setColor(15);
        cout << "1. Jugar\t2. Salir" << endl << "Seleccione la opcion que desea: ";
        cin >> option;

        switch (option)
        {
        case 1:
            rlutil::setColor(10); 
            showMap(map);
            startkey;
            break;
        case 2:
            exit(0);
            break;
        }

    }while(option != 2);
    
    
    
    rlutil::cls();
    rlutil::showcursor();

}

void showMap(int m[mapF][mapC])
{
    object ball; ball.obj = 'o';
    rlutil::hidecursor();
    rlutil::cls();
    rlutil::locate(8,0); cout << "J1";
    rlutil::locate(20,0); cout << "J2";
    int x = 0, y = 2;
    for(int i = 0; i < mapF;i++,y++)
    {
        rlutil::locate(x,y);
        for(int j = 0; j < mapC;j++,x++)
        {
            switch(m[i][j])
            {
                case 0: cout << " "; break;
                case 1: cout << "#"; break;
                case 2: cout << "0"; break;
                case 3:
                    rlutil::setColor(15); 
                    cout << "|"; 
                    rlutil::setColor(10);
                    break;
                case 4:
                    ball.x = x; ball.y = y; rlutil::locate(ball.x+ 1 , ball.y);
                    cout << ball.obj;
                    rlutil::setColor(9); 
                    ball.obj = 'o';
                    rlutil::setColor(10); 
                    break;
            }
        }
        x = 0;
    }
    cout << endl << endl << endl;

    while(ball.x > 2)
    {
        gotoxy(ball.x,ball.y); std::cout << " ";
        ball.x--;
        gotoxy(ball.x , ball.y);
        cout << ball.obj;
    }

    rlutil::locate(0,14);
    cout.flush();
}