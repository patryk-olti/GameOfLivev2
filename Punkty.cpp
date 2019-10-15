#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Punkty.h"

using namespace std;

Punkt::~Punkt(){
    delete this;
}
Punkt * Punkt::losowaniePunktow(int wys, int szer, int ilosc){

    Punkt * zbior = new Punkt [ilosc];

    if(wys <= 0 || szer <= 0){
        delete [] zbior;
        return NULL;
    }
    else
    {
        srand(time(NULL));

        for(int i=0; i<ilosc; i++){
            (zbior[i]).x = ((rand() % (szer-2))+1);
            (zbior[i]).y = ((rand() % (wys-2)) + 1);

            for(int j=0; j<i+1; j++){
                if( ( ( (zbior[i].x == zbior[j].x) && (zbior[i].y == zbior[j].y) ) && i!=j  )){
                    i--;
                    break;
                }
            }
        }
        return &zbior[0];
    }
}

void Punkt::wyswietlPunkty(Punkt * wsk, int ilosc){
    for(int i=0; i<ilosc; i++){
        cout<<"x"<<i+1<<" = "<<wsk[i].x<<" and y"<<i+1<<" = "<<wsk[i].y<<endl;
    }
}

int Punkt::getX(){
    return x;
}

int Punkt::getY(){
    return y;
}

void Punkt::setX(int x){
    this->x = x;
}

void Punkt::setY(int y){
    this->y = y;
}
