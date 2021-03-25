#define _CRT_SECURE_NO_WARNINGS

#include "Dacia.h"
#include <string>

int Dacia::GetFuelCapacity()
{
	return this->fuelCapacity;
}

int Dacia::GetFuelConsumption()
{
	return this->fuelConsumption;
}

char* Dacia::GetName()
{
	return this->name;
}

int Dacia::GetAverageSpeed()
{
	return this->avgSpeed;
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