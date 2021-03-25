#include "Dacia.h"
#include "Mazda.h"
#include "Mercedes.h"
#include "Toyota.h"
#include "Ford.h"
#include "Circuit.h"
#include "WeatherControll.h"

int main()
{
	Circuit c;
	c.SetLength(100);
	c.SetWeather(Weather::Snow);
	c.AddCar(new Dacia());
	c.AddCar(new Mercedes());
	c.AddCar(new Toyota());
	c.AddCar(new Mazda());
	c.AddCar(new Ford());
	c.Race();
	c.ShowFinalRanks();
	c.ShowWhoDidNotFinish();
	return 0;
}