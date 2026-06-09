#pragma once

#include <memory>
#include "Doors.h"

enum class ElevatorStatus {
    STOP,
    PREPARE,
    IN_MOTION,
    CLOSED,
    OPENED
};

class Elevator {
private:
    std::unique_ptr<Doors> myDoors;

public:
};