#include <iostream>

#include "Agenda.h"
#include "Coleg.h"
#include "Cunoscut.h"
#include "Prieten.h"

#include <iostream>

using namespace std;

int main()
{
    Agenda a;
    Coleg c;
    Cunoscut cunosc;
    Prieten p1, p2;

    //cunosc
    c.set("Rob", "123", "LOC", "adresa -1");
    cunosc.set("Alex", "456");

    //prieteni
    p1.set("Denis", "789", "01.05.2000", "adresa 1");
    p2.set("Cos", "101112", "01.01.0001", "adresa 2");

    //contacte
    a.adaugaContact(&c);
    a.adaugaContact(&cunosc);
    a.adaugaContact(&p1);
    a.adaugaContact(&p2);
    //ROB ALEX DENIS COS
    a.printNames();
    a.stergeContact("Denis");
    //ROB ALEX COS
    a.printNames();

    cout << "\n-----------------------\n";
    cout << "Prieteni\n";
    cout << "--------------------------\n";

    for (auto i : a.returnPrieteteni())
        cout << i.getNume() << " " << i.getAdresa() << '\n';

    return 0;
}