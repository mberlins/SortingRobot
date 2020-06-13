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
int main()
{


    while (1)
    {
        srand(time(0));

        int x;
        cout<<"Wybierz tryb działania programu: \nWczytywanie danych z klawiatury - wcisnij 1.\nGenerowanie i segregowanie - wcisnij 2.\nGenerowanie, segregowanie i podsumowanie - wcisnij 3.\n";
        cout<<"Aby opuscic program wybierz 0\n\n";
        cin>>x;

        if (x==1)
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
        if (x==2)
        {
            int rozmiar = 100;
            int tryb = 0;
            cout<<"Wybierz rozmiar tablicy do sortowania"<<endl;
            cin>>rozmiar;
            cout<<"Wybierz stopien uporzadkowania danych"<<endl;
            cin>>tryb;

            Generator generator(rozmiar, tryb);
            generator.setShelf(rozmiar, tryb);

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
        if (x==3)
        {
            int quality;
            cout<<"Podaj jakosc generowanych danych ( 0 - przypadkowa, 1 - przypadek optymistyczny, -1 - przypadek pesymistyczny )"<<endl;
            cin>>quality;
            if (quality == 0 || quality == 1 || quality == -1)
            {
                Test test(0);
                test.conductTests(10);
                test.printResults();
            }
        }
        if (x==0)
            break;
    }

    return 0;
}
