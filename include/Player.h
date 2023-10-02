#ifndef PLAYER_
#define PLAYER_
#include "Graphic.h"
#include <string>
using namespace std;

class Player : public Graphic
{
public:
    Player(int x, int y)
        : Graphic(x, y), puntos(0)
    {
    }

    void draw();
    void clean();
    void reset();
    void move(int dir);
    void anotar()
    {
        puntos++;
    }
    int getPuntos() const
    {
        return puntos;
    }
    string getNick()
    {
        return nickname;
    }
    void setNick(string nick)
    {
        nickname = nick;
    }

private:
    int puntos;
    string nickname;
};

#endif // PLAYER_