#ifndef KLAMMER_H
#define KLAMMER_H

#include "Berechnung.h"
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

class Klammer
{
        private: string sWert;
        private: double dWert;

    public:
        Klammer();
        Klammer(string wert);
        virtual ~Klammer();

        double getWert(void);
    protected:
    private:

};

#endif // KLAMMER_H
