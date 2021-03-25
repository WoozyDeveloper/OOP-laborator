#pragma once
#include "Car.h"

class Toyota : public Car
{
public:
	Toyota();
	~Toyota();
private:
	void SetAverageSpeed(int speed) override;
	void SetFuelCapacity(int capacity) override;
	void SetFuelConsumption(int consumption) override;
	char* GetName() override;
};