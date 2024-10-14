#pragma once

#include <iostream>
#include <limits>
#include <iomanip>

namespace calultr
{
    enum OperationType 
    {
        ADDITION,
        SUBTRACTION,
        MULTIPLICATION,
        DIVISION,
        UNKNOWN
    };

    class program
    {
    public:
        program() = default;
        program(program&) = delete;

        int run();

    private:
        int getOperationType(const std::string& input) const;
    };
}
