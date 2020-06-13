#ifndef AALROBOTBIS_SMARTROBOTBIS_H
#define AALROBOTBIS_SMARTROBOTBIS_H

#include <vector>
#include "NaiveRobot.h"

using namespace std;

/* Klasa SmartRobotBis dziedziczy po klasie NaiveRobot, przeprowadza działanie algorytmu tworzącego sekwencję CMYK z par CMYx i xxxK, Cxxx i xMYK oraz CMxx i xxYK*/
class SmartRobotBis: public NaiveRobot
{
private:
    int counter;                                            // licznik operacji

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
