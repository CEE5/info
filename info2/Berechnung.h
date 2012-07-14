#ifndef BERECHNUNG_H
#define BERECHNUNG_H
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <vector>

using namespace std;

class Berechnung
{
    private: string rechnung;

    public:
        Berechnung();
        Berechnung(string input);
        virtual ~Berechnung();
        double getErgebnis();
    protected:
    private:
};

#endif // BERECHNUNG_H
