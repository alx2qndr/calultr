#include "calultr/program.hpp"
#include <iostream>

int main()
{
    try
    {
        calultr::program program;
        return program.run();
    } 
    catch (const std::exception& exception) 
    {
        std::cerr << "Exception: " << exception.what() << std::endl;
        return -1;
    } 
    catch (...) 
    {
        std::cerr << "Unknown error occurred." << std::endl;
        return -1;
    }

    return 0;
}