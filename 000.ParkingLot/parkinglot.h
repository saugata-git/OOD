#ifndef _PARKIBGLOT_
#define _PARKIBGLOT_

#include"level.h"

class ParkingLot {
    std::vector<Level*> floors;
    static const int MAX_FLOORS = 2;
public :
    ParkingLot();
    bool ParkVehicle(Vehicle *v);
    void displayFreeSlots();  
};

#endif 