#pragma once

enum class DoorStatus {
    OPENING,
    OPEN,
    CLOSING,
    CLOSE
};

class Doors {
private:
    DoorStatus status;
public:
    Doors(DoorStatus state = DoorStatus::CLOSE) : status(state) {}
    void open() {
        status = DoorStatus::OPEN;
    }

    void close() {
        status = DoorStatus::CLOSE;
    }
};