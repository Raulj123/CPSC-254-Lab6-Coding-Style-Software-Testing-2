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


token_323::token_323() {
    token_323_ = "none";
    lexeme_323_= "none";
}

std::string token_323::token() { return token_323_; }
std::string token_323::lexeme() { return lexeme_323_; }
void token_323::token_update(std::string token) { token_323_ = token; }
void token_323::lexeme_update(std::string lexeme) { lexeme_323_ = lexeme; }
void token_323::rule_print_helper() {
    //ofstream& outfile
    //token_print_helper();
    std::string tokenp;
    std::string lexemep;
    tokenp = token();
    lexemep = lexeme();
    std::cout << "Token: " << tokenp << "                   Lexeme: " << lexemep << "\n";
    //outfile << "Token: " << tokenp << "                   Lexeme: " << lexemep << "\n";        
    int k = rule_holder.size() - 1;
    for (int i = k; i >= 0; i--) {
        std::cout << "   " << rule_holder[i] ;
         //outfile << "   " << rule_holder[i];
    }
}
void token_323::start_print_helper() {
    std::cout << "Program begins\n";
    std::cout << std::left << std::setw(15) << "token" << "lexeme" << "\n";
    //std::cout << "token" << "lexeme" << "\n";
    std::cout << "-------------------\n";
}
void token_323::token_print_helper() {
    //ofstream& outfile
    std::string tokenp;
    std::string lexemep;
    tokenp = token();
    lexemep = lexeme();
    std::cout <<"Token: " << tokenp << "                   Lexeme: " << lexemep << "\n";
    //outfile << std::left << std::setw(15) << tokenp << lexemep << "\n";
    //std::cout << lexemep << tokenp << "\n";
    //outfile << lexemep << tokenp << "\n";
}