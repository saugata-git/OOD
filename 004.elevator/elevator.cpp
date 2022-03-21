#include <iostream>
#include <set>
#include "elevator.h"
using namespace std;


ElevatorSystem::ELevator::ELevator(){
    floors = 0;
    current_floor = 0;
    direction = Direction::IDLE;
    pushed_floors = new set<int>;
}

ElevatorSystem::ELevator::ELevator(int floors){
    this->floors = floors;
    current_floor = 0 ;
    direction = Direction::IDLE;
    pushed_floors = new set<int>;
}

ElevatorSystem::ELevator::~ELevator(){
    delete pushed_floors;
}

ElevatorSystem::ELevator::ELevator(const ElevatorSystem::ELevator& other_ele){
    floors = other_ele.floors;
    current_floor = other_ele.current_floor;
    direction = other_ele.direction;
    pushed_floors = other_ele.pushed_floors;
    *this = other_ele;
    return;
}

ElevatorSystem::ELevator& ElevatorSystem::ELevator::operator=(const ElevatorSystem::ELevator& other_ele){
   if( &other_ele != this){
        floors = other_ele.floors;
        current_floor = other_ele.current_floor;
        direction = other_ele.direction;
        pushed_floors = other_ele.pushed_floors;
        *this = other_ele;
    }
   return;
}

std::string ElevatorSystem::ELevator::getDirection(){
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

void ElevatorSystem::ELevator::ride(){
	set<int>::iterator itr;
	if(direction == Direction::UP){
		itr = pushed_floors->begin();
	}
	else{
		itr = pushed_floors->end();
	}
	while(!pushed_floors->empty() && direction != Direction::IDLE){
		if (direction == Direction::UP){
			std::cout <<"Elevator " << id << " going up!" << endl;
			current_floor = *itr;
			std::cout << "Elevator" << id << " stopping at floor:" << current_floor << endl;
			std::cout << "Press a button to go to a desired floor." << endl;
			int floor_request;
			std::cin >> floor_request;
			process_request(floor_request);
			itr++;
		}
		else{
			cout <<"Elevator " << id << " going down!" << endl;
			current_floor = *itr;
			std::cout << "Elevator" << id << " stopping at floor:" << current_floor << endl;
			std::cout << "Press a button to go to a desired floor." << endl;
			int floor_request;
			std::cin >> floor_request;
			process_request(floor_request);
			itr--;
		}
	}
	cout << "Elevator " << id << " is returning to idle service now." << endl;
	direction = Direction::IDLE;
	return;
}

void ElevatorSystem::ELevator::process_request(int floor_request){
	if (direction == Direction::UP &&  floor_request < current_floor){
		cout << "Sorry, Elevator " << id << " is going up right now." << endl;
	}
	else if (direction == Direction::DOWN && floor_request > current_floor){
		cout << "Sorry, Elevator " << id << " is going down right now." << endl;
	}
	else{
		pushed_floors->insert(floor_request);
		cout << "New request to go to floor " << floor_request << endl;
	}
	return;
}