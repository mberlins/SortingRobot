#include "Generator.h"
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <time.h>
#include <iostream>
#include <vector>

using namespace std;

Generator:: Generator(int size)
{
    srand(time(NULL));
    this->size = size;

    for (int i = 0; i < size; i++)
    {
        int tmp = rand()%4;
        //int tmp = i%4;

        if (tmp == 0)
            shelf.push_back('C');
        else if (tmp == 1)
            shelf.push_back('M');
        else if (tmp == 2)
            shelf.push_back('Y');
        else if (tmp == 3)
            shelf.push_back('K');
    }
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

