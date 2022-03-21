#ifndef ELEVATOR_H
#define ELEVATOR_H
#include <iostream>
#include <set>

namespace ElevatorSystem {

enum Direction {
    UP,
    DOWN,
    IDLE
};

class ELevator {
public:
    std::string id;
    int floors;
    int current_floor;
    std::set<int>* pushed_floors; 
    Direction direction;
public:
    ELevator();
    ELevator(int floors);
    ~ELevator();
    ELevator(const ELevator& other_ele);
    ELevator& operator=(const ELevator& other_ele);

    const std::string& getDirection() const;
    void ride();
    void process_request(int floor_request);
};

}

#endif