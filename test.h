#ifndef AALROBOTBIS_TEST_H
#define AALROBOTBIS_TEST_H

#include <vector>
#include "SmartRobot.h"
#include "SmartRobotBis.h"
#include "NaiveRobot.h"
#include "Generator.h"
#include <chrono>

using namespace std;

class Test
{
private:
    vector<int> naiveOperations;
    vector<int> smartOperations;
    vector<int> smartOperationsBis;

    vector<int> naiveTime;
    vector<int> smartTime;
    vector<int> smartTimeBis;
    /*NaiveRobot naiveRobot;
    SmartRobot smartRobot;
    SmartRobotBis smartRobotBis;*/

public:
    Test(int i);
    void conductTests(int iterations);
    void printResults();

};

#endif AALROBOTBIS_TEST_H
