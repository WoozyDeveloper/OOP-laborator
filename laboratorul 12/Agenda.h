#pragma once
#include <iostream>
#include <vector>

#include "Contact.h"
#include "Prieten.h"

using namespace std;

class Agenda {
public:
	vector<Contact*> contacte;

public:
	Contact* cautareDupaNume(string);
	vector<Prieten> returnPrieteteni();
	bool stergeContact(string);
	void adaugaContact(Contact*);

	void printNames();
};
