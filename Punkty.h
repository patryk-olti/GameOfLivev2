class Punkt{
    int x;
    int y;

    public:
    ~Punkt();
    Punkt * losowaniePunktow(int , int , int);
    void wyswietlPunkty(Punkt *, int);
    int getX();
    int getY();
    void setX(int);
    void setY(int);

    friend Punkt * tableOfGame(Punkt *, int, int, int);
};
