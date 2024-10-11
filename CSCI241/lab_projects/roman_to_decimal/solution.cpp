#include <iostream>
#include <string>
#include <cstring>

/**
    * @brief Converts a roman numeral character to a decimal integer
    *
    * @arg input The roman numeral character to convert
    *
    * @return The decimal integer
    */
int rchar_to_decimal ( const char &input ) {
    switch ( input ) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -1;
    }
}

/**
    * @brief Converts a roman numeral to a decimal integer
    *
    * @arg input The roman numeral to convert
    *
    * @return The decimal integer
    */
int roman_to_decimal ( const std::string &input ) {
    int ret = 0;
    int prev = 0;

    for ( long unsigned int i = 0; i < input.length(); i++ ) {
        //std::cout << input[i] << " | " << rchar_to_decimal(input[i]) << std::endl;

        if ( rchar_to_decimal(input[i]) > prev ) {
            ret += rchar_to_decimal(input[i]) - 2 * prev;
        } else {
            ret += rchar_to_decimal(input[i]);
        }

        prev = rchar_to_decimal(input[i]);
    }

    return ret;
}