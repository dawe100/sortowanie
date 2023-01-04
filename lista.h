#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

using namespace std;


template <typename TYP>
class SLista;


template <typename TYP>
class SWezel{
  TYP wartosc;
  SWezel<TYP> *nastepny;
  friend class SLista<TYP>;
};



template <typename TYP>
class SLista{
    SWezel<TYP> *head;
    SWezel<TYP> *tail;
    unsigned int rozmiar;

 public:
    SLista();
    ~SLista();
    bool czyPusta() const;
    const TYP& przodwar() const {return head->wartosc;};
    void dodajPrzod(const TYP& nwart);
    void dodajTyl(const TYP& nwart);
    void usunPrzod();
    TYP usunZwrocWartPrzod();
    unsigned int Rozmiar(){return rozmiar;};
    void wyczyscListe();
    TYP zwrocElement(unsigned int indeks);
    void drukujListe();
    bool czyDobrze();
};


template <typename TYP>
SLista<TYP>::SLista(): head(NULL), tail(NULL), rozmiar(0){};  //konstruktor

template <typename TYP>
SLista<TYP>::~SLista(){                 //destruktor

    while(head != NULL){
      SWezel<TYP> *stary = head;
      head = stary->nastepny;
      delete stary;
    }
};


template <typename TYP>
bool SLista<TYP>::czyPusta() const{

    if(head != NULL)
        return false;
    return true;
}


template <typename TYP>
void SLista<TYP>::dodajPrzod(const TYP& nwart){

    SWezel<TYP> *nowy = new SWezel<TYP>;
    nowy->wartosc = nwart;
    nowy->nastepny = head;
    head = nowy;
    if (tail == NULL)       //gdy dodawany jest pierwszy element
        tail = head;
    ++rozmiar;
}


template <typename TYP>
void SLista<TYP>::usunPrzod(){

    if(head != NULL){
      SWezel<TYP> *stary = head;
      head = stary->nastepny;
       --rozmiar;
       delete stary;
    }
}


template <typename TYP>
TYP SLista<TYP>::usunZwrocWartPrzod(){

      SWezel<TYP> *stary = head;
      head = stary->nastepny;
      TYP wartstary;
      wartstary = stary->wartosc;
      delete stary;
      --rozmiar;
      return wartstary;
}


template <typename TYP>
void SLista<TYP>::dodajTyl(const TYP& nwart){

    SWezel<TYP> *nowy = new SWezel<TYP>;
    nowy->wartosc = nwart;
    nowy->nastepny = NULL;
    if (tail != NULL)           //gdy nie jest to pierwszy dodawany element
      tail->nastepny = nowy;
    tail = nowy;
    if (head == NULL)           //gdy jest to pierwszy dodawany element
      head = tail;
    ++rozmiar;
}



template <typename TYP>
void SLista<TYP>::wyczyscListe(){

    while(head != NULL){
      SWezel<TYP> *stary = head;
      head = stary->nastepny;
      delete stary;
    }
    head = NULL;
    tail = NULL;
    rozmiar = 0;
};



template <typename TYP>
TYP SLista<TYP>::zwrocElement(unsigned int indeks){

     SWezel<TYP> *pamiec = head;
     for (unsigned int i=0; i<indeks; i++){
        head = head->nastepny;
     }
     TYP element = head->wartosc;
     head = pamiec;
     return element;
}



template <typename TYP>
void SLista<TYP>::drukujListe(){

    SWezel<TYP> *pamiec = head;
    while(head != NULL){
        cout << head->wartosc << endl;
        head = head->nastepny;
    }
     head = pamiec;
}


template <typename TYP>
bool SLista<TYP>::czyDobrze(){

    bool wynik = true;
    SWezel<TYP> *pamiec = head;
    if(head != NULL){
        while(head->nastepny != NULL){
            if (head->wartosc  >  head->nastepny->wartosc)
                wynik = 0;
                head = head->nastepny;
        }
    }
    head = pamiec;

    return wynik;
}


#endif // LISTA_H_INCLUDED
