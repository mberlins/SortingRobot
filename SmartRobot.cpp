#include "SmartRobot.h"
#include <time.h>
#include <iostream>
#include <vector>
#include "NaiveRobot.h"
#include <stdlib.h>

using namespace std;

SmartRobot::SmartRobot(int start) : NaiveRobot(start)
{
    counter = start;
}

int SmartRobot::getCounter() const
{
    return counter;
}

void SmartRobot::setCounter(int counter) {
    SmartRobot::counter = counter;
}

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

