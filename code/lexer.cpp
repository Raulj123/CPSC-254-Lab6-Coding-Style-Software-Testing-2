#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include "lexer.hpp"
#include "input_type.hpp"
#include "token.hpp"
#include "table.hpp"
using namespace std;


//lexer machine
token_323 lexer_323(ifstream& input_file) {

    token_323 return_token;
    int state = 1;
    char input_char;
    input_file.get(input_char);
    std::string token_string = "";
    token_string.push_back(input_char);

    //firstly check the first char and determine which machine to go to
    if (isdigit(input_char)) //case for int/real
    {
        while (input_file.eof() != true && is_accepting_intreal(state)) //keep reading char until terminates a token
        {
            input_file.get(input_char);
            token_string.push_back(input_char);
            state = intrealFSM(state, input_char);
        }
        if (input_file.eof() != true)
        {//if not end of file, return 1 char
            input_file.unget();
            token_string.pop_back();
        }
        std::string return_token_st = ending_state_intreal(state);
        std::string return_lexeme_st = token_string;
        return_token.token_update(return_token_st);
        return_token.lexeme_update(return_lexeme_st);
        return return_token;
    }
    else if (isalpha(input_char)) //case for id
    {
        while (input_file.eof() != true && is_accepting_id(state)) //keep reading char until terminates a token
        {
            input_file.get(input_char);
            token_string.push_back(input_char);
            state = idFSM(state, input_char);
        }
        if (input_file.eof() != true)
        {//if not end of file, return 1 char
            input_file.unget();
            token_string.pop_back();
        }
        std::string return_token_st = ending_state_id(state);
        std::string return_lexeme_st = token_string;
        return_token.lexeme_update(return_lexeme_st);
        if (isKeyword(return_lexeme_st))
        {
            return_token_st = "Keyword";
        }
        return_token.token_update(return_token_st);
        return return_token;
    }
    else if (isWhitespace(input_char))
    {//case for whitespace
        std::string return_token_st = "Other Separators";
        std::string return_lexime_st = token_string;
        //update token class with info we get and return
        return_token.token_update(return_token_st);
        return_token.lexeme_update(return_lexime_st);
        return return_token;
    }
    else if (input_char =='\0' || input_file.eof())
    {
        std::cout << "error";
        return return_token;
    }
    else //case for other seperator/operators
    {   //determine what typen of token input char is
        std::string return_token_st = operator_or_separator(input_char);
        std::string return_lexime_st = token_string;
        char char_holder_2;
        if (return_lexime_st == "$")
        {
            input_file.get(char_holder_2);
            if (char_holder_2 == '$')
            {
                return_lexime_st += char_holder_2;
            }
            else
            {
                input_file.unget();
            }
        }
        else if (return_lexime_st == "!")
        {
            input_file.get(char_holder_2);
            if (char_holder_2 == '=')
            {
                return_lexime_st += char_holder_2;
            }
            else
            {
                input_file.unget();
            }
        }
        else if (return_lexime_st == "=")
        {
            input_file.get(char_holder_2);
            if (char_holder_2 == '=' || char_holder_2 == '>')
            {
                return_lexime_st += char_holder_2;
            }
            else
            {
                input_file.unget();
            }
        }
        else if (return_lexime_st == "<")
        {
            input_file.get(char_holder_2);
            if (char_holder_2 == '=')
            {
                return_lexime_st += char_holder_2;
            }
            else
            {
                input_file.unget();
            }
        }
        else if (return_lexime_st == "/")
        {
            input_file.get(char_holder_2);
            if (char_holder_2 == '*')
            {
                bool loopc = true;
                while (loopc == true) 
                {
                    input_file.get(char_holder_2);
                    if (char_holder_2 == '*') 
                    {
                        input_file.get(char_holder_2);
                        
                        if (char_holder_2 == '/') 
                        {
                            loopc = false;
                            return_lexime_st == "Ignored";
                            return_token_st = "Comments";
                        }
                        else
                        {
                            input_file.unget();
                        }
                    }
                    
                }
            }
            else
            {
                input_file.unget();
            }
        }
        //update token class with info we get and return
        return_token.token_update(return_token_st);
        return_token.lexeme_update(return_lexime_st);
        return return_token;
    }
}