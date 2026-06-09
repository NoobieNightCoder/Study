#pragma once

class AppController {
private:
    int currentFloor = 1;
    int targetFloor = 0;
    
    int getCurrentFloor();
    void setCurrentFloor(int floor);

    int getTargetFloor();
    void setTargetFloor(int floor);
public:
    void elevatorCall(int floor);
};