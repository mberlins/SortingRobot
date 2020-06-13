#include <vector>
#include <iostream>
#include "SmartRobot.h"
#include "SmartRobotBis.h"
#include "NaiveRobot.h"
#include "Generator.h"
#include "test.h"
#include <chrono>

using namespace std;


Test:: Test( int i)
{

}

void Test:: conductTests(int iterations)
{

    NaiveRobot naiveRobot(0);
    SmartRobot smartRobot(0);
    SmartRobotBis smartRobotBis(0);
    Generator generator(120, 0);

    vector<char> tab;
    vector<char> tabBis;
    vector<char> tabTer;

    for(int i = 0; i < iterations; i++)
    {
        generator.setShelf(2000, 0);
        tab = generator.getShelf();

        for (int i = 0; i< tab.size(); i++)
        {
            tabBis.push_back(tab[i]);
            tabTer.push_back(tab[i]);
        }

        auto t1 = std::chrono::high_resolution_clock::now();
        naiveRobot.sort(tab, 0);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
        naiveTime.push_back(int_ms.count());
        naiveOperations.push_back(naiveRobot.getCounter());
        naiveRobot.setCounter(0);


        t1 = std::chrono::high_resolution_clock::now();
        tabBis = smartRobot.smartSort(tabBis,0);
        tabBis = naiveRobot.sort(tabBis,0);
        t2 = std::chrono::high_resolution_clock::now();

        int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
        smartTime.push_back(int_ms.count());
        int counter = smartRobot.getCounter() + naiveRobot.getCounter();
        smartOperations.push_back(counter);
        smartRobot.setCounter(0);
        naiveRobot.setCounter(0);

        tabTer = smartRobotBis.smartSort(tabTer);
        //tabTer = naiveRobot.sort(tabTer);
        int counterBis = smartRobotBis.getCounter() /*+ naiveRobot.getCounter()*/;
        smartOperationsBis.push_back(counterBis);
        smartRobotBis.setCounter(0);
        naiveRobot.setCounter(0);

        tab.clear();
        tabBis.clear();
        tabTer.clear();
    }
}

void Test:: printResults()
{
    cout<<"Naiwne operacje:    "<<"Smart operacje:     "<<"Czas naiwny:   "<<"Czas smart:    "<<endl;

    for (int i = 0; i < naiveOperations.size(); i++)
    {
        cout.width(20);
        cout<<naiveOperations[i];
        cout.width(20);
        cout<<smartOperations[i];
        cout.width(15);
        cout<<naiveTime[i];
        cout.width(15);
        cout<<smartTime[i];
        cout.width(20);
        cout<<smartOperationsBis[i]<<endl;
    }
}