#include"parkinglot.h"

int main(){
        ParkingLot parkingLot;
        parkingLot.displayFreeSlots();
   
	Vehicle bike("pulser", small);
	parkingLot.ParkVehicle(&bike);

	parkingLot.displayFreeSlots();

	Vehicle car("nano", medium);
	parkingLot.ParkVehicle(&car);
	
	bike.removeVehicle();

	parkingLot.displayFreeSlots();

	Vehicle bus("mahindra", large);
	parkingLot.ParkVehicle(&bus);

	parkingLot.displayFreeSlots();

        return 0;
}
