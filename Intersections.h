#ifndef INTERSECTION_H_
#define INTERSECTION_H_


enum enumIntersection {
    EMPTY,
    WHITE = 'W',
    BLACK = 'B'
};

class Intersection {
public:
    Intersection();

    Intersection(char tour);

    enumIntersection getStone() const;

    void edit(const enumIntersection &value);

private:

    enumIntersection intersection;
};


#endif /* INTERSECTION_H_ */
