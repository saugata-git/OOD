#include"parkingspot.h"
#include"level.h"

void ParkingSpot::removeVehicle()
{
	v = NULL;
	l->spotFreed(_spot_size);
}

bool ParkingSpot::parkVehicle(Vehicle *v)
{
	if (!canVehicleFit(v) || !isAvailable())
		return false;
	v = v;
	v->parkInSpot(this);
	return true;
}