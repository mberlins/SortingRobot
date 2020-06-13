#include "SmartRobot.h"
#include <time.h>
#include <iostream>
#include <vector>
#include "NaiveRobot.h"
#include <stdlib.h>

using namespace std;

/* Konstruktor klasy SmartRobot, licznik operacji jest ustawiany na wartość przekazaną parametrem start */
SmartRobot::SmartRobot(int start) : NaiveRobot(start)
{
    counter = start;
}
//zwraca licznik operacji
int SmartRobot::getCounter() const
{
    return counter;
}
// ustawia licznik operacji na zadaną wartość
void SmartRobot::setCounter(int counter) {
    SmartRobot::counter = counter;
}

/* Funckja przeprowadzająca sortowanie półki algorytmem tworzącym sekwencję CMYK, za pomocą dostawiania
 *  czwórek zaczynających się od pasującej do poprzedniej litery na koniec półki. Przed rozpoczęciem właściwego sortowania wszystkie poprawne
 *  czwórki CMYK są przemieszczane na koniec półki.
 *  Jako parametry przyjmuje półkę oraz liczbę całkowitą określającą tryb wykonania -
 *  ( 0 - bez wyświetlania kroków pośrednich, 1 - z krokami pośrednimi)*/
vector<char> SmartRobot:: smartSort(vector<char> shelf, int mode)
{
    counter = 0;

    int tmpCounter = 0;
    int j = 0;

    while(true)
    {
        if (j >= shelf.size()-5)
            break;
        if (shelf[j] == 'C' && shelf[j+1] == 'M' && shelf[j+2] == 'Y' && shelf [j+3] == 'K')
        {
            counter++;
            shelf = replace(j,shelf);
            j = j + 4;

            if (mode == 1)
            {
                for (int i = 0; i < shelf.size(); i++)
                    cout << shelf[i] << " ";
            }

            continue;
        }
        j++;
    }

    int check = 0;

    while (true)
    {
        check = findFour(shelf, shelf[shelf.size()-1]);

        if (check < 0)
            break;

        shelf = replace(check, shelf);

        if (mode == 1)
        {
            for (int i = 0; i < shelf.size(); i++)
                cout << shelf[i] << " ";
        }

        counter++;
    }
    
    cout<<"SmartSort done"<<endl;
    for (int j = 0; j < shelf.size(); j++)
    {
        cout<<shelf[j]<<" ";

        if (j%50 == 49)
            cout<<" "<< endl;
    }
    cout<<"\n\nWykonano: "<<counter<<" operacji"<<endl;
    return shelf;
}

/* Funkcja odnajduje na półce shelf czwórkę zaczynającą się zadaną w parametrze target literą. Po odnalezieniu indeksu
 * pierwszej litey takiej czwórki, przekazuje go funkcji check w celu sprawdzenia możliwości przeniesienia czwórki.
 * Jeśli poszukiwana czwórka nie istnieje zwraca wartość -1*/
int SmartRobot:: findFour(vector<char> shelf, char target)
{
    int tmp;

    for (int i = 0; i < shelf.size()-4; i++)
    {
        if (target == 'C')
        {
            if (shelf[i] == 'M')
            {
                tmp = check(shelf, 'M', i);
                if (tmp == 1)
                    return i;
            }
        }
        else if (target == 'M')
        {
            if (shelf[i] == 'Y')
            {
                tmp = check(shelf, 'Y', i);
                if (tmp == 1)
                    return i;
            }
        }
        else if (target == 'Y')
        {
            if (shelf[i] == 'K')
            {
                tmp = check(shelf, 'K', i);
                if (tmp == 1)
                    return i;
            }
        }
        else if (target == 'K')
        {
            if (shelf[i] == 'C')
            {
                tmp = check(shelf, 'C', i);
                if (tmp == 1)
                    return i;
            }
        }
    }
    return -1;
}

