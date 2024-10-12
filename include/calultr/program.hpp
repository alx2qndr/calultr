#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

enum OperationType
{
    ADDITION       = 1,
    SUBTRACTION    = 2,
    MULTIPLICATION = 3,
    DIVISION       = 4,
    UNKNOWN        = 0
};

namespace calultr
{
    class program
    {
    public:
        program() = default;
        
        program(const program&) = delete;
        program& operator=(const program&) = delete;

        int run();

    private:
        int getOperationType(const std::string& operation) const;
    };
}
