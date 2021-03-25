#pragma once
#include "Car.h"

class Mazda : public Car
{
public:
	Mazda();
	~Mazda();
private:
	void SetAverageSpeed(int speed) override;
	void SetFuelCapacity(int capacity) override;
	void SetFuelConsumption(int consumption) override;
	char* GetName() override;
};