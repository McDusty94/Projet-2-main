
class Joueur
{

private:
    int vie;
    int jump;
    int speed;

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
};
