#include"vehicle.h"
#include"parkingspot.h"

void Vehicle::removeVehicle()
{
	_spot->removeVehicle();
	_spot = NULL;
}