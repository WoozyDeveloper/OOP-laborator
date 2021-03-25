#define _CRT_SECURE_NO_WARNINGS

#include "Ford.h"
#include <string>

char* Ford::GetName()
{
	return this->name;
}

void Ford::SetAverageSpeed(int speed)
{
	this->avgSpeed = speed;
}

void Ford::SetFuelCapacity(int capacity)
{
	this->fuelCapacity = capacity;
}

void Ford::SetFuelConsumption(int consumption)
{
	this->fuelConsumption = consumption;
}

Ford::Ford()
{
	this->name = (char*)malloc(sizeof(char) * 10);
	strcpy(this->name, "Ford");
	this->SetAverageSpeed(68);
	this->SetFuelCapacity(90);
	this->SetFuelConsumption(8);
}

Ford::~Ford()
{
}