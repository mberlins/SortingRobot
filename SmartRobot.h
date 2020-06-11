#ifndef AALROBOT_SMARTROBOT_H
#define AALROBOT_SMARTROBOT_H

#include <vector>
#include "NaiveRobot.h"

using namespace std;

class SmartRobot: public NaiveRobot
{
private:
    int counter;

public:
    SmartRobot(int start, int i);
    vector<char> smartSort(vector<char> shelf);
    int findFour(vector<char> shelf, char target);
    int check(vector<char> shelf, char target, int position);

    int getCounter() const;
    //vector<char> replace(int i, vector<char> shelf);

};

#endif AALROBOT_SMARTROBOT_H
