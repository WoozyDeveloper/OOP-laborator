#pragma once
#include "Car.h"

class Dacia : public Car
{
public:
	Dacia();
	~Dacia();
private:
	void SetAverageSpeed(int speed) override;
	void SetFuelCapacity(int capacity) override;
	void SetFuelConsumption(int consumption) override;
	char* GetName() override;
};