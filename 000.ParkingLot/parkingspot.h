#ifndef _PARKINGSPOT_H
#define _PARKINGSPOT_H

#include "vehicle.h"

class ParkingSpot {
    Vehicle *v;
    VehicleSize _spot_size;
    int _spot_nbr;
    Level *l;
public :
    ParkingSpot( VehicleSize _spot_size, int _spot_nbr ,Level *l)
        : _spot_size(_spot_size), _spot_nbr(_spot_nbr) , l(l)
    {
        v = NULL;
    }

    bool isAvailable() {
        return (v == NULL);
    }

    bool canVehicleFit(Vehicle *v){
        return (v->getSize() == _spot_size);
    }

    bool parkVehicle(Vehicle *v);
    void removeVehicle();
};

#endif






