#include "shapes.h"

bool point_in_rect ( const rectangle& r, point p ) {
	return p.x >= r.origin.x && p.x <= r.origin.x + r.width &&
	       p.y >= r.origin.y && p.y <= r.origin.y + r.height;

};
bool overlap ( const rectangle& r1, const rectangle& r2 ) {
	return point_in_rect( r1, point( r2.origin.x, r2.origin.y ) ) ||
		point_in_rect( r1, point( r2.origin.x + r2.width, r2.origin.y ) ) ||
		point_in_rect( r1, point( r2.origin.x, r2.origin.y + r2.height ) ) ||
		point_in_rect( r1, point( r2.origin.x + r2.width, r2.origin.y + r2.height ) );
};


