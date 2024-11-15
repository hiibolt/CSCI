/***************************************************************
                            lib.h


CSCI 330         John White     Fall 2024

Programmer: z19942444

Section: 330-0001

Date Due: Saturday, September 28rst

Purpose: Emulate the UNIX `dog` command at a rudimentary level
***************************************************************/

/*

    /ᐠ - ˕ -マ 

    @hiibolt on GitHub 

*/



#ifndef SHIFT_H
#define SHIFT_H

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <cerrno>
#include <cstring>


/**
 * @brief Datatype representing absolutely nothing
 */
struct Nothing {};

/**
 * @brief A Result type to handle errors
 */
template <typename T>
class Result {
    private:
        T                        value;
        bool                     ok;
        std::vector<std::string> errors;
    public:
        /**
         * @brief Construct a new Result object
         * 
         * @param value The value to store
         * @param ok Whether the result is successful
         * 
         * EITHER
         * @param err The error message
         * @param err_vec A vector of error messages
         */
        Result ( T value, bool ok, std::string err ) {
            this->value = value;
            this->ok    = ok;

            if ( !ok ) {
                this->errors.push_back(err);
            }
        }
        Result ( T value, bool ok, std::vector<std::string> err_vec ) {
            this->value = value;
            this->ok    = ok;

            if ( !ok ) {
                this->errors = err_vec;
            }
        }

        /**
         * @brief Add a context to the error message
         * 
         * @param err The context to add
         * 
         * @return Result<T>& The Result object
         */
        Result<T>& context ( std::string err ) {
            this->errors.push_back(err);
            return *this;
        }

        /* State Assessors */
        /**
         * @brief Check if the result is successful
         * 
         * @return bool Whether the result is successful
         */
        bool is_ok(){
            return this->ok;
        }
        /**
         * @brief Check if the result is an error
         * 
         * @return bool Whether the result is an error
         */
        bool is_err(){
            return !this->ok;
        }

        /* Unwrappers */
        /**
         * @brief Unwrap the value
         * 
         * @return T The value
         */
        T unwrap() {
            if ( this->is_err() ) {
                size_t err_len = this->errors.size();

                std::cerr << "Program aborting due to fatal error:" << std::endl
                          << "\033[0;31m\t\"" << this->errors[err_len - 1] << "\"\033[00m" 
                          << std::endl << std::endl;

                std::cerr << "Full Stacktrace:" << std::endl;
                for ( size_t i = err_len; i > 0; i-- ) {
                    std::cerr << "\t[" << i << "]: " << this->errors[i - 1] << std::endl;
                }

                exit(1);
            }

            return this->value;
        }
        /**
         * @brief Unwrap the error message
         * 
         * @return std::string The error message
         */
        std::vector<std::string> unwrap_err() {
            return this->errors;
        }
};
/**
 * @brief Create a new successful Result object
 * 
 * @param value The value to store
 * 
 * @return Result<T> The Result object
 */
template <typename T>
Result<T> Ok ( T value ) {
    return Result<T>(value, true, "");
}
/**
 * @brief Create a new error Result object
 * 
 * @param err The error message
 * 
 * @return Result<T> The Result object
 */
template <typename T>
Result<T> Err ( std::string err ) {
    return Result<T>(T(), false, err);
}

// Macro to propagate Result type and return value up a level
#define PROPAGATE(result, ret_type) \
    if (!(result).is_ok()) return Result<ret_type>(ret_type(), false, result.unwrap_err());

// Macro to propagate syscall errors and syscall value up a level
#define PROPAGATE_SYSCALL(value_pointer, syscall_result, ret_type) \
    *value_pointer = syscall_result; if ( *value_pointer == -1 ) return Result<ret_type>(ret_type(), false, strerror(errno));

// Macro to propagate syscall errors
#define PROPAGATE_SYSCALL_NO_RET(syscall_result, ret_type) \
    if ( syscall_result == -1 ) return Result<ret_type>(ret_type(), false, strerror(errno));

Result<int> checked_stoi ( std::string );

/**
 * @brief The program state
 */
struct State {
    // Buffer-Related
    int buffer_size;
    int max_bytes;
    int remaining_bytes;

    // Shift-Related
    bool caeser_shift;
    bool normal_shift;
    int  shift;

    // Representation-Related
    bool binary;
    bool hexa;
};

/* Shifts */
void caeser_shift ( unsigned char *, ssize_t, int );
void normal_shift ( unsigned char *, ssize_t, int );

/* Representation Conversions */
unsigned char* bytesToBinary ( const unsigned char*, size_t );
unsigned char* bytesToHex    ( const unsigned char*, size_t );

/* Print */
Result<Nothing> print         ( unsigned char[], ssize_t len, State *state );
Result<Nothing> print_from_fd ( int,             State *state              );

#endif