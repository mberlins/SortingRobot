#ifndef AALROBOTBIS_SMARTROBOTBIS_H
#define AALROBOTBIS_SMARTROBOTBIS_H

#include <vector>
#include "NaiveRobot.h"

using namespace std;

class SmartRobotBis: public NaiveRobot
{
private:
    int counter;

public:
    SmartRobotBis(int start, int i);
    vector<char> smartSort(vector<char> shelf);
    int findFour(vector<char> shelf, char target);
    int check(vector<char> shelf, char target, int position);

    int getCounter() const;
};


#endif AALROBOTBIS_SMARTROBOTBIS_H
