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
    SmartRobotBis(int start);
    vector<char> smartSort(vector<char> shelf);
    int findCMY(vector<char> shelf);
    int findK(vector<char> shelf);
    int findC(vector<char> shelf);
    int findMYK(vector<char> shelf);
    int findCM(vector<char> shelf);
    int findYK(vector<char> shelf);
    //int findFour(vector<char> shelf, int target);

    int getCounter() const;

    void setCounter(int counter);
};


#endif AALROBOTBIS_SMARTROBOTBIS_H
