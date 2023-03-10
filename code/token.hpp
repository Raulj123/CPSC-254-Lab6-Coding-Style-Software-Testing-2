#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class token_323 {
    private:
        std::string token_323_;
        std::string lexeme_323_;

    public:
        // Default constructor
        token_323() {}

        // Accessor and modifier functions
        std::string token() {}
        std::string lexeme() {}
        void token_update(std::string token) {}
        void lexeme_update(std::string token) {}

        // Functions to help print out rules
        void rule_print_helper() {}
        void start_print_helper() {}
        void token_print_helper() {}
};

#endif