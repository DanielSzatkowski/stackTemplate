#pragma once
#include "wezel.hpp"

template <typename T>
class Stos
{
private:
    Wezel<T> *pierwszy;
    int ilosc;

public:
    Stos()
    {
        pierwszy = nullptr;
        ilosc = 0;
    }

    Stos(Wezel<T> * wsk)
    {
        pierwszy = wsk;
        ilosc = 1;
    }

    ~Stos()
    {
        while(ilosc != 0)
            zdejmij();
    }

    Stos(const Stos<T> & s)
    {
        if(s.ilosc == 0){
            pierwszy = nullptr;
        } else if(s.ilosc == 1){
            ilosc = s.ilosc;
            Wezel<T> *wsk = new Wezel<T>(s.pierwszy -> getWartosc(), nullptr);
            pierwszy = wsk;
        }else {
            /* JEZELI ELEMENTOW W STOSIE JEST WIECEJ NIZ 1*/
            pierwszy = new Wezel<T>(s.pierwszy -> getWartosc());

            ilosc = s.ilosc;
            Wezel<T> *wskS = s.pierwszy -> getNastepny();
            Wezel<T> *wsk1N = pierwszy;//pierwszyN;

            while((wskS -> getNastepny()) != nullptr){
                Wezel<T> *wsk2N = new Wezel<T>(wskS -> getWartosc());
                wsk1N -> setNastepny(wsk2N);

                //krok na przod
                wsk1N = wsk1N -> getNastepny();
                wskS = wskS -> getNastepny();
            }
            Wezel<T> *wsk2N = new Wezel<T>(wskS -> getWartosc());
            wsk2N -> setNastepny(nullptr);

            wsk1N -> setNastepny(wsk2N);
        }
    }

    bool czyPusty()
    {
        if(rozmiar() == 0)
            return true;
        else
            return false;
    }

    int rozmiar()
    {
        return ilosc;
    }

    void dodaj(int wartosc)
    {
        if(czyPusty()){
            pierwszy = new Wezel<T>(wartosc, nullptr);
        } else {
            Wezel<T> *wsk = pierwszy;
            pierwszy = new Wezel<T>(wartosc, wsk);
        }

        ilosc++;
    }

    T zdejmij()
    {
        if(czyPusty())
            throw "Proba zdjecia elementu z pustego stosu";

        T war = pierwszy -> getWartosc();
        if(rozmiar() == 1){
            delete pierwszy;
            pierwszy = nullptr;
        } else {
            Wezel<T> *wsk = pierwszy;
            pierwszy = pierwszy -> getNastepny();
            delete pierwszy;
        }

        ilosc--;
        return war;
    }

    Stos<T> &operator=(const Stos<T> &s)
    {
        if(&s == this)
            return *this;

        Stos<T> pom(s);

        //przypisanie wartosci (zamiana wartosci this i s przy pomocy pom - zostanie wywolany destruktor ktory uwolni pamiec)
        Wezel<T> *wezel = s.pierwszy;
        int iloscElem = s.ilosc;

        pom.pierwszy = pierwszy;
        pom.ilosc = ilosc;
        pierwszy = wezel;
        ilosc = iloscElem;
    }
};
