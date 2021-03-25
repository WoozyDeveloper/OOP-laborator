#include "Circuit.h"
#include "Dacia.h"
#include "Mercedes.h"

#include <string>
#include <iostream>
#include <stdlib.h>
#include <iomanip>

Circuit::Circuit()
{
	this->enteredCars = 0;
}

Circuit::~Circuit(){}

void Circuit::ShowWhoDidNotFinish()
{
	std::cout << "\nCars who didn't finish the race:\n";
	for (int i = 0; i < this->enteredCars; i++)
		if ((this->cars[i]->GetFuelCapacity() * 100) / this->cars[i]->GetFuelConsumption() < this->circuitLength)
			std::cout << this->cars[i]->GetName() << ' ';
}

void Circuit::ShowFinalRanks()
{
	int place = 1;
	for (int i = 0; i < this->enteredCars; i++)
		if ((this->cars[i]->GetFuelCapacity() * 100) / this->cars[i]->GetFuelConsumption() >= this->circuitLength)
		{
			std::cout << "Locul " << place++ << ':' << this->cars[i]->GetName() << " a terminat cursa in " << std::fixed << std::setprecision(3) << (float)this->circuitLength / this->cars[i]->GetAverageSpeed() << " ore."<< '\n';
		}
}

void Circuit::Race()
{
	for (int i = 0; i < this->enteredCars - 1; i++)
		for (int j = i + 1; j < this->enteredCars; j++)
			if (this->cars[i]->GetAverageSpeed() < this->cars[j]->GetAverageSpeed())
				std::swap(this->cars[i], this->cars[j]);
}

void Circuit::SetWeather(int newWeather)
{
	this->currentWeather = newWeather;
}

void Circuit::SetLength(int length)
{
	this->circuitLength = length;
}

void Circuit::AddCar(Car* addedCar)
{
	++enteredCars;
	
	this->cars = (Car**)realloc(this->cars, enteredCars * sizeof(Car*));
	this->cars[enteredCars - 1] = addedCar;
	
	if (strcmp(this->cars[enteredCars - 1]->GetName(),"Dacia") == 0)
		this->cars[enteredCars - 1]->SetAverageSpeed(this->cars[enteredCars - 1]->GetAverageSpeed() - this->currentWeather * 10);
	
	else if (strcmp(this->cars[enteredCars - 1]->GetName(), "Mercedes") == 0)
		this->cars[enteredCars - 1]->SetAverageSpeed(this->cars[enteredCars - 1]->GetAverageSpeed() - this->currentWeather * 5);
	
	else if (strcmp(this->cars[enteredCars - 1]->GetName(), "Ford") == 0)
		this->cars[enteredCars - 1]->SetAverageSpeed(this->cars[enteredCars - 1]->GetAverageSpeed() - this->currentWeather * 15);
	
	else
		this->cars[enteredCars - 1]->SetAverageSpeed(this->cars[enteredCars - 1]->GetAverageSpeed() - this->currentWeather * 27);
}