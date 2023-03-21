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

//functions used to determine input type-----------------------------------
bool isSeparator(char input);
bool isOperator(char input);
bool isUnderline(char input);
bool isDot(char input);
bool isKeyword(std::string input);
std::string operator_or_separator(char input);
bool isWhitespace(char input);
//2FSMs and helper functions
int FSM_col_determiner(char input);

int idFSM(int state, char input);
bool is_accepting_id(int state);

int intrealFSM(int state, char input);
bool is_accepting_intreal(int state);
//determine token type based on final state------------------------------------------
std::string ending_state_intreal(int state);
std::string ending_state_id(int state);
