#pragma once

template <typename T>
class Wezel
{
private:
    T wartosc;
    Wezel *nastepny;

public:
    Wezel() {}

    Wezel(T w)
    {
        wartosc = w;
    }

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

    void setWartosc(T w)
    {
        wartosc = w;
    }
};
