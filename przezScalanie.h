#ifndef PRZEZSCALANIE_H_INCLUDED
#define PRZEZSCALANIE_H_INCLUDED

#include "lista.h"

template <typename TYP>
void mPodziel(SLista<TYP> &S, SLista<TYP> &S1, SLista<TYP> &S2, unsigned int ilosc){
    unsigned int n;
    n = (ilosc%2 ? (ilosc-1)/2+1 : ilosc/2);    //indeks srodka
    while(n>0){
       S1.dodajTyl(S.usunZwrocWartPrzod());
       n = n-1;
    }
    while(!S.czyPusta())
       S2.dodajTyl(S.usunZwrocWartPrzod());
}



template <typename TYP>
void mScal(SLista<TYP> &S, SLista<TYP> &S1, SLista<TYP> &S2, bool tryb){

    while(!S1.czyPusta() && !S2.czyPusta()){
            if(tryb){
                if (S1.przodwar() <= S2.przodwar())
                    S.dodajTyl(S1.usunZwrocWartPrzod());
                else
                    S.dodajTyl(S2.usunZwrocWartPrzod());
            }else{
                if (S1.przodwar() >= S2.przodwar())
                    S.dodajTyl(S1.usunZwrocWartPrzod());
                else
                    S.dodajTyl(S2.usunZwrocWartPrzod());
            }
    }
    while (!S1.czyPusta())
        S.dodajTyl(S1.usunZwrocWartPrzod());
    while (!S2.czyPusta())
        S.dodajTyl(S2.usunZwrocWartPrzod());
}



template <typename TYP>
SLista<TYP>& SortScalanie(SLista<TYP> &S, bool tryb = true){
    unsigned int n;
    if ((n = S.Rozmiar()) > 1) {
        SLista<TYP> S1;
        SLista<TYP> S2;
        mPodziel(S, S1, S2, n);
        SortScalanie(S1, tryb);
        SortScalanie(S2, tryb);
        S.wyczyscListe();
        mScal(S, S1, S2, tryb);
    }
    return S;
}


#endif // PRZEZSCALANIE_H_INCLUDED
