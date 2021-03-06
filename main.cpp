//Created by Michał Berliński
//Funkcja main odpowiada za interakcję z użytkownikiem oraz uruchomienie programu w odpowiednim trybie.

#include <iostream>
#include <time.h>
#include "Generator.h"
#include "NaiveRobot.h"
#include "SmartRobot.h"
#include "SmartRobotBis.h"
#include "test.h"
#include "Wczytywanie.h"
using namespace std;


// W funkcji main dokonuje się główna pętla programu, uzytkownik może wybrać opcje wykonywania
int main(int argc, char *argv[])
{

    cout<<argv[1]<<endl;
    cout<<argv[2]<<endl;
    cout<<argv[3]<<endl;
    cout<<argv[4]<<endl;

    int trybPracy = atoi(argv[1]);
    int iteracje = atoi(argv[2]);
    int rozmiarStartowy = atoi(argv[3]);
    int krok = atoi(argv[4]);
    
        srand(time(0));

        if (trybPracy==1)
        {
            Wczytywanie wczytywanie;
            wczytywanie.wczytaj();

            vector<char> tab;
            vector<char> tabBis;
            vector<char> tabTer;
            tab=wczytywanie.getShelf();

            for (int i = 0; i< tab.size(); i++)
            {
                tabBis.push_back(tab[i]);
                tabTer.push_back(tab[i]);
            }

            NaiveRobot naiveRobot(0);
            SmartRobot smartRobot(0);
            SmartRobotBis smartRobotBis(0);

            naiveRobot.sort(tab, 1);

            tabBis = smartRobot.smartSort(tabBis, 1);
            naiveRobot.sort(tabBis, 1);
        }
        if (trybPracy==2)
        {
            int rozmiar = 100;
            int tryb = 0;
            
            cout<<"Wybierz stopien uporzadkowania danych"<<endl;
            cin>>tryb;

            Generator generator(rozmiarStartowy, tryb);
            generator.setShelf(rozmiarStartowy, tryb);

            vector<char> tab;
            vector<char> tabBis;
            vector<char> tabTer;

            tab = generator.getShelf();

            for (int i = 0; i< tab.size(); i++)
            {
                tabBis.push_back(tab[i]);
                tabTer.push_back(tab[i]);
            }

            NaiveRobot naiveRobot(0);
            SmartRobot smartRobot(0);
            SmartRobotBis smartRobotBis(0);

            naiveRobot.sort(tab, 0);

            tabBis = smartRobot.smartSort(tabBis, 0);
            naiveRobot.sort(tabBis, 0);

            tabTer = smartRobotBis.smartSort(tabTer);
            naiveRobot.sort(tabTer, 0);

        }
        if (trybPracy==3)
        {
            int quality;
            cout<<"Podaj jakosc generowanych danych ( 0 - przypadkowa, 1 - przypadek optymistyczny, -1 - przypadek pesymistyczny )"<<endl;
            cin>>quality;
            if (quality == 0 || quality == 1 || quality == -1)
            {
                Test test(0);
                test.conductTests(iteracje, rozmiarStartowy, krok, quality);
                test.printResults();
            }
        }
        
           
    

    return 0;
}
