#include "SmartRobotBis.h"
#include <time.h>
#include <iostream>
#include <vector>
#include "NaiveRobot.h"
#include <stdlib.h>

SmartRobotBis::SmartRobotBis(int start, int i) : NaiveRobot(start)
{
    counter = i;
}

vector<char> SmartRobotBis:: smartSort(vector<char> shelf)
{
    
}