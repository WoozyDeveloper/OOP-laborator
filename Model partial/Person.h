#pragma once
class Person
{
private:
	char nume[30];
	int varsta,nrnote;
	int* note;
	float inaltime;
public:
	Person(const char[],int,float);
	~Person();
	void addNote(int nota);
	char* operator[](const char*);
	operator int();
};