#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "przezScalanie.h"
#include "quicksort.h"
#include "przezKopcowanie.h"
#include "introspek.h"


template <typename TYP>
void Generuj_losowo(SLista<TYP> &Lista, int wymiar, float procent = 0){

    Lista.wyczyscListe();
    int wybor = rand();
    float granica = (100-procent)*wymiar*0.01;

    while(wymiar > granica){                //dodanie mniejszych od granicy
        Lista.dodajPrzod(rand()%wybor);
        wymiar--;
    }
    SortScalanie(Lista, true);              //sortowanie poczatku listy
    while(wymiar > 0){                      //dodanie reszty (>granicy)
        Lista.dodajTyl(rand()+wybor);
        wymiar--;
    }
}



template <typename TYP>
void Generuj_odwrotnie(SLista<TYP> &Lista, int ilosc){

    Lista.wyczyscListe();
    for(int i=0; i<ilosc; i++){
        Lista.dodajPrzod(rand());
    }
    SortScalanie(Lista, false);            //sortowanie malejaco
}



template <typename TYP>
void Generuj_losowo(TYP *tablica, int wymiar, float procent = 0){

    int wybor = rand();
    float granica = (100-procent)*wymiar*0.01;
    int i = 1;
    tablica[0] = 0;

    while(wymiar > granica){                //dodanie mniejszych od granicy
        tablica[i] = rand()%wybor;
        wymiar--;
        i++;
    }
   SortKopcowanie(tablica, i);            //sortowanie poczatku listy
    while(wymiar > 0){                      //dodanie reszty (>granicy)
        tablica[i] = rand()+wybor;
        wymiar--;
        i++;
    }
}


template <typename TYP>
void Generuj_odwrotnie(TYP *tablica, int wymiar){

    Generuj_losowo(tablica, wymiar, 100);
    for (int i=1; i<=wymiar/2; i++){
        TYP temp = tablica[i];
        tablica[i] = tablica[wymiar-i+1];
        tablica[wymiar-i+1] = temp;
    }
}





int Wykonaj(int wymiar, float procent = 0, unsigned int sortowanie = 0){

    int suma_czas = 0;
    int sprawdzenie = 0;
    SLista<int> Lista;
    int *tab2 = new int[wymiar+1];


    for(int i=0; i<100; i++){
        if(procent >= 0)
            if(sortowanie == 2)
                Generuj_losowo(tab2, wymiar, procent);
            else
                Generuj_losowo(Lista, wymiar, procent);
        else
            if(sortowanie == 2)
                Generuj_odwrotnie(tab2, wymiar);
            else
                Generuj_odwrotnie(Lista, wymiar);

        clock_t czas = clock();             //START POMIARU CZASU

        if(sortowanie == 0)
            SortScalanie(Lista);
        else if (sortowanie == 1)
            Quicksort(Lista);
        else if (sortowanie == 2)
            SortKopcowanie(tab2, wymiar);
        else if (sortowanie == 3)
            introspektywne(Lista);

        suma_czas += clock() - czas;        //STOP POMIARU CZASU

        if (sortowanie == 2)
            sprawdzenie += czyDobrze(tab2, wymiar);
        else
            sprawdzenie += Lista.czyDobrze();
    }
    if (sprawdzenie == 100)
        cout << endl << "Posortowano prawidlowo" << endl;
    else
        cout << endl << "Posortowano blednie" << endl;

    delete tab2;
    return suma_czas;
}




int main()
{
    srand((int)time(NULL));
    int wymiar[] = {10000, 50000, 100000, 500000, 1000000};
    float procent[] = {0, 25, 50, 75, 95, 99, 99.7, -1};

    int wczrodzaj, wczwymiar, wczprocent;

    ofstream plik;
    plik.open ("wyniki.txt");

    cout << "Sortowanie!\n 0-przez scalanie\n 1-szybkie\n 2-przez kopcowanie\n 3-introspektywne\n" << endl;
    cin >> wczrodzaj;
    cout << "Podaj wymiar:\n";
    cin >> wczwymiar;
    cout << "Podaj procent posortowania:\n";
    cin >> wczprocent;
    cout << endl << "Czas: " << Wykonaj(wczwymiar, wczprocent, wczrodzaj)/100 << "ms";

                            //(rozmiar, procent posort (gdy <0 odwrotna kolejnosc), sortowanie)
                            //sortowanie: 0-scalanie, 1-szybkie, 2-kopcowanie, 3-introspektywne
   /*for(int k=0; k<4; k++){
       for(int j=0; j<5; j++){
        for (int i=0; i<8; i++)
            plik << Wykonaj(wymiar[j], procent[i], k) << endl;
        plik << endl;
        cout << "koniec" << endl;
    }*/

    return 0;
}
