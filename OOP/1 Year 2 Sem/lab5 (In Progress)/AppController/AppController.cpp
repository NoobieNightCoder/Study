#include "AppController.h"

int AppController::getCurrentFloor() {
    return currentFloor;
}

int AppController::getTargetFloor() {
    return targetFloor;
}

void AppController::setCurrentFloor(int floor) {
    currentFloor = floor;
}

void AppController::setTargetFloor(int floor) {
    targetFloor = floor;
}

void AppController::elevatorCall(int floor) {
    int currFloor = getCurrentFloor();
    if(currFloor != floor)
        setTargetFloor(floor);
}