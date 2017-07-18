#include "Intersections.h"

Intersection::Intersection()
{
	intersection = EMPTY;
}

Intersection::Intersection(char tour)
{
    intersection = (tour == 'N' ? WHITE : BLACK);
}

enumIntersection Intersection::getStone() const
{
	return intersection;
}

void Intersection::edit(const enumIntersection& value)
{
	intersection = value;
}
