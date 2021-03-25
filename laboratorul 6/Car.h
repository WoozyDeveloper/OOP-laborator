#pragma once
class Car
{
protected:
	char* name;
	int fuelCapacity, fuelConsumption, avgSpeed;
public:
	virtual void SetAverageSpeed(int) = 0;
	virtual void SetFuelCapacity(int capacity) = 0;
	virtual void SetFuelConsumption(int consumption) = 0;

	virtual char* GetName() = 0;
	virtual int GetAverageSpeed() = 0;
	virtual int GetFuelCapacity() = 0;
	virtual int GetFuelConsumption() = 0;
};