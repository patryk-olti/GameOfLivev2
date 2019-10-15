#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include "Punkty.h"

using namespace std;

Punkt * tableOfGame(Punkt *, int, int, int);
void gameOfLive(Punkt **, int, int , int, int);
void wyswietlMapa(Punkt *, int , int , int);
void menu(int, int, int, int);

int main()
{
    int wys     = 10,
        szer    = 10,
        ilosc   = 20,
        ileRund = 10;

    menu(wys, szer, ilosc, ileRund);

    return 0;
}

Punkt * tableOfGame(Punkt * wsk, int wys, int szer, int ilosc){
    int tab[wys][szer];
    int tab2[wys][szer];
    int rozmiar = 0;

    // POMOCNICZE TABLICE
    for(int i=0; i<wys; i++){
        for(int j=0; j<szer; j++){
            tab[i][j] = 0;
            tab2[i][j] = 0;
    }   }

    for(int k=0; k<ilosc; k++){
        for(int i=0; i<wys; i++){
            for(int j=0; j<szer; j++){
                if(wsk[k].getX() == j && wsk[k].getY() == i){
                    tab[i][j] = 1;
                    break;
    }   }   }   }

    for(int i=1; i<wys-1; i++){
        for(int j=1; j<szer-1; j++){

            int result = 0;

            for(int k=-1; k<2; k++){
                for(int l=-1; l<2; l++){

                    if((tab[i+k][j+l] == 1)){
                        result++;
            }   }   }

            if(tab[i][j] == 1){
                result--;
            }

            if(result < 2 || result > 4){
                tab2[i][j] = 0;
            }

            if(result > 1 && result < 5){
                if(tab[i][j] == 1){
                    tab2[i][j] = 1;
                }
            }

            if(tab[i][j] == 0 && result == 3){
                tab2[i][j] = 1;
    }   }   }

    rozmiar = 0;
    for(int i=0; i<wys; i++){
        for(int j=0; j<szer; j++){
            if(tab2[i][j] == 1)
                rozmiar++;

            tab[i][j] = tab2[i][j];
    }   }

    // NOWA ALOKACJA PAMIECI
    //Punkt * zbior = new Punkt [rozmiar];
    int k = 0;

    for(int i=0; i<wys; i++){
        for(int j=0; j<szer; j++){

            if(tab[i][j] == 1){
                wsk[k].setX(j);
                wsk[k].setY(i);
                tab[i][j] = 0;
                k++;
    }   }   }

    return &wsk[0];
}


void gameOfLive(Punkt ** tab_wsk, int ilosc, int szer, int wys, int runda){

    cout<<"Game of Live v.0.1."<<endl;

    for(int i=1; i<runda; i++){
        cout<<"Runda: "<<i+1<<endl;
        tab_wsk[i] = tableOfGame(tab_wsk[i-1], wys, szer, ilosc);
        wyswietlMapa(tab_wsk[i], ilosc, szer, wys);
    }
}

void wyswietlMapa(Punkt * wsk, int ilosc, int szer, int wys){
    char tab[szer][wys];

    for(int i=0; i<wys; i++){
        for(int j=0; j<szer; j++){

            if(i==0 && j>0 && j<szer){  tab[j][i] = 205;    }
            if(i==wys-1 && j>0 && j<szer){  tab[j][i] = 205;    }
            if(i>0 && i<wys && j == 0){ tab[j][i] = 186;    }
            if(i>0 && i<wys && j == szer-1){ tab[j][i] = 186;    }

            if(i==0 && j==0){       tab[j][i] = 201;    }
            if(i==0 && j==szer-1){    tab[j][i] = 187;    }
            if(i==wys-1 && j==0){     tab[j][i] = 200;    }
            if(i==wys-1 && j==szer-1){  tab[j][i] = 188;    }
        }
    }

    for(int i=1; i<wys-1; i++){
        for(int j=1; j<szer-1; j++){
            tab[j][i] = ' ';
        }
    }

    for(int i=0; i<ilosc; i++){
        tab[ wsk[i].getX() ][ wsk[i].getY() ] = 'x';
    }

    for(int i=0; i<wys; i++){
        cout<<endl;
        for(int j=0; j<szer; j++){
            cout<<tab[j][i]<<" ";
        }
    }
    cout<<endl;
}

void menu(int wys, int szer, int ilosc, int ileRund){

    int znak, exit = 0;
    Punkt obj;
    Punkt ** wsk = new Punkt * [ileRund];

while(exit==0){

    cout<<"Parametry symulacji."<<endl<<"Wysokosc mapy: "<<wys<<" szerokosc mapy: "<<szer<<endl;
    cout<<"Ile osobnikow na start: "<<ilosc<<" ile Rund trwa symulacja: "<<ileRund<<endl;
    cout<<"1. Wygeneruj losowa tablice."<<endl;
    cout<<"2. Wyswietl poczatkowa mape."<<endl;
    cout<<"3. Rozpocznik symulacje."<<endl;
    cout<<"4. Zmien parametry."<<endl;
    cout<<"5. Zakoncz program."<<endl;

    cin>>znak;
    system("CLS");

    switch(znak){
        case 1:{
            wsk[0] = obj.losowaniePunktow(wys, szer, ilosc);
        }
        break;

        case 2:{
            wyswietlMapa(wsk[0], ilosc, szer, wys);
        }
        break;

        case 3:{
            gameOfLive(wsk, ilosc, szer, wys, ileRund);
        }
        break;

        case 4:{
            cout<<"Podaj ilosc osobnikow: ";
            cin>>ilosc;
            cout<<"Podaj ilosc rund: ";
            cin>>ileRund;
        }
        break;

        case 5:{
            exit = 1;
            cout<<"Dzieki za udzial w symulacji!";
            for(int i=0; i<ileRund; i++)
                delete wsk[i];

            delete [] wsk;
        }
        break;

        default:{

        }
        break;
    }
}
}
