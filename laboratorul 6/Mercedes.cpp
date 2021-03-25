#define _CRT_SECURE_NO_WARNINGS

#include "Mercedes.h"
#include <string>

char* Mercedes::GetName()
{
	return this->name;
}

void Mercedes::SetAverageSpeed(int speed)
{
	this->avgSpeed = speed;
}

void Mercedes::SetFuelCapacity(int capacity)
{
	this->fuelCapacity = capacity;
}

void Mercedes::SetFuelConsumption(int consumption)
{
	this->fuelConsumption = consumption;
}

Mercedes::Mercedes()
{
	this->name = (char*)malloc(sizeof(char) * 10);
	strcpy(this->name, "Mercedes");
	this->SetAverageSpeed(90);
	this->SetFuelCapacity(120);
	this->SetFuelConsumption(15);
}

Mercedes::~Mercedes()
{
}