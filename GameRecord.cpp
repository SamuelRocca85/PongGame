#include "GameRecord.h"

void GameRecord::addGame(string p1, string p2, int s1, int s2)
{
    node* nuevo = new node(); 
    nuevo->player_1 = p1; nuevo->player_2 = p2;
    nuevo->score_1 = s1; nuevo->score_2 = s2;
    nuevo->next = nullptr;
    if(isEmpty())
    {
        first = nuevo;
        return;
    }

    node* n = first;

    while(n->next != nullptr)
    {
        n = n->next;
    }
    n->next = nuevo;
}

void GameRecord::print()
{
     
    if(isEmpty())
    {
        gotoxy(2,2);cout << "No hay historial aun! juega para crear un historial";
        return;
    }

    gotoxy(2,1); cout << "Player 1";
    gotoxy(15,1); cout << "Player 2";
    gotoxy(28,1); cout  << "Score";
    int y = 3;
    node* n = first;
    while(n != nullptr)
    {
        gotoxy(2,y); cout << n->player_1;
        gotoxy(15,y); cout << n->player_2;
        gotoxy(28,y); cout << n->score_1 << " - " << n->score_2;
        y+=2;
        n = n->next;
    }

}
