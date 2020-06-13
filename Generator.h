#ifndef AALROBOT_GENERATOR_H
#define AALROBOT_GENERATOR_H

#include <vector>
using namespace std;

class Generator
{
private:
    vector <char> shelf;
    int size;
    int quality;

    //void setShelf();
    //list<char> getShelf();

public:
    Generator(int size, int quality);
    void printShelf();
    void addChar(int colour);
    const vector <char> &getShelf() const;
    vector<char> getFour(int beginning);
    void setShelf(int size, int quality);

};

#endif AALROBOT_GENERATOR_H
