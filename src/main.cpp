#include <Arduino.h>
#include <defines_matrice.h>
#include <classe_joueur.h>

//***********************************//
// Creation des etats des differentes parties du programme
//***********************************//

enum Etat
{
  ETAT_TITRE,    // Etat du menu principal
  ETAT_JEU,      // Etat du jeu en cours
  ETAT_GAMEOVER, // Etat de l'ecran de fin de jeu
  ETAT_RESETTING // Etat de reinitialisation du jeu
};

Etat etatActuel = ETAT_TITRE; // Initialisation de l'etat actuel

//************************************************//

void test()
{
  Joueur joueurp1;
  Serial.print(" Stats joueur 1: ");
  Serial.print(joueurp1.getVie());
  Serial.print(" ");
  Serial.print(joueurp1.getJump());
  Serial.print(" ");
  Serial.println(joueurp1.getSpeed());

  delay(3000);

  joueurp1.setVie(50);
  joueurp1.setJump(5);
  joueurp1.setSpeed(2);

  Serial.print(" Stats Updated joueur 1: ");
  Serial.print(joueurp1.getVie());
  Serial.print(" ");
  Serial.print(joueurp1.getJump());
  Serial.print(" ");
  Serial.println(joueurp1.getSpeed());

  delay(3000);

  Joueur joueurp2(25, 4, 1);

  Serial.print(" Stats joueur 2: ");
  Serial.print(joueurp2.getVie());
  Serial.print(" ");
  Serial.print(joueurp2.getJump());
  Serial.print(" ");
  Serial.println(joueurp2.getSpeed());

  delay(3000);
}

//************************************************//

void affiche_joueur(int pos_x, int pos_y)
{
  matrix.drawRect(pos_x, pos_y, 4, 4, matrix.Color888(255, 255, 0));
}

void efface_joueur(int pos_x, int pos_y)
{
  matrix.drawRect(pos_x, pos_y, 4, 4, matrix.Color888(0, 0, 0));
}

//************************************************//

void animation_titre()
{
  int pos_x = 1;
  int last_pos_x = 1;
  pos_x = constrain(pos_x, 1, 58);
  affiche_joueur(1, 27);

  for (int i = 0; i < 58; i++)
  {
    efface_joueur(last_pos_x, 27);
    pos_x++;
    affiche_joueur(pos_x, 27);
    last_pos_x = pos_x;
    delay(100);
  }
  if (pos_x >= 58)
  {
    efface_joueur(pos_x, 27);
  }
}

//*************************************************//

void titre()
{
  // Delimitation de la zone de dessin

  matrix.drawLine(0, 0, 63, 0, (matrix.Color888(255, 255, 0)));   // Haut
  matrix.drawLine(0, 0, 0, 31, (matrix.Color888(255, 255, 0)));   // Gauche
  matrix.drawLine(63, 0, 63, 31, (matrix.Color888(255, 255, 0))); // Droite
  matrix.drawLine(0, 31, 63, 31, (matrix.Color888(255, 255, 0))); // Bas

  // Delimitation autour du titre
  matrix.drawLine(18, 10, 44, 10, (matrix.Color888(255, 255, 0))); // Haut
  matrix.drawLine(18, 20, 44, 20, (matrix.Color888(255, 255, 0))); // Bas
  matrix.drawLine(18, 10, 18, 20, (matrix.Color888(255, 255, 0))); // Gauche
  matrix.drawLine(44, 10, 44, 20, (matrix.Color888(255, 255, 0))); // Droite

  // Zone pour le texte
  matrix.setTextSize(1);                            // Taille du texte
  matrix.setTextWrap(true);                         // Permet le retour a la ligne automatique
  matrix.setCursor(20, 12);                         // Position du texte
  matrix.setTextColor(matrix.Color888(255, 0, 55)); // Couleur du texte en Orange
  matrix.print("DASH");                             // Affichage du texte

  // Zone pour le joueur
  animation_titre();

  if (!isBitSet(PINC, BTN_C))
  {
    etatActuel = ETAT_JEU;
    matrix.fillScreen(matrix.Color333(0, 0, 0));
  }
}

void setup()
{
  DDRG = DDRG | B00000111; //
  DDRL = setBitM(DDRL, B11111100);
  PORTG &= B00100000; //

  // configuration des boutons en entrer
  DDRC = clearBitM(DDRC, B11111110);
  PORTC = setBitM(DDRC, B11111110);
  DDRF = clearBitM(DDRF, B11000000);
  Serial.begin(9600);
  matrix.begin();
  etatActuel = ETAT_TITRE;
}

void loop()
{
  // test();
  // titre();
  // affiche_joueur(1, 27);
  // Gestion des etats de la machine
  switch(etatActuel)

  {

  case ETAT_TITRE:
    titre();
    break;

  //case ETAT_JEU:
    // jeu();
    // break;

    // case ETAT_GAMEOVER:
    // gameOver();
    // break;

    // case ETAT_RESETTING:
    //  resetting();
    //  break;
  }
}
