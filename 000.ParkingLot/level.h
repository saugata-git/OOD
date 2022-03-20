#ifndef _LEVEL_H
#define _LEVEL_H

#include<vector>
#include "parkingspot.h"

class Level {
    int _floor;
    std::vector<ParkingSpot*> _spots;
    int availableSpots[3];
public:
    Level(int _flr, int _nbr_of_spots);

    void spotFreed(VehicleSize size){
        availableSpots[size]++;
    }

    bool parkVehicle(Vehicle *v);
	void displayAvailableSlots();

};


#endif