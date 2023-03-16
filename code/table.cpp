#include "./table.hpp"


void instruction_table::new_instruction(string ope, string opre){
    
        op = ope;
        oprnd = opre;
}
 
 
void instruction_table::print_ins(ofstream& outfile)
{
    std::cout << op << "     " << oprnd << "\n";
    outfile << op << "     " << oprnd << "\n";
    
}


int symbol_table_element::get_ml(string id)
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


void symbol_table_element::print_element(ofstream& outfile)
{        
    std::cout << Identifier << "           " << MemoryLocation << "           " << Type << "\n";
    outfile << Identifier << "           " << MemoryLocation << "           " << Type << "\n";
}