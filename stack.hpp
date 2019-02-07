template <typename T>
class Wezel
{
private:
    T wartosc;
    Wezel *nastepny;

public:
    Wezel(T w, Wezel *wsk)
    {
        wartosc = w;
        nastepny = wsk;
    }

    Wezel *getNastepny()
    {
        return nastepny;
    }

    void setNastepny(Wezel * wsk)
    {
        nastepny = wsk;
    }

    T getWartosc()
    {
        return wartosc;
    }
};

template <typename T>
class Stos
{
private:
    Wezel<T> *pierwszy;
    int ilosc;

public:
    Stos()
    {
        pierwszy = 0;
        ilosc = 0;
    }

    ~Stos()
    {
        while(ilosc != 0)
            zdejmij();
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
            pierwszy = new Wezel<T>(wartosc, 0);
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
            pierwszy = 0;
        } else {
            Wezel<T> *wsk = pierwszy;
            pierwszy = pierwszy -> getNastepny();
            delete pierwszy;
        }

        ilosc--;
        return war;
    }
};
