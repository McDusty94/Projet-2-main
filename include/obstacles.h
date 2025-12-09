class Obstacles
{
    private:
        int pos_x;
        int pos_y;
        int speed;

    public:
        Obstacles();
        Obstacles(int x, int y, int s);

        void setPosX(int x);
        void setPosY(int y);
        int getPosX();
        int getPosY();

        void setSpeed(int s);
        int getSpeed();
        
};