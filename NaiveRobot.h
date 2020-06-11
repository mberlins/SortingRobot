#ifndef AALROBOT_NAIVEROBOT_H
#define AALROBOT_NAIVEROBOT_H

#include <vector>
using namespace std;

class NaiveRobot
{
private:
    int counter;
    int first;
    int second;
    int third;
    int fourth;

    //vector <char> move;
    //vector <char> shelf;
public:
    NaiveRobot(int start);
    vector<char> sort(vector<char> shelf);
    vector<char> replace(int i, vector<char> shelf);

    int getCounter() const;


};


#endif AALROBOT_NAIVEROBOT_H
