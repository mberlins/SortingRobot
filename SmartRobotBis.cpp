//Created by Michał Berliński
//Klasa sortująca półkę algorytmem tworzącym czwórki CMYK na końcu półki w wyniku łączenia w pary określonych czwórek

#include "SmartRobotBis.h"
#include <time.h>
#include <iostream>
#include <vector>
#include "NaiveRobot.h"
#include <stdlib.h>

using namespace std;

/* Konstruktor klasy SmartRobotBis, licznik operacji jest ustawiany na wartość przekazaną parametrem start */
SmartRobotBis::SmartRobotBis(int start) : NaiveRobot(start)
{
    counter = start;
}
//zwraca licznik operacji
int SmartRobotBis:: getCounter() const
{
    return counter;
}
// ustawia licznik operacji na zadaną wartość
void SmartRobotBis::setCounter(int counter)
{
    SmartRobotBis::counter = counter;
}
/* Funckja przeprowadzająca sortowanie półki algorytmem poszukującym par CMYx i xxxK, CMxx i xxYK oraz Cxxx oraz xMYK, przenoszącym
 * te pary na koniec , a następnie wycinającym czwórki xxxx "ze środka".
 * Jako argument przyjmuje półkę shelf.*/
vector<char> SmartRobotBis:: smartSort(vector<char> shelf)
{
    counter = 0;

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
            continue;
        }
        j++;
    }

    // szukamy CMYx i xxxK
    while (true)
    {
        int CMYx;
        int xxxK;

        CMYx = findCMY(shelf);
        xxxK = findK(shelf);
        if(CMYx == -1 || xxxK == -1)
            break;

        shelf = replace(CMYx, shelf);
        shelf = replace(xxxK, shelf);
        shelf = replace(shelf.size() - 5, shelf);
        counter += 3;
    }


    // szukamy Cxxx i xMYK
    while(true)
    {
        int Cxxx;
        int xMYK;

        Cxxx = findC(shelf);
        xMYK = findMYK(shelf);
        if (Cxxx == -1 || xMYK == -1)
            break;

        shelf = replace(Cxxx, shelf);
        shelf = replace(xMYK, shelf);
        shelf = replace(shelf.size() - 7, shelf);
        counter += 3;
    }


    // szukamy CMxx i xxYK
    while (true)
    {
        int CMxx;
        int xxYK;

        CMxx = findCM(shelf);
        xxYK = findYK(shelf);
        if (CMxx == -1 || xxYK == -1)
            break;

        shelf = replace(CMxx, shelf);
        shelf = replace(xxYK, shelf);
        shelf = replace(shelf.size() - 6, shelf);
        counter += 3;
    }

    j = 0;
    while(true)
    {
        if (j >= shelf.size()-5)
            break;
        if (shelf[j] == 'C' && shelf[j+1] == 'M' && shelf[j+2] == 'Y' && shelf [j+3] == 'K')
        {
            counter++;
            shelf = replace(j,shelf);
            j = j + 4;
            continue;
        }
        j++;
    }

    cout<<"SmartSortBis done "<<endl;
    for (int j = 0; j < shelf.size(); j++)
    {
        cout<<shelf[j]<<" ";

        if (j%50 == 49)
            cout<<" "<< endl;
    }
    cout<<"\n\nWykonano: "<<counter<<" operacji"<<endl;
    return shelf;
}

/* Funckja szuka czwórki w formacie CMYx, a następnie wywołuje funkcje check w celu sprawdzenia możliwości
 * przeniesienia czwórki. Jeśli jest to możliwe zwraca indeks na jej pierwszy element.
 * Jako argument przyjmuje półkę shelf. */
int SmartRobotBis:: findCMY(vector<char> shelf)
{
    int tmp;
    for (int i = 0; i< shelf.size()-5; i++)
    {
        if(shelf[i] == 'C' && shelf[i+1] == 'M' && shelf[i+2] == 'Y' && shelf[i+3] != 'K')
        {
            tmp = check(shelf, 'C', i);
            if(tmp==0)
                continue;
            else
                return i;
        }
    }
    return -1;
}

/* Funkcja szuka czwórki w formacie xxxK, a następnie wywołuje funkcje check w celu sprawdzenia możliwości
* przeniesienia czwórki. Jeśli jest to możliwe zwraca indeks na jej pierwszy element.
* Jako argument przyjmuje półkę shelf. */
int SmartRobotBis:: findK(vector<char> shelf)
{
    int tmp;
    for (int i = 0; i< shelf.size()-5; i++)
    {
        if(shelf[i+3] == 'K' && shelf[i] != 'C')
        {
            tmp = check(shelf, shelf[i], i);
            if(tmp==0)
                continue;
            else
                return i;
        }
    }
    return -1;
}

/* Funkcja szuka czwórki w formacie Cxxx, a następnie wywołuje funkcje check w celu sprawdzenia możliwości
* przeniesienia czwórki. Jeśli jest to możliwe zwraca indeks na jej pierwszy element.
* Jako argument przyjmuje półkę shelf. */
int SmartRobotBis:: findC(vector<char> shelf)
{
    int tmp;
    for (int i = 0; i< shelf.size()-5; i++)
    {
        if(shelf[i] == 'C' && shelf[i+1] != 'M')
        {
            tmp = check(shelf, shelf[i], i);
            if(tmp==0)
                continue;
            else
                return i;
        }
    }
    return -1;
}

/* Funkcja szuka czwórki w formacie xMYK, a następnie wywołuje funkcje check w celu sprawdzenia możliwości
* przeniesienia czwórki. Jeśli jest to możliwe zwraca indeks na jej pierwszy element.
* Jako argument przyjmuje półkę shelf. */
int SmartRobotBis:: findMYK(vector<char> shelf)
{
    int tmp;
    for (int i = 0; i< shelf.size()-5; i++)
    {
        if(shelf[i] != 'C' && shelf[i+1] == 'M' && shelf[i+2] == 'Y' && shelf[i+3] == 'K')
        {
            tmp = check(shelf, shelf[i], i);
            if(tmp==0)
                continue;
            else
                return i;
        }
    }
    return -1;
}

/* Funkcja szuka czwórki w formacie CMxx, a następnie wywołuje funkcje check w celu sprawdzenia możliwości
* przeniesienia czwórki. Jeśli jest to możliwe zwraca indeks na jej pierwszy element.
* Jako argument przyjmuje półkę shelf. */
int SmartRobotBis:: findCM(vector<char> shelf)
{
    int tmp;
    for (int i = 0; i< shelf.size()-5; i++)
    {
        if(shelf[i] == 'C' && shelf[i+1] == 'M' && shelf[i+2] != 'Y')
        {
            tmp = check(shelf, shelf[i], i);
            if(tmp==0)
                continue;
            else
                return i;
        }
    }
    return -1;
}

/* Funkcja szuka czwórki w formacie xxYK, a następnie wywołuje funkcje check w celu sprawdzenia możliwości
* przeniesienia czwórki. Jeśli jest to możliwe zwraca indeks na jej pierwszy element.
* Jako argument przyjmuje półkę shelf. */
int SmartRobotBis:: findYK(vector<char> shelf)
{
    int tmp;
    for (int i = 0; i< shelf.size()-5; i++)
    {
        if(shelf[i] != 'C' && shelf[i+2] == 'Y' && shelf[i+3] == 'K')
        {
            tmp = check(shelf, shelf[i], i);
            if(tmp==0)
                continue;
            else
                return i;
        }
    }
    return -1;
}
