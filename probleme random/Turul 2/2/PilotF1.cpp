#define _CRT_SECURE_NO_WARNINGS
#include "PilotF1.h"

#include <string>

PilotF1::PilotF1(const char* n, int v, int rec, int pole)
{
	this->SetName(n);
	this->SetNrPolePos(pole);
	this->SetRecord(rec);
	this->SetVarsta(v);
}

char* PilotF1::GetName()
{
	return this->nume;
}

int PilotF1::GetNrPolePosition()
{
	return this->nr_pole_position;
}

int PilotF1::GetRecord()
{
	return this->record;
}

int PilotF1::GetVarsta()
{
	return this->varsta;
}

void PilotF1::SetName(const char* new_name)
{
	strcpy(this->nume, new_name);
}

void PilotF1::SetNrPolePos(int nr)
{
	this->nr_pole_position = nr;
}

void PilotF1::SetRecord(int nr)
{
	this->record = nr;
}

void PilotF1::SetVarsta(int nr)
{
	this->varsta = nr;
}