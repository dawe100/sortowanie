#ifndef PRZEZKOPCOWANIE_H_INCLUDED
#define PRZEZKOPCOWANIE_H_INCLUDED


template <typename TYP>
void zamien(TYP *tab, int k, int j){
    TYP temp = tab[k];
    tab[k] = tab[j];
    tab[j] = temp;
}


template <typename TYP>
void downheap(TYP *tab, int o, int ilosc){
    int s = 2*o;        //lewy syn
    while(s <= ilosc){  //dopóki syn s jest w zakresie drzewa
        if(s < ilosc && tab[s] < tab[s+1])  //porownanie lewego i prawego syna
            s++;
        if(tab[o] >= tab[s])   //gdy w³asnosc podkopca zachowana wychodzi z pêtli
            break;
        zamien(tab, o, s);
        o = s; s = 2*o;
    }
}


template<typename TYP>
void SortKopcowanie(TYP *tab, int ilosc){
    for(int k=ilosc/2; k>=1; k--)
        downheap(tab, k, ilosc);
    while(ilosc>1){
        zamien(tab, 1, ilosc);
        ilosc--;
        downheap(tab, 1, ilosc);
    }
}


template<typename TYP>
bool czyDobrze(TYP *tab, int rozmiar){
    for (int i=1; i<rozmiar; i++){
        if (tab[i+1] < tab[i])
            return false;
    }
    return true;
}


#endif // PRZEZKOPCOWANIE_H_INCLUDED
