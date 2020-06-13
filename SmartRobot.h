#ifndef AALROBOT_SMARTROBOT_H
#define AALROBOT_SMARTROBOT_H

#include <vector>
#include "NaiveRobot.h"

using namespace std;

/*Klasa SmartRobotBis dziedziczy po klasie NaiveRobot, przeprowadza działanie algorytmu tworzącego sekwencję CMYK, za pomocą dostawiania
 *  czwórek zaczynających się od pasującej do poprzedniej litery na koniec półki*/
class SmartRobot: public NaiveRobot
{
private:
    int counter;                                                        // licznik operacji

public:
    SmartRobot(int start);
    vector<char> smartSort(vector<char> shelf, int mode);
    int findFour(vector<char> shelf, char target);


    int getCounter() const;

    void setCounter(int counter);
    //vector<char> replace(int i, vector<char> shelf);

};

#endif AALROBOT_SMARTROBOT_H
