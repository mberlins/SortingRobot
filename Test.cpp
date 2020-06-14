//Created by Michał Berliński
//Klasa odpowiada za iteracyjne wykonywanie sortowań, podsumowanie i wyświetlenie ich rezultatów

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
/* Funckja przeprowadza tyle wykonań każdego z algorytmów, ile zostało zadane w parametrze iterations. Mierzy czas wykonania
 * każdego z sortowań i umieszcza je w odpowiedniej tablicy.  */
void Test:: conductTests(int iterations, int rozmiarStartowy, int krok, int quality)
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
        generator.setShelf(rozmiarStartowy + i*krok, quality);
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

        t1 = std::chrono::high_resolution_clock::now();
        tabTer = smartRobotBis.smartSort(tabTer);
	naiveRobot.setCounter(0);
        tabTer = naiveRobot.sort(tabTer, 0);
        t2 = std::chrono::high_resolution_clock::now();
        int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
        smartTimeBis.push_back(int_ms.count());
        int counterBis = smartRobotBis.getCounter() + naiveRobot.getCounter();
        smartOperationsBis.push_back(counterBis);
        smartRobotBis.setCounter(0);
        naiveRobot.setCounter(0);

        tab.clear();
        tabBis.clear();
        tabTer.clear();
    }
}

/* Wyswietla w formie tabelki liczbę operacji oraz czas
 * działania dla każdego z wywołan algorytmów sortujących.  */
void Test:: printResults()
{
    cout<<"Naiwne operacje:    "<<"Smart operacje:     "<<"SmartBis operacje:  "<<"Czas naiwny:   "<<"Czas smart:    "<<"Czas smartBis:"<<endl;

    for (int i = 0; i < smartTimeBis.size(); i++)
    {
        cout.width(20);
        cout<<naiveOperations[i];
        cout.width(20);
        cout<<smartOperations[i];
        cout.width(20);
        cout<<smartOperationsBis[i];
        cout.width(15);
        cout<<naiveTime[i];
        cout.width(15);
        cout<<smartTime[i];
        cout.width(15);
        cout<<smartTimeBis[i]<<endl;
    }
}
