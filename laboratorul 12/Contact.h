#pragma once

#include <string>

using namespace std;

class Contact {
protected:
	string nume;
public:
	virtual string getNume()
	{
		return nume;
	}
};
