
class Joueur
{

private:
    int vie;
    int jump;
    int speed;
    int pos_x;
    int pos_y;

public:
    Joueur();
    Joueur(int v, int j, int s);

    // setter /getters
    void setVie(int v); // Setter de la vie
    int getVie();       // Getter de la vie

    void setJump(int j);
    int getJump();

    void setSpeed(int s);
    int getSpeed();

    void setPosX(int x);
    void setPosY(int y);
    int getPosX();
    int getPosY();
};
