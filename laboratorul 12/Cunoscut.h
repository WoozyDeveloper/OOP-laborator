#pragma once

#include "Contact.h"

using namespace std;

class Cunoscut : public Contact 
{
protected:
    string nrTelefon;

public:
    void set(string n, string nr) {
        nume = n;
        nrTelefon = nr;
    }
    virtual string getNume()
    {
        return nume;
    }
};
