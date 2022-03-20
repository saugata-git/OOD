#include "level.h"

Level::Level(int _flr, int _nbr_of_spots){
    _floor = _flr;
    availableSpots[0] = _nbr_of_spots / 4;
	availableSpots[2] = _nbr_of_spots / 4;
	availableSpots[1] = _nbr_of_spots - availableSpots[0] - availableSpots[2];
   
    int i = 0;

    for (;i < availableSpots[2];i++){
		_spots.push_back(new ParkingSpot(large, i,this));
    }    
	for (;i < availableSpots[0] + availableSpots[2];i++){
		_spots.push_back(new ParkingSpot(small, i ,this));
    }    
	for (;i < _nbr_of_spots;i++){
		_spots.push_back(new ParkingSpot(medium, i, this));
    }    

}


bool Level::parkVehicle(Vehicle *v)
{
	for (int i = 0;i < _spots.size();i++)
	{
		if (_spots[i]->parkVehicle(v))
		{
			availableSpots[v->getSize()]--;
			return true;
		}
	}
	return false;
}



void Level::displayAvailableSlots()
{
	cout << "On Floor :" << _floor << endl;
	cout << "Available Slots for Bike = " << availableSpots[0] << endl;
	cout << "Available Slots for car  = " << availableSpots[1] << endl;
	cout << "Available Slots for Bus  = " << availableSpots[2] << endl;
}