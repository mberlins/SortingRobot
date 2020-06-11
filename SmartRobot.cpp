#include "SmartRobot.h"
#include <time.h>
#include <iostream>
#include <vector>
#include "NaiveRobot.h"
#include <stdlib.h>

using namespace std;

SmartRobot::SmartRobot(int start, int i) : NaiveRobot(start)
{
    counter = i;
}

vector<char> SmartRobot:: smartSort(vector<char> shelf)
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
        counter++;
    }

    cout<<"SmartSort done"<<endl;
    for (int i = 0; i < shelf.size(); i++)
    {
        cout<<shelf[i]<<" ";

        if (i%50 == 49)
            cout<<" "<< endl;
    }
    cout<<"\n\nWykonano: "<<counter<<" operacji"<<endl;
    return shelf;
}

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

int SmartRobot:: check(vector<char> shelf, char target, int position)
{
    //cout << target <<" "<< position <<  endl;
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