//Created by Michał Berliński
//Klasa sortuje półkę algorytmem naiwnym

#include <time.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "NaiveRobot.h"

using namespace std;

/* Konstruktor klasy NaiveRobot, licznik operacji jest ustawiany na wartość przekazaną parametrem start */
NaiveRobot:: NaiveRobot(int start)
{
    counter = start;
    first = second = third = fourth = 0;

}
//zwraca licznik operacji
int NaiveRobot::getCounter() const
{
    return counter;
}
// ustawia licznik operacji na zadaną wartość
void NaiveRobot::setCounter(int counter)
{
    NaiveRobot::counter = counter;
}

/* Funkcja przeprowadzająca naiwne sortowanie półki, jako parametry przyjmuje półkę oraz liczbę całkowitą określającą tryb wykonania
 * ( 0 - bez wyświetlania kroków pośrednich, 1 - z krokami pośrednimi) */
vector<char> NaiveRobot:: sort(vector<char> shelf, int mode)
{
    cout<<"\n\n"<<endl;

    for (int j = 0; j < shelf.size(); j++)
    {
        cout<<shelf[j]<<" ";

        if (j%50 == 49)
            cout<<" "<< endl;
    }

    int tmpCounter=0;

    int i =0;

    while (1)
    {
        if (mode == 1)
        {
            for (int i = 0; i < shelf.size(); i++)
	    {
		cout << shelf[i] << " ";	
	    }
	    cout<<"\n";
        }
            tmpCounter++;

        if (tmpCounter==1000)
            break;

        if(i>=shelf.size())
            break;

        if (shelf[i] != 'C')
        {
            shelf = replace(i,shelf);
            continue;
        }

        if (shelf[i+1] != 'M')
        {
            shelf = replace(i+1, shelf);
            continue;
        }

        if (shelf[i+2] != 'Y')
        {
            shelf = replace(i+2, shelf);
            continue;
        }

        if (shelf[i+3] != 'K')
        {
            shelf = replace(i+3, shelf);
            continue;
        }

        i = i + 4;
        first = second = third = fourth = 0;
        tmpCounter = 0;
    }

    cout<<"Naive sort done"<<endl;
    for (int j = 0; j < shelf.size(); j++)
    {
        cout<<shelf[j]<<" ";

        if (j%50 == 49)
            cout<<" "<< endl;
    }
    cout<<"\nWykonano: "<<counter<<" operacji"<<endl;

    return shelf;
}

/* Funckja replace odpowiada za przeniesienie wybranej czwórki kolorów na koniec półki. Jako arguemnty przyjmuje indeks pierwszego elementu półki oraz półkę */
vector<char> NaiveRobot:: replace(int i, vector<char> shelf)
{
    counter++;
    vector<char> move;

    move.push_back(shelf[i]);
    move.push_back(shelf[i+1]);
    move.push_back(shelf[i+2]);
    move.push_back(shelf[i+3]);

    auto it = shelf.begin();
    it = it + i;

    shelf.erase(it, it+4);
    shelf.push_back(move[0]);
    shelf.push_back(move[1]);
    shelf.push_back(move[2]);
    shelf.push_back(move[3]);

    return shelf;
}

/* Funkcja check sprawdza czy możliwe jest przeniesienie określonej czwórki, bez popsucia już istniejącej poprawnej czwórki.
 * Jako argumenty przyjmuje półkę, indeks na początek czwórki oraz pierwszy element czwórki*/
int NaiveRobot:: check(vector<char> shelf, char target, int position)
{
    if (position != 0)
    {
        if (target == 'C')
        {
            if (shelf[position-1] == 'K')
                return 0;
        }
        else if (target == 'M')
        {
            if (shelf[position-1] == 'C')
                return 0;
        }
        else if (target == 'Y')
        {
            if (shelf[position-1] == 'M')
                return 0;
        }
        else if (target == 'K')
        {
            if (shelf[position-1] == 'Y')
                return 0;
        }
    }

    if (position < shelf.size() - 5)
    {
        if (shelf[position+3]=='K' && shelf[position+4] == 'C')
            return 0;
        else if (shelf[position+3]=='C' && shelf[position+4] == 'M')
            return 0;
        else if (shelf[position+3]=='M' && shelf[position+4] == 'Y')
            return 0;
        else if (shelf[position+3]=='Y' && shelf[position+4] == 'K')
            return 0;
    }
    return 1;
}
