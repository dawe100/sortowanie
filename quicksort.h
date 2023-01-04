#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

#include "lista.h"

template <typename TYP>
void qPodziel(SLista<TYP> &S, SLista<TYP> &L, SLista<TYP> &E, SLista<TYP> &G, unsigned int piwot){

    TYP x = S.zwrocElement(piwot);
    while(!S.czyPusta()){
        TYP y = S.usunZwrocWartPrzod();
        if (y < x)
            L.dodajTyl(y);
        else if (y == x)
            E.dodajTyl(y);
        else
            G.dodajTyl(y);
    }
}



template <typename TYP>
void qPolacz(SLista<TYP> &S, SLista<TYP> &L, SLista<TYP> &E, SLista<TYP> &G){

        while(!L.czyPusta())
            S.dodajTyl(L.usunZwrocWartPrzod());
        while(!E.czyPusta())
            S.dodajTyl(E.usunZwrocWartPrzod());
        while(!G.czyPusta())
            S.dodajTyl(G.usunZwrocWartPrzod());
}



template <typename TYP>
SLista<TYP>& Quicksort(SLista<TYP> &S){

    unsigned int n;
    if ((n = S.Rozmiar()) > 1) {
        SLista<TYP> L;
        SLista<TYP> E;
        SLista<TYP> G;
        unsigned int piwot = (n%2 ? (n-1)/2 : n/2); //wybor el. srodkowego jako piwota

        qPodziel(S, L, E, G, piwot);
        Quicksort(L);
        Quicksort(G);
        S.wyczyscListe();
        qPolacz(S, L, E, G);
    }
    return S;
}

#endif // QUICKSORT_H_INCLUDED
