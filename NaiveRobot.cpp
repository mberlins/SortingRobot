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

vector<char> NaiveRobot:: sort(vector<char> shelf)
{
    cout<<"\n\n"<<endl;

    int tmpCounter=0;

    for (int i = 0; i < shelf.size(); i++)
    {
        cout<<shelf[i]<<" ";

        if (i%50 == 49)
            cout<<" "<< endl;
    }
    cout<<"\n\n"<<endl;

    int i =0;

    while (1)
    {
        //move.clear();
        //counter++;
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

    for (int j = 0; j < shelf.size(); j++)
    {
        //cout<<"Naive sort done"<<endl;
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

    //cout<<move[0]<<move[1]<<move[2]<<move[3]<<endl;

    auto it = shelf.begin();
    it = it + i;

    shelf.erase(it, it+4);
    shelf.push_back(move[0]);
    shelf.push_back(move[1]);
    shelf.push_back(move[2]);
    shelf.push_back(move[3]);

    return shelf;
}