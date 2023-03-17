#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include "token.hpp"
using namespace std;



token_323 lexer_323(ifstream& input_file);



struct symbol_table_element
{
    //Identifier   MemoryLocation       Type
    string Identifier;
    int MemoryLocation;
    string Type;
    
    int get_ml(string id)
    {
        if (id == Identifier)
        {
            return MemoryLocation;
        }
        else 
        {
            //std::cout << "error, identifier not defined\n";
            return -1;
        }
    }



    void print_element(ofstream& outfile)
    {        
        std::cout << Identifier << "           " << MemoryLocation << "           " << Type << "\n";
        outfile << Identifier << "           " << MemoryLocation << "           " << Type << "\n";
    }
};



