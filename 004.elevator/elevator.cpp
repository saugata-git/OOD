#include <iostream>
#include <set>
#include "elevator.h"
using namespace std;

ELevator::ELevator(){
    floors = 0;
    current_floor = 0;
    direction = Direction::IDLE;
    pushed_floors = new set<int>;
}

ELevator::ELevator(int floors){
    this->floors = floors;
    current_floor = 0 ;
    direction = Direction::IDLE;
    pushed_floors = new set<int>;
}

ELevator::~ELevator(){
    delete pushed_floors;
}

ELevator::ELevator(const ELevator& other_ele){
    floors = other_ele.floors;
    current_floor = other_ele.current_floor;
    direction = other_ele.direction;
    pushed_floors = other_ele.pushed_floors;
    *this = other_ele;
    return;
}

ELevator& ELevator::operator=(const ELevator& other_ele){
   if( &other_ele != this){
        floors = other_ele.floors;
        current_floor = other_ele.current_floor;
        direction = other_ele.direction;
        pushed_floors = other_ele.pushed_floors;
        *this = other_ele;
    }
   return;
}

std::string ELevator::getDirection(){
    if(direction == Direction::UP){
        return "UP";
    }
    else if(direction == Direction::DOWN){
        return "DOWN";
    }
    else{
        return "IDLE";
    }
}

void Elevator::setId(std::string id){
	this->id = id;
	return;
}

std::string Elevator::getId() {
	return id;
}


void Elevator::ride(){
	int i;
	if(direction == Direction::UP){
		i = 0;
	}
	else{
		i = pushed_floors.size();
	}
	while(!pushed_floors.empty() && direction != Direction::IDLE){
		if (direction == Direction::UP){
			std::cout <<"Elevator " << id << " going up!" << endl;
			current_floor = pushed_floors[i];
			std::cout << "Elevator" << id << " stopping at floor:" << pushed_floors[i] << endl;
			std::cout << "Press a button to go to a desired floor." << endl;
			int floor_request;
			std::cin >> floor_request;
			process_request(floor_request);
			i++;
		}
		else{
			cout <<"Elevator " << id << " going up!" << endl;
			current_floor = pushed_floors[i];
			std::cout << "Elevator" << id << " stopping at floor:" << pushed_floors[i] << endl;
			std::cout << "Press a button to go to a desired floor." << endl;
			int floor_request;
			std::cin >> floor_request;
			process_request(floor_request);
			i--;
		}
	}
	cout << "Elevator " << id << " is returning to idle service now." << endl;
	direction = Direction::IDLE;
	return;
}




void Elevator::process_request(int floor_request){
	if (direction == Direction::UP &&  floor_request < current_floor){
		cout << "Sorry, Elevator " << id << " is going up right now." << endl;
	}
	else if (direction == Direction::DOWN && floor_request > current_floor){
		cout << "Sorry, Elevator " << id << " is going down right now." << endl;
	}
	else{
		pushed_floors.insert(floor_request);
		cout << "New request to go to floor " << floor_request << endl;
	}
	return;
}