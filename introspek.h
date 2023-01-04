#ifndef INTROSPEK_H_INCLUDED
#define INTROSPEK_H_INCLUDED

#include <cmath>
#include "lista.h"
#include "quicksort.h"
#include "przezKopcowanie.h"

template <typename TYP>
void Lista_do_tablica(SLista<TYP> &S, TYP *tab){

    int i = 1;
    while(!S.czyPusta()){
        tab[i] = S.usunZwrocWartPrzod();
        i++;
    }
}



template <typename TYP>
void Tablica_do_lista(SLista<TYP> &S, TYP *tab, int wymiar){

    for(int i=1; i<=wymiar; i++){
        S.dodajTyl(tab[i]);
    }
}




template <typename TYP>
SLista<TYP>& introSort(SLista<TYP> &S, int poziom){

    unsigned int n = S.Rozmiar();

    if (n <= 1) return S;                     //gdy jeden element w zbiorze

    if (poziom <= 0){                         //sortowanie przez kopcowanie
        int *tab = new int[n+1];
        Lista_do_tablica(S, tab);
        SortKopcowanie(tab, n);
        Tablica_do_lista(S, tab, n);
        delete tab;
    } else {
        SLista<TYP> L;
        SLista<TYP> E;
        SLista<TYP> G;
        unsigned int piwot = (n%2 ? (n-1)/2 : n/2); //wybor el. srodkowego jako piwota

        qPodziel(S, L, E, G, piwot);
        introSort(L, poziom-1);
        introSort(G, poziom-1);
        S.wyczyscListe();
        qPolacz(S, L, E, G);
    }
    return S;
}


template <typename TYP>
void introspektywne(SLista<TYP> &S){

    int poziom = log2(S.Rozmiar());
    introSort(S, poziom*2);
}

#endif // INTROSPEK_H_INCLUDED
