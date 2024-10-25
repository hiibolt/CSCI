#include "vector3.h"

#include <iostream>

/**
  * @brief Default constructor
 */
vector3::vector3 ( double x, double y, double z ) {
	this->x = x;
	this->y = y;
	this->z = z;
};

/**
  * @brief Overload the << operator
 */
std::ostream& operator<< ( std::ostream& os, const vector3& obj ) {
	os << "(" << obj.x << ", " << obj.y << ", " << obj.z << ")";
	
	return os;
};

/**
  * @brief Overload the + operator
 */
vector3 vector3::operator+ ( const vector3& obj ) const {
	return vector3 ( x + obj.x, y + obj.y, z + obj.z );
};

/**
  * @brief Overload the - operator
 */
vector3 vector3::operator- ( const vector3& obj ) const {  
	return vector3 ( x - obj.x, y - obj.y, z - obj.z );
};

/**
  * @brief Overload the * operator
  *
  * @note This is the dot product
 */
double vector3::operator* ( const vector3& obj ) const {
	return x * obj.x + y * obj.y + z * obj.z;
};
/**
  * @brief Overload the * operator
  *
  * @note This is the scalar product for vector * double
 */
vector3 vector3::operator* ( double obj ) const {
	return vector3 ( x * obj, y * obj, z * obj );
};
/**
  * @brief Overload the * operator
  *
  * @note This is the scalar product for double * vector
 */
vector3 operator* ( double obj, const vector3& obj2 ) {
	return vector3 ( obj * obj2.x, obj * obj2.y, obj * obj2.z );
};

/**
  * @brief Overload the == operator
 */
bool vector3::operator== ( const vector3& obj ) const {
	return ( x == obj.x && y == obj.y && z == obj.z );
};

/**
  * @brief Overload the [] operator
  *
  * @note This is the getter
 */
double vector3::operator[] ( size_t i ) const {
	if ( i == 0 ) return x;
	if ( i == 1 ) return y;
	if ( i == 2 ) return z;

	std::cerr << "Error: index out of range" << std::endl;
	exit ( 1 );
};

/**
  * @brief Overload the [] operator
  *
  * @note This is the setter
 */
double& vector3::operator[] ( size_t i ) {
	if ( i == 0 ) return x;
	if ( i == 1 ) return y;
	if ( i == 2 ) return z;

	std::cerr << "Error: index out of range" << std::endl;
	exit ( 1 );
};