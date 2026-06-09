#pragma once

class IAppCommand {
public:
    virtual void execute() = 0;

    virtual ~IAppCommand() = default;
};
