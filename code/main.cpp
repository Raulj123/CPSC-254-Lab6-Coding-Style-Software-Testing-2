
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "input_type.cpp"
#include "token.cpp"
#include "lexer.cpp"
#include "procedure_functions.cpp"

using namespace std;

int main()
{
    int loc = 0;
    ifstream inFile("input.txt");
    vector<token_323> testCase;
    bool testResult = false;
    int check_eof;

    while(!inFile.eof())
    {
        testCase.push_back(lexer_323(inFile));
        check_eof = inFile.peek();
        if(check_eof == EOF)
        {
            break;
        }
    }

    testResult = procedure_If(testCase, loc);
    
     if (testResult == false) {
        std::cout << "Failed: Testing of <If>" << std::endl;
    } else {
        std::cout << "Passed: Testing of <If>" << std::endl;
    }

    std::cout << "\nHere are all the tokens in the vector:" << std::endl;
    for (auto token : testCase) {
        token.token_print_helper();
    }

    inFile.close();
    return 0;
}