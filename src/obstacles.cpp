#include <classe_joueur.h>
#include <defines_matrice.h>
#include <obstacles.h>

Obstacles::Obstacles() // Constructeur de base
{
    pos_x = LARGEUR_MATRICE - 1;
    pos_y = 15;
    speed = 1;
}

Obstacles::Obstacles(int x, int y, int s) // Constructeur avec paramètres
{
    pos_x = x;
    pos_y = y;
    speed = s;
}

void Obstacles::setPosX(int x)
{
    pos_x = x;
}

void Obstacles::setPosY(int y)
{
    pos_y = y;
}

int Obstacles::getPosX()
{
    return pos_x;
}
int Obstacles::getPosY()
{
    return pos_y;
}

void Obstacles::setSpeed(int s)
{
    speed = s;
}

int Obstacles::getSpeed()
{
    return speed;
}

