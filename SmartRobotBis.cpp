#include "SmartRobotBis.h"
#include <time.h>
#include <iostream>
#include <vector>
#include "NaiveRobot.h"
#include <stdlib.h>

using namespace std;

SmartRobotBis::SmartRobotBis(int start) : NaiveRobot(start)
{
    counter = start;
}

int SmartRobotBis:: getCounter() const
{
    return counter;
}

void SmartRobotBis::setCounter(int counter)
{
    SmartRobotBis::counter = counter;
}

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

    for (int j = 0; j < shelf.size(); j++)
    {
        cout<<shelf[j]<<" ";

        if (j%50 == 49)
            cout<<" "<< endl;
    }

    cout<<"\n\nWykonano: "<<counter<<" operacji (SmartSortBis)"<<endl;
    return shelf;
}

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

int SmartRobotBis:: findK(vector<char> shelf)
{
    int tmp;
    for (int i = 0; i< shelf.size()-5; i++)
    {
        if(shelf[i+3] == 'K')
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