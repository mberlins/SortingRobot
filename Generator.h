#ifndef AALROBOT_GENERATOR_H
#define AALROBOT_GENERATOR_H

#include <vector>
using namespace std;

/* Klasa Generator odpowiada za utworzenie półki barwników zapełnionej kolorami ustawionymi w losowej kolejności.
 * W zależności od parametru wygenerowane dane mogą być mniej lub bardziej uporządkowane */
class Generator
{
private:
    vector <char> shelf;                                    // półka z barwnikami
    int size;                                               // rozmiar generowanej półki
    int quality;                                            // tryb generowania

public:
    Generator(int size, int quality);
    void printShelf();
    void addChar(int colour);
    const vector <char> &getShelf() const;
    vector<char> getFour(int beginning);
    void setShelf(int size, int quality);

};

#endif AALROBOT_GENERATOR_H
