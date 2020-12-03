#include "rlutil.h"
#include <iostream>

using namespace std;

#define waitkey rlutil::anykey("Presiona cualquier tecla para continuar...\n")
#define startkey rlutil::anykey("Pulse cualquier tecla para comenzar...\n")
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
     1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1,};
    
    rlutil::hidecursor();

    showMap(map);
    
    
    startkey;

    rlutil::cls();
    rlutil::showcursor();

}

void showMap(int m[mapF][mapC])
{
    object ball; 
    int x = 0, y = 2;
    for(int i = 0; i < mapF;i++,y++)
    {
        rlutil::locate(x,y);
        for(int j = 0; j < mapC;j++,x+=2)
        {
            switch(m[i][j])
            {
                case 0:
                    cout << " ";
                    break;
                case 1:
                    cout << "#";
                    break;
                case 2:
                    cout<< "0";
                    break;
                case 3:
                    cout << "|";
                    break;
                case 4:
                    ball.x = x; ball.y = y; ball.val = 'o';
                    cout << "o";
                    break;
            }
        }
        x = 0;
    }
    cout << endl;
}