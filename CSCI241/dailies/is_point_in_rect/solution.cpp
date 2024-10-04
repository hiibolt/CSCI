/***************************************************************
CSCI 241         John White     Spring 2024

Programmer: z19942444

Section: 241-0002

Date Due: ASAP

Purpose: Check if a point is inside a rectangle.
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/



#include "shapes.h"

/**
 * @brief Check if a point is inside a rectangle
 * 
 * @param p The point to check
 * @param r The rectangle to check
 * 
 * @return true if the point is inside the rectangle, false otherwise
 */
bool is_inside ( const point& p, const rectangle& r ) {
    return !(p.x < r.origin.x || p.x > r.origin.x + r.width || p.y < r.origin.y || p.y > r.origin.y + r.height);
}