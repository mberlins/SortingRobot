#ifndef AALROBOTBIS_WCZYTYWANIE_H
#define AALROBOTBIS_WCZYTYWANIE_H

#include <vector>

using namespace std;

/* Klasa wczytywanie odpowiada za odbieranie, sprawdzanie oraz poprawianie danych wprowadzonych przez użytkownika */
class Wczytywanie
{
private:
    vector<char> shelf;
    vector<char> input;
public:
    void wczytaj();

    const vector<char> &getShelf() const;

    void setShelf(const vector<char> &shelf);

};

#endif AALROBOTBIS_WCZYTYWANIE_H
