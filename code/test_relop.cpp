#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "input_type.cpp"
#include "token.cpp"
#include "lexer.cpp"
#include "procedure_functions.cpp"
using namespace std;
void test_Relop();

int main(int argc, char *argv[])
{
  test_Relop();
  return 0;
}

void test_Relop()
{
    ifstream input_file("testcase_Relop.txt");
    vector<token_323> all_tokens;
    int location = 0;
    
    bool test_results = false;
    int end_file;

    while (!input_file.eof()) {
        all_tokens.push_back(lexer_323(input_file));
        end_file = input_file.peek();
        if (end_file == EOF) {
            break;
        }
    }


    test_results = procedure_Relop(all_tokens, location);

    if (test_results == false) {
        cout << "Failed: Testing of R24<Relop>" << endl;
    } else {
        cout << "Passed: Testing of R24<Relop>" << endl;
    }

    cout << "\nHere are all the tokens in the vector:" << endl;
    for (auto token : all_tokens) {
        token.token_print_helper();
    }

    input_file.close();

    return;
}