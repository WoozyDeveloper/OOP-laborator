#define _CRT_SECURE_NO_WARNINGS

#include "Mazda.h"
#include <string>

char* Mazda::GetName()
{
	return this->name;
}

void Mazda::SetAverageSpeed(int speed)
{
	this->avgSpeed = speed;
}

void Mazda::SetFuelCapacity(int capacity)
{
	this->fuelCapacity = capacity;
}

void Mazda::SetFuelConsumption(int consumption)
{
	this->fuelConsumption = consumption;
}

Mazda::Mazda()
{
	this->name = (char*)malloc(sizeof(char) * 10);
	strcpy(this->name, "Mazda");
	this->SetAverageSpeed(62);
	this->SetFuelCapacity(120);
	this->SetFuelConsumption(6);
}

Mazda::~Mazda()
{
}