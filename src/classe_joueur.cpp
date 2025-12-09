#include <classe_joueur.h>
#include <defines_matrice.h>

Joueur::Joueur() // Constructeur de base
{
	vie = 100; // Initialisation de la vie à 100
	jump = 10; // Initialisation de la capacité de saut
	speed = 5; // Initialisation de la vitesse
	pos_x = 5;
	pos_y = HAUTEUR_MATRICE - 10;
}
//************************************************/

Joueur::Joueur(int v, int j, int s) // Constructeur de base
{
	vie = v;   // Initialisation de la vie à 100
	jump = j;  // Initialisation de la capacité de saut
	speed = s; // Initialisation de la vitesse
	pos_x = 5;
	pos_y = HAUTEUR_MATRICE - 10;
}

//************************************************//
void Joueur::setVie(int v)
{
	vie = v;
} // Setter de la vie

int Joueur::getVie()
{
	return vie;
} // Getter de lavie

//************************************************/

void Joueur::setPosX(int x)
{
	pos_x = x;
}
void Joueur::setPosY(int y)
{
	pos_y = y;
}
int Joueur::getPosX()
{
	return pos_x;
}
int Joueur::getPosY()
{
	return pos_y;
}

void Joueur::setJump(int j)
{
	jump = j;
} // Setter de la vie

int Joueur::getJump()
{
	return jump;
} // Getter de la jump

//************************************************/

void Joueur::setSpeed(int s)
{
	speed = s;
} // Setter de la speed

int Joueur::getSpeed()
{
	return speed;
} // Getter de la speed

//************************************************/