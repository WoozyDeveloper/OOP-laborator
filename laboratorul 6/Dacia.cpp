#define _CRT_SECURE_NO_WARNINGS

#include "Dacia.h"
#include <string>

char* Dacia::GetName()
{
	return this->name;
}


void Dacia::SetAverageSpeed(int speed)
{
	this->avgSpeed = speed;
}

void Dacia::SetFuelCapacity(int capacity)
{
	this->fuelCapacity = capacity;
}

void Dacia::SetFuelConsumption(int consumption)
{
	this->fuelConsumption = consumption;
}

Dacia::Dacia()
{
	this->name = (char*)malloc(sizeof(char) * 10);
	strcpy(this->name, "Dacia");
	this->SetAverageSpeed(50);
	this->SetFuelCapacity(10);
	this->SetFuelConsumption(100);
}

Dacia::~Dacia() 
{ 
}