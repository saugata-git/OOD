#ifndef _VEHICLE_H
#define _VEHICLE_H

#include "common.h"
class ParkingSpot;
class Level;

class Vehicle {
    ParkingSpot *_spot;
    std::string _nbr_plate;
    VehicleSize _vehicle_size;
public :
    Vehicle(std::string _nbr, VehicleSize _size):
        _nbr_plate(_nbr) , _vehicle_size(_size) {};

    VehicleSize getSize() const {
        return _vehicle_size;
    }  

    void parkInSpot(ParkingSpot *spot){
        _spot = spot;
    }
     
    void removeVehicle();

};

#endif  