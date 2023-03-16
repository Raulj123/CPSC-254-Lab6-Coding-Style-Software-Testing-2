#include "./lexer.hpp"


struct instruction_table
{
    string op;
    string oprnd;

    void new_instruction(string ope, string opre){}
    void print_ins(ofstream& outfile){}
};

struct symbol_table_element
{
    //Identifier   MemoryLocation       Type
    string Identifier;
    int MemoryLocation;
    string Type;
    
    int get_ml(string id){}
    void print_element(ofstream& outfile){}
};