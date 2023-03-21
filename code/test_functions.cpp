//Includes Primary, Term, Print, scan & expression function. Comment all functions besides the one you want to test in main.
//Write your input in input.txt & run like an oridnary cpp file 

#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include "procedure_functions.cpp"
#include "lexer.cpp"
using namespace std;
void test_Primary();
void test_term();
void test_Print();
void test_Scan();
void test_expresssion();
int main(int argc, char *argv[])
{
  //test_Primary();
  //test_term();
  //test_Print();
  //test_Scan();
  test_expresssion();
  return 0;
}
void test_Primary()
{
    ifstream input_file("input.txt");
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

    test_results = procedure_Primary(all_tokens, location);

    if (test_results == false) {
        cout << "Failed: Testing of R28<Primary>" << endl;
    } else {
        cout << "Passed: Testing of R28<Primary>" << endl;
    }

    cout << "\nHere are all the tokens in the vector:" << endl;
    for (auto token : all_tokens) {
        token.token_print_helper();
    }

    input_file.close();

    return;
}

void test_term()
{
    ifstream input_file("input.txt");
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

    test_results = procedure_Term_q(all_tokens, location);

    if (test_results == false) {
        cout << "Failed: Testing of R26.1<<Term'>" << endl;
    } else {
        cout << "Passed: Testing of R26.1<Term'>" << endl;
    }

    cout << "\nHere are all the tokens in the vector:" << endl;
    for (auto token : all_tokens) {
        token.token_print_helper();
    }

    input_file.close();

    return;
}

void test_Print()
{
    ifstream input_file("input.txt");
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

    test_results = procedure_Print(all_tokens, location);

    if (test_results == false) {
        cout << "Failed: Testing of R20. <Print> " << endl;
    } else {
        cout << "Passed: Testing of R20. <Print> " << endl;
    }

    cout << "\nHere are all the tokens in the vector:" << endl;
    for (auto token : all_tokens) {
        token.token_print_helper();
    }

    input_file.close();

    return;
}

void test_Scan()
{
    ifstream input_file("input.txt");
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

    test_results = procedure_Scan(all_tokens, location);

    if (test_results == false) {
        cout << "Failed: Testing of R21. <Scan> " << endl;
    } else {
        cout << "Passed: Testing of R21. <Scan> " << endl;
    }

    cout << "\nHere are all the tokens in the vector:" << endl;
    for (auto token : all_tokens) {
        token.token_print_helper();
    }

    input_file.close();

    return;
}

void test_expresssion(){
     ifstream input_file("input.txt");
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

    test_results = procedure_Expression(all_tokens, location);

    if (test_results == false) {
        cout << "Failed: Testing of R25. <Expression> " << endl;
    } else {
        cout << "Passed: Testing of R25. <Expression> " << endl;
    }

    cout << "\nHere are all the tokens in the vector:" << endl;
    for (auto token : all_tokens) {
        token.token_print_helper();
    }

    input_file.close();

    return;
}