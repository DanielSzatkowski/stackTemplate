#include <iostream>
#include "stack.hpp"

using namespace std;

int main()
{
    Stos<char> s;
    string text;
    cin>>text;

    int n = text.length();
    for(int i = 0; i < n; i++){
        s.dodaj(text[i]);
    }

    try{
        for(int i = 0; i < n; i++){
            cout<<s.zdejmij();
        }
    } catch(const char *msg){
        cerr<<"Wystapil blad: "<<msg<<endl;
    }


    return 0;
}
