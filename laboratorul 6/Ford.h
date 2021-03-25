#pragma once
#include "Car.h"

class Ford : public Car
{
public:
	Ford();
	~Ford();
private:
	void SetAverageSpeed(int speed) override;
	void SetFuelCapacity(int capacity) override;
	void SetFuelConsumption(int consumption) override;
	int GetAverageSpeed() override;
	char* GetName() override;
	int GetFuelConsumption() override;
	int GetFuelCapacity() override;
};