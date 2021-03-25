#define _CRT_SECURE_NO_WARNINGS

#include "Toyota.h"
#include <string>

char* Toyota::GetName()
{
	return this->name;
}

void Toyota::SetAverageSpeed(int speed)
{
	this->avgSpeed = speed;
}

void Toyota::SetFuelCapacity(int capacity)
{
	this->fuelCapacity = capacity;
}

void Toyota::SetFuelConsumption(int consumption)
{
	this->fuelConsumption = consumption;
}

Toyota::Toyota()
{
	this->name = (char*)malloc(sizeof(char) * 10);
	strcpy(this->name, "Toyota");
	this->SetAverageSpeed(75);
	this->SetFuelCapacity(99);
	this->SetFuelConsumption(6);
}

Toyota::~Toyota()
{
}