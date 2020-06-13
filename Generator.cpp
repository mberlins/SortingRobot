#include "Generator.h"
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <time.h>
#include <iostream>
#include <vector>

using namespace std;

Generator:: Generator(int size, int quality)
{
   this->size = size;
   this->quality = size;
}

void Generator:: setShelf(int size, int quality)
{

    shelf.clear();
    this->size = size;
    this->quality = quality;

    if (quality==0)
    {
        for (int i = 0; i < size; i++)
        {
            int tmp = rand()%4;
            //int tmp = i%4;
            addChar(tmp);
        }
    }
    else if (quality == 1)                          // 40% na kolejny poprawny, 20% pozostałe
    {
        for (int i = 0; i < size; i++)
        {
            int tmp = rand()%4;

            addChar(tmp);

            int tmp2 = rand()%10;
            i++;

            if (tmp2 < 4)
                addChar(tmp+1);
            else if (tmp2 == 4 || tmp2 == 5)
                addChar(tmp + 2);
            else if (tmp2 == 6 || tmp2 == 7)
                addChar(tmp + 3);
            else if (tmp2 == 8 || tmp2 == 9)
                addChar(tmp + 4);
        }
    }
    else if (quality == 2)                         // 60% na poprawny, 13% pozostałe
    {
        for (int i = 0; i < size; i++)
        {
            int tmp = rand()%4;
            addChar(tmp);
            int tmp2 = rand()%15;
            i++;

            if (tmp2 < 9)
                addChar(tmp+1);
            else if (tmp2 == 9 || tmp2 == 10)
                addChar(tmp + 2);
            else if (tmp2 == 11 || tmp2 == 12)
                addChar(tmp + 3);
            else if (tmp2 == 13 || tmp2 == 14)
                addChar(tmp + 4);
        }
    }
    else if (quality == -1)                                 // przypadek pesymistyczny
    {
        for (int i = 0; i < size; i++)
        {
            int tmp = rand()%4;
            addChar(tmp);
            i++;
            int tmp2 = rand()%3;

            if (tmp2 == 0)
                addChar(tmp+2);
            else if (tmp2 == 1)
                addChar(tmp + 3);
            else if (tmp2 == 2)
                addChar(tmp + 4);
        }
    }

}

void Generator:: addChar(int tmp)
{

    if (tmp == 0 || tmp ==4)
        shelf.push_back('C');
    else if (tmp == 1 || tmp == 5)
        shelf.push_back('M');
    else if (tmp == 2 || tmp == 6)
        shelf.push_back('Y');
    else if (tmp == 3 || tmp == 7)
        shelf.push_back('K');
}


const vector <char> &Generator:: getShelf() const
{
    return shelf;
}

void Generator:: printShelf()
{
    for (int i = 0; i < shelf.size(); i++)
    {
        cout<<shelf[i]<<" ";

        if (i%50 == 49)
            cout<<" "<< endl;
    }
}

