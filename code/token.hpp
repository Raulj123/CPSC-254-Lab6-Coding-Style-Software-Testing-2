#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
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

class token_323 {
private:
    std::string token_323_;
    std::string lexeme_323_;


public:
    
    std::vector<instruction_table> all_instructions;
    std::vector<std::string> rule_holder;


    //constructor destructor
    token_323();

    //~token323();

    //accessor and modifier functions------------------------------------------
    std::string token();
    std::string lexeme();
    void token_update(std::string token);
    void lexeme_update(std::string lexeme);
    //void rule_holder_update(std::string rule) { }

    //function that helps print out rules
    void rule_print_helper();


    //functions used to help print------------------------------------------
    void start_print_helper();

    void token_print_helper();
};
