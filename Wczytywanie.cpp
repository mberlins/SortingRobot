#include <vector>
#include <iostream>
#include <cstdio>
#include "Wczytywanie.h"

using namespace std;


const vector<char> &Wczytywanie::getShelf() const {
    return shelf;
}

void Wczytywanie::setShelf(const vector<char> &shelf) {
    Wczytywanie::shelf = shelf;
}

void Wczytywanie:: wczytaj()
{
        string message;
        cout<<"Wprowadz wiadomosc, tylko litery C, M, Y i K zostana zapisane\n"<<endl;
        cin>>message;

        for (int i = 0; i < message.size(); i++)
            input.push_back((char)message[i]);

        for (int i = 0; i < message.size(); i++)
        {
            if (input[i] == 'C' || input[i] == 'M' || input[i] == 'Y' || input[i] == 'K')
                shelf.push_back(input[i]);
        }

        for (int i = 0; i < shelf.size(); i++)
            cout<<shelf[i]<<" ";
}
