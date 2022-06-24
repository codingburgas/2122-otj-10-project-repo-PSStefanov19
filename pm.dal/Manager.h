#pragma once

#include <string>
#include <iostream>
#include <numeric>
#include <fstream>
namespace pm::dal 
{
    class Manager
    {
    public:
        template<class...A> 
        void create(std::string filename, A... args) 
        {
            std::fstream file(filename, std::ios::out | std::ios::app);
            ((file << args << ','),...);
            file << '\n';
        }
    };
}

#include "Manager.cpp"
