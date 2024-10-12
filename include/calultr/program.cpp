#include "calultr/program.hpp"

namespace calultr
{
	int program::run()
	{
		std::cout << "Welcome to calultr!" << std::endl;
		std::cout << "Enter two numbers and an operation (+, -, *, /) or 'exit' to quit:" << std::endl;

		while (true)
		{
			double number0 = 0.0, number1 = 0.0;
			std::string operation;

			std::string input;
			std::getline(std::cin, input);

			if (input == "exit")
			{
				std::cout << "Exiting the program." << std::endl;
				break;
			}

			std::istringstream input_stream_parser(input);
			if (!(input_stream_parser >> number0 >> operation >> number1))
			{
				std::cout << "Invalid input. Please enter two numbers and an operation." << std::endl;
				continue;
			}

			double result = 0.0;

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
					if (number1 != 0) 
					{
						result = number0 / number1;
					} 
					else 
					{
						throw std::runtime_error("Error: Cannot divide by zero.");
						continue;
					}
					break;
				default:
					throw std::runtime_error("Error: Unknown operation.");
					continue;
			}
			
			std::cout << std::fixed;
			std::cout << std::setprecision(6);

			if (std::floor(result) == result) 
			{
				std::cout << "Result: " << static_cast<int>(result) << std::endl;
			} 
			else 
			{
				std::cout << "Result: " << result << std::endl;
			}
		}
			
		return 0;
	}
	
	int program::getOperationType(const std::string& operation) const
	{
		if (operation == "+") return ADDITION;
		if (operation == "-") return SUBTRACTION;
		if (operation == "*") return MULTIPLICATION;
		if (operation == "/") return DIVISION;

		return UNKNOWN;
	}
};