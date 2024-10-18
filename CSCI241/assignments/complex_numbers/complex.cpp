#include "complex.h"
#include <iostream>
#include <tuple>
#include <string>
#include <limits>

/**
 * @brief Default constructor for the complex class
 *
 * @arg double real - The real part of the complex number
 * @arg double imag - The imaginary part of the complex number
 *
 * @return complex - The complex number object
 */
complex::complex ( double real, double imag ) {
	this->real = real;
	this->imag = imag;
}

// Getters
/**
 * @brief Get the complex number as a tuple
 *
 * @return std::tuple<double, double> - The complex number as a tuple
 */
std::tuple<double, double> complex::get_complex ( ) const {
	return std::make_tuple( this->real, this->imag );
};
/**
 * @brief Get the real part of the complex number
 *
 * @return double - The real part of the complex number
 */
double complex::get_real ( ) const {
	return this->real;
};
/**
 * @brief Get the imaginary part of the complex number
 *
 * @return double - The imaginary part of the complex number
 */
double complex::get_imaginary ( ) const {
	return this->imag;
};

// Setters
/**
 * @brief Set the complex number
 *
 * @arg double real - The real part of the complex number
 * @arg double imag - The imaginary part of the complex number
 */
void complex::set_complex ( double real, double imag ) {
	this->real = real;
	this->imag = imag;
};
/**
 * @brief Set the real part of the complex number
 *
 * @arg double real - The real part of the complex number
 */
void complex::set_real ( double real ) {
	this->real = real;
};
/**
 * @brief Set the imaginary part of the complex number
 *
 * @arg double imag - The imaginary part of the complex number
 */
void complex::set_imaginary ( double imag ) {
	this->imag = imag;
};

// Operators
/**
 * @brief Add two complex numbers together
 *
 * @arg const complex& other - The other complex number to add
 *
 * @return complex - The sum of the two complex numbers
 */
complex complex::operator+ ( const complex& other ) const {
	double real = ( this->real + other.get_real()      );
	double imag = ( this->imag + other.get_imaginary() );

	return complex( real, imag );
};
/**
 * @brief Subtract two complex numbers
 *
 * @arg const complex& other - The other complex number to subtract
 *
 * @return complex - The difference of the two complex numbers
 */
complex complex::operator*  ( const complex& other ) const {
	double a = this->real;
	double b = this->imag;
	double c = other.get_real();
	double d = other.get_imaginary();
	
	double real = ( a * c - b * d );
	double imag = ( a * d + b * c );

	return complex( real, imag );
};
/**
 * @brief Multiply two complex numbers
 *
 * @arg const complex& other - The other complex number to multiply
 *
 * @return complex - The product of the two complex numbers
 */
bool complex::operator== ( const complex& other ) const {
	return ( this->real == other.get_real() ) && ( this->imag == other.get_imaginary() );
};
/**
 * @brief Check if two complex numbers are equal
 *
 * @arg const complex& other - The other complex number to compare
 *
 * @return bool - Whether the two complex numbers are equal
 */
std::ostream& operator<< ( std::ostream& os, const complex& c ) {
	os << "(" << c.get_real() << ", " << c.get_imaginary() << ")";

	return os;
};
/**
  * @brief Output the complex number to a stream
  *
  * @arg std::ostream& os - The output stream
  * @arg const complex& c - The complex number to output
  *
  * @return std::ostream& - The output stream
  */
std::istream& operator>> ( std::istream& is, complex& c ) {
	std::string real_buf;
	std::string imag_buf;
	
	is.ignore( std::numeric_limits<std::streamsize>::max(), '(' ); 
	std::getline( is, real_buf, ',' );
	is.ignore( std::numeric_limits<std::streamsize>::max(), ' ' );
	std::getline( is, imag_buf, ')' );

	double real = std::stod( real_buf );
	double imag = std::stod( imag_buf );

	c.set_real      ( real );
	c.set_imaginary ( imag );

	return is;
};

