#include "rlutil.h"
#include "Player.h"
#include "Ball.h"
#include "GameRecord.h"
#include <string>
using namespace std;

#define startkey rlutil::anykey("Pulse cualquier tecla para comenzar...\n\n")
#define waitkey rlutil::anykey("Pulse cualquier tecla para continuar...\n\n")

static Player j1(5,12);
static Player j2(56,12);
static GameRecord record;
void game();
void menu();
void drawMap();
void historial();
void setName(Player *p, int n);

struct delimiter : std::ctype<char> {
  delimiter() : std::ctype<char>(get_table()) {}
  static mask const* get_table()
  {
    static mask rc[table_size];
    rc['\n'] = std::ctype_base::space;
    rc['\n'] = std::ctype_base::space;
    return &rc[0];
  }
};

int main()
{
    rlutil::cls();
    rlutil::hidecursor();
    cin.imbue(locale(cin.getloc(), new delimiter));
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
                    setName(&j1, 1);
                    setName(&j2, 2);
                    game();
                }else if (counter == 2)
                {
                    historial();
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
        gotoxy(i, 2);
        cout << "#";

        gotoxy(i, 24);
        cout << "#";
    }

    for (int i =3; i < 24; i++)
    {
        gotoxy(1,i);
        cout << "#";

        gotoxy(60,i);
        cout << "#";
    }

    for (int i = 3; i < 24;i++)
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
    gotoxy(14,1);
    startkey;
    gotoxy(14,1); cout << "   Consigue 7 puntos para ganar!         ";
    
    int cont = 0;
    while(true)
    {
        drawMap();
        if(kbhit())
        {
            rlutil::cls();
            drawMap();
            char tecla = getch();
            if(tecla == 'w' && j1.getY() >  4)
                j1.move(1);
            else if(tecla == 's' && j1.getY() < 22)
                j1.move(0);
            else if (tecla == 'i' && j2.getY() > 4)
                j2.move(1);
            else if (tecla == 'k' && j2.getY() < 22)
                j2.move(0);

            j1.draw(); j2.draw();
        }
        int punto;
        if (!cont++) punto = ball.move(&j1, &j2);
        if(cont > 5) cont = 0;

        if (j1.getPuntos() == 7 || j2.getPuntos() == 7)
        {
            rlutil::cls();
            record.addGame(j1.getNick(),j2.getNick(), j1.getPuntos(), j2.getPuntos());
            j1.setCoordinates(5,12); 
            j2.setCoordinates(56,12); 
            ball.reset();
            gotoxy(2,2); cout << "score: "  << j1.getNick() << ": " << j1.getPuntos() << " - " << j2.getNick() << ": " << j2.getPuntos();
            gotoxy(2,4); waitkey;
            rlutil::cls();
            j1.reset(); j2.reset();
            break;
        }

        if(punto)
        {
            drawMap();
            ball.clean(); j1.clean(); j2.clean();
            ball.setCoordinates(30,12); ball.draw();
            j1.setCoordinates(5,12); j1.draw(); 
            j2.setCoordinates(56,12); j2.draw();
            gotoxy(14,1);
            waitkey;
            gotoxy(14,1); cout << "   Consigue 7 puntos para ganar!         ";

            punto = !punto;
        }

        rlutil::msleep(10);
        cout.flush();
    }
}

void historial()
{
    gotoxy(38,1); cout << "Pulsa \"q\" en cualquier momento para regresar al menu";
    char key = 'a';
    while(key != 'q')
    {
        record.print();
        key = getch();
    }
    rlutil::cls();
}

void setName(Player *p, int n)
{
    string name;
    rlutil::showcursor();
   do
    {
        gotoxy(2,3); cout << "Ingrese el nickname del jugador " << n << " (maximo 12 caracteres): ";
        cin >> name;
        if(name.length() > 12)
        {
            rlutil::cls();
            gotoxy(2,1); cout << "Error: el nickname no debe contener mas de 12 caracteres! Vuelve a intentar";
        }
    } while(name.length() > 12);

    p->setNick(name);
    rlutil::cls();
    rlutil::hidecursor();
    getch(); //Evita que el juego inicie sin esperar el teclado, linea 149 startkey detectaba la ultima tecla presionada y seguia
}
