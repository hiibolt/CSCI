#include "complex.h"
#include <iostream>
#include <tuple>
#include <string>
#include <limits>

complex::complex ( double real, double imag ) {
	this->real = real;
	this->imag = imag;
}

// Getters
std::tuple<double, double> complex::get_complex ( ) const {
	return std::make_tuple( this->real, this->imag );
};
double complex::get_real ( ) const {
	return this->real;
};
double complex::get_imaginary ( ) const {
	return this->imag;
};

// Setters
void complex::set_complex ( double real, double imag ) {
	this->real = real;
	this->imag = imag;
};
void complex::set_real ( double real ) {
	this->real = real;
};
void complex::set_imaginary ( double imag ) {
	this->imag = imag;
};

// Operators
complex complex::operator+ ( const complex& other ) const {
	double real = ( this->real + other.get_real()      );
	double imag = ( this->imag + other.get_imaginary() );

	return complex( real, imag );
};
complex complex::operator*  ( const complex& other ) const {
	double a = this->real;
	double b = this->imag;
	double c = other.get_real();
	double d = other.get_imaginary();
	
	double real = ( a * c - b * d );
	double imag = ( a * d + b * c );

	return complex( real, imag );
};
bool complex::operator== ( const complex& other ) const {
	return ( this->real == other.get_real() ) && ( this->imag == other.get_imaginary() );
};
std::ostream& operator<< ( std::ostream& os, const complex& c ) {
	os << "(" << c.get_real() << ", " << c.get_imaginary() << ")";

	return os;
};
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

