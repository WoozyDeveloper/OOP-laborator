#pragma once

#include "Contact.h"

using namespace std;

class Coleg : public Contact {
protected:
    string nrTelefon, firma, adresa;

public:
    void set(string n, string nr, string f, string adr) 
    {
        nume = n;
        nrTelefon = nr;
        firma = f;
        adresa = adr;
    }
    virtual string getNume()
    {
        return nume;
    }
};
