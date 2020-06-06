#ifndef AALROBOT_GENERATOR_H
#define AALROBOT_GENERATOR_H

#include <vector>
using namespace std;

class Generator
{
private:
    vector <char> shelf;
    int size;

    //void setShelf();
    //list<char> getShelf();

public:
    Generator(int size);
    void printShelf();
    const vector <char> &getShelf() const;
    vector<char> getFour(int beginning);

};

#endif AALROBOT_GENERATOR_H
