#include "calultr/program.hpp"

namespace calultr
{
    int program::run()
    {
        std::cout << "Welcome to the Calultr!" << std::endl;
        std::cout << "Enter two numbers and an operation (+, -, *, /) to get the result." << std::endl;

        while (true)
        {
            std::string operation;
            double number0 = 0.0f, number1 = 0.0f, result = 0.0f;

            std::cout << "Input: ";
            std::cin >> number0 >> operation >> number1;

            if (std::cin.fail()) 
            {
                std::cerr << "Invalid input. Please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if (getOperationType(operation) == UNKNOWN)
            {
                std::cerr << "Unknown operation! Please try again." << std::endl;
                continue;
            }

            switch (getOperationType(operation))
            {
            case ADDITION:
                result = number0 + number1;
                break;
            case SUBTRACTION:
                result = number0 - number1;
                break;
            case MULTIPLICATION:
                result = number0 * number1;
                break;
            case DIVISION:
                if (number1 == 0.0) 
                {
                    std::cerr << "Cannot divide by zero." << std::endl;
                    continue;
                }
                result = number0 / number1;
                break;
            
            default:
                break;
            }

			std::cout << std::fixed;
			std::cout << std::setprecision(8);
        
            std::cout << "Result: " << result << std::endl;
        }

        return 0;
    }

    int program::getOperationType(const std::string& input) const
    {
        if (input == "+") return ADDITION;
        if (input == "-") return SUBTRACTION;
        if (input == "*") return MULTIPLICATION;
        if (input == "/") return DIVISION;
    
        return UNKNOWN;
    }
}
