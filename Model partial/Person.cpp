#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

Person::~Person() {}

Person::operator int()
{
	float sum = 0;
	for (int i = 0; i < this->nrnote; i++)
		sum += this->note[i];
	float rezultat = sum / this->nrnote;
	return (int)rezultat;
}

char* Person::operator[](const char* getter)
{
	char error_code[20] = "404";
	if (strcmp(getter, "nume") == 0)
		return this->nume;
	else if (strcmp(getter, "varsta") == 0)
	{
		char* nr = (char*)malloc(sizeof(char) * 10);
		_itoa(this->varsta, nr, 10);
		return nr;
	}
	return error_code;
}

Person::Person(const char nume[30],int varsta,float inaltime)
{
	this->nrnote = 0;
	strcpy(this->nume, nume);
	this->varsta = varsta;
	this->inaltime = inaltime;
}

void Person::addNote(int nota)
{
	++nrnote;
	this->note = (int*)realloc(this->note, nrnote * sizeof(int));
	this->note[nrnote - 1] = nota;
}