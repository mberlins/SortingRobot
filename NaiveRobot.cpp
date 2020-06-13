#include <time.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "NaiveRobot.h"

using namespace std;

NaiveRobot:: NaiveRobot(int start)
{
    counter = start;
    first = second = third = fourth = 0;

}

int NaiveRobot::getCounter() const
{
    return counter;
}

void NaiveRobot::setCounter(int counter)
{
    NaiveRobot::counter = counter;
}



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
                cout << shelf[i] << " ";
        }
            tmpCounter++;

        if (tmpCounter==1000)
            break;

        if(i>=shelf.size())
            break;

        if (shelf[i]=='C')
        {
            first = 1;
        } else
        {
            shelf = replace(i,shelf);
            continue;
        }

        if (shelf[i+1]=='M')
        {
            second = 1;
        } else
        {
            shelf = replace(i+1, shelf);
            continue;
        }

        if (shelf[i+2] == 'Y')
        {
            third = 1;
        } else
        {
            shelf = replace(i+2, shelf);
            continue;
        }

        if (shelf[i+3]=='K')
        {
            fourth = 1;
        } else
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
    cout<<"\n\nWykonano: "<<counter<<" operacji"<<endl;

    return shelf;
}

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