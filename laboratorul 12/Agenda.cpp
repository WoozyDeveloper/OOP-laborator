#include "Agenda.h"

using namespace std;

Contact* Agenda::cautareDupaNume(std::string nume) 
{
    for (auto contact : contacte)
        if (contact->getNume() == nume)
            return contact;
}

bool Agenda::stergeContact(string nume) 
{
    for (int i = 0; i < contacte.size(); ++i)
        if (contacte[i]->getNume() == nume) 
        {
            contacte.erase(contacte.begin() + i);
            return true;
        }
    return false;
}

vector<Prieten> Agenda::returnPrieteteni() 
{
    vector<Prieten> prieteni;

    for (auto contact : contacte)
        if ((typeid(*contact) == typeid(Prieten))) 
        {
            //dynamic_cast intre pointeri
            //static_cast inlocuitor de cast() 
            Prieten* p = (Prieten*)contact;
            prieteni.push_back(*p);
        }
    return prieteni;
}

void Agenda::adaugaContact(Contact* c)
{
    contacte.push_back(c);
}

void Agenda::printNames() {
    for (auto contact : contacte)
        cout << contact->getNume() << " ";
    cout << '\n';
}