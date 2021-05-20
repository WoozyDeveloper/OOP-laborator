#pragma once

#include "Contact.h"

using namespace std;

class Prieten : public Contact {
protected:
    string nrTelefon;
    string dataNastere;
    string adresa;

public:
    void set(string _nume, string _nrTelefon, string _dataNastere, string _adresa) 
    {
        nume = _nume;
        nrTelefon = _nrTelefon;
        dataNastere = _dataNastere;
        adresa = _adresa;
    }
    string getAdresa() 
    { 
        return adresa; 
    }
    virtual string getNume()
    {
        return nume;
    }
};
