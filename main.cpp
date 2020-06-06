#include <iostream>
#include "Generator.h"
#include "NaiveRobot.h"
using namespace std;

int main()
{
    //cout << "Hello, World!" << std::endl;

    Generator generator(225);

    //generator.printShelf();

    NaiveRobot naiveRobot(0);


    vector<char> tab;

    tab = generator.getShelf();

    /*for (int i = 0; i < tab.size(); i++)
    {
        cout<<tab[i]<<" ";

        if (i%50 == 49)
            cout<<" "<< endl;
    }*/



    naiveRobot.sort(tab);



    return 0;
}
