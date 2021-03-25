#pragma once
#include "Car.h"
#include "WeatherControll.h"

class Circuit
{
public:
	Car** cars;
	int circuitLength, currentWeather, enteredCars;
public:
	Circuit();
	~Circuit();
	void AddCar(Car*);
	void SetWeather(int);
	void SetLength(int);
	void ShowWhoDidNotFinish();
	void Race();
	void ShowFinalRanks();
};