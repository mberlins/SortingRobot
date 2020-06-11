#include <iostream>
#include "Generator.h"
#include "NaiveRobot.h"
#include "SmartRobot.h"
using namespace std;

int main()
{
    Generator generator(2000, 0);
    NaiveRobot naiveRobot(0);
    SmartRobot smartRobot(0, 0);

    vector<char> tab;
    vector<char> tabBis;

    tab = generator.getShelf();

    for (int i = 0; i< tab.size(); i++)
        tabBis.push_back(tab[i]);

    naiveRobot.sort(tab);

    tabBis = smartRobot.smartSort(tabBis);
    /*int counter = smartRobot.getCounter();
    NaiveRobot naiveRobotBis(counter);
    naiveRobotBis.sort(tabBis);*/
    tabBis = smartRobot.sort(tabBis);
    return 0;
}
