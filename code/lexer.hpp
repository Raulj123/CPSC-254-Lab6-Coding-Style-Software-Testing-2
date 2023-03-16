#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
//#include "procedure_functions.h"
#include "input_type.hpp"
#include "token.hpp"

using namespace std;


struct instruction_table
{
    string op;
    string oprnd;

    void new_instruction(string ope, string opre)
    {
        op = ope;
        oprnd = opre;
    }

    void print_ins(ofstream& outfile)
    {
        std::cout << op << "     " << oprnd << "\n";
        outfile << op << "     " << oprnd << "\n";
    
    }
};


token_323 lexer_323(ifstream& input_file);


