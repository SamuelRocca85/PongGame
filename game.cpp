#include "rlutil.h"
#include "Player.h"
#include "Ball.h"
#include <string>
using namespace std;

#define startkey rlutil::anykey("Pulse cualquier tecla para comenzar...\n\n")

Player j1(5,12);
Player j2(56,12);

void game();
void menu();
void drawMap();

int main()
{
    rlutil::cls();
    rlutil::hidecursor();
    menu();
}

void menu()
{
    int set[3] = {12,10,10}; //Lista de colores para colorear de rojo la opcion seleccionada
    int counter = 1;
    char key;

    while(true)
    {
        rlutil::setColor(10);
        gotoxy(3,1); cout << "Seleccione una opcion:" ;
        gotoxy(27,2); cout << "Controles:";
        gotoxy(27,3); cout << "S: Desplazarse hacia abajo";
        gotoxy(27,4); cout << "W: Desplazarse hacia arriba";
        gotoxy(27,5); cout << "Enter: Aceptar/Seleccionar";

        rlutil::setColor(set[0]);
        gotoxy(3,3); cout << "Jugar";

        rlutil::setColor(set[1]);
        gotoxy(3,4); cout << "Historial de partidas";  
        
        rlutil::setColor(set[2]);
        gotoxy(3,5); cout << "Salir";  

        if (counter == 1)
            gotoxy(1,3);
        else if (counter == 2)
            gotoxy(1,4);
        else
            gotoxy(1,5);
        
        rlutil::setColor(9); cout << "=>";

        if (kbhit())
        {
            rlutil::cls();
            key = getch();
            if (key == 'w' && (counter >= 2 && counter <= 3))
                counter--;
            if (key == 's' && (counter >= 1 && counter <= 2))
                counter++;

            if (key == '\r')
            {
                //rlutil::cls();
                if (counter == 1)
                {
                    game();
                }else if (counter == 2)
                {
                    //TODO historial aqui
                }else if (counter == 3)
                {
                    rlutil::showcursor();
                    exit(0);
                }
            }

            set[0] = 10; set[1] = 10; set[2] = 10;

            if (counter == 1)
                set[0] = 12;
            else if (counter == 2)
                set[1] = 12;
            else
                set[2] = 12;
            
        }
    }
}

void drawMap()
{
    for (int i = 2; i < 60; i++)
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

    gotoxy(25,5); cout << j1.getPuntos();
    gotoxy(35,5); cout << j2.getPuntos();
    
}

void game()
{
    rlutil::setColor(10);
    drawMap();
    Ball ball(30,12,1,1); ball.draw();
    j1.draw(); j2.draw();
    gotoxy(62,3);
    startkey;
    gotoxy(62,3); cout << "   Consigue 7 puntos para ganar!         ";
    
    int cont = 0;
    while(true)
    {
        drawMap();
        if(kbhit())
        {
            rlutil::cls();
            drawMap();
            char tecla = getch();
            if(tecla == 'q')
            {
                rlutil::cls();
                break;
            }
            if(tecla == 'w' && j1.getY() > 3)
                j1.move(1);
            else if(tecla == 's' && j1.getY() < 22)
                j1.move(0);
            else if (tecla == 'i' && j2.getY() > 3)
                j2.move(1);
            else if (tecla == 'k' && j2.getY() < 22)
                j2.move(0);

            j1.draw(); j2.draw();
        }
        if (!cont++) ball.move();
        if(cont > 5) cont = 0;
        rlutil::msleep(10);
        cout.flush();
    }
}
