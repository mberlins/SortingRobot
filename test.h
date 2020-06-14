#ifndef AALROBOTBIS_TEST_H
#define AALROBOTBIS_TEST_H

#include <vector>
#include "SmartRobot.h"
#include "SmartRobotBis.h"
#include "NaiveRobot.h"
#include "Generator.h"
#include <chrono>

using namespace std;

/* Klasa Test przeprowadza określoną ilość sortowań za pomocą każdego algorytmu liczy i przechowuje czasy ich wykonania oraz ilości wykonanych operacji*/
class Test
{
private:
    vector<int> naiveOperations;                            // tablica przechowująca ilości operacji poszczególnych wywołań algorytmu naiwnego
    vector<int> smartOperations;                            // tablica przechowująca ilości operacji poszczególnych wywołań algorytmu "smart"
    vector<int> smartOperationsBis;                         // tablica przechowująca ilości operacji poszczególnych wywołań algorytmu "smartbis""

    vector<int> naiveTime;                                  // tablica przechowująca czasy wykonania poszczególnych wywołań algorytmu naiwnego
    vector<int> smartTime;                                  // tablica przechowująca czasy wykonania poszczególnych wywołań algorytmu "smart"
    vector<int> smartTimeBis;                               // tablica przechowująca czasy wykonania poszczególnych wywołań algorytmu "smartBis"

public:
    Test(int i);
    void conductTests(int iterations, int rozmiarStartowy, int krok, int quality);
    void printResults();

};

#endif AALROBOTBIS_TEST_H
