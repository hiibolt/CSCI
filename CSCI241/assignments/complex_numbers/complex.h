#include <iostream>
#include <tuple>

// Complex Class
class complex {
	public:
		complex ( double real = 0, double imag = 0 );

		// Getters
		std::tuple<double, double> get_complex ( ) const;
		double get_real                        ( ) const;
		double get_imaginary                   ( ) const;

		// Setters
		void set_complex   ( double real, double imag );
		void set_real      ( double real );
		void set_imaginary ( double imag );

		// Operators
		complex operator+  ( const complex& other ) const;
		complex operator*  ( const complex& other ) const;
		bool    operator== ( const complex& other ) const;

	private:
		double real;
		double imag;
};
// Operator Overloads for Complex
std::ostream& operator<< ( std::ostream& os, const complex& c );
std::istream& operator>> ( std::istream& is, complex& c       );
