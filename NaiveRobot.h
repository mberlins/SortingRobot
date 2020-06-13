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
    vector<char> sort(vector<char> shelf, int mode);
    vector<char> replace(int i, vector<char> shelf);
    int check(vector<char> shelf, char target, int position);

    int getCounter() const;

    void setCounter(int counter);


};


#endif AALROBOT_NAIVEROBOT_H
