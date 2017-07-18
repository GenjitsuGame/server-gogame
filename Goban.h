#ifndef GOBAN_H_
#define GOBAN_H_

#include<vector>
#include "Intersections.h"


using namespace std;

class Goban {
public:

    Goban();

    ~Goban();

    unsigned int getSize() const;

    unsigned int access(unsigned int x, unsigned int y) const;

    void createGoban(unsigned int cote);

    enumIntersection getStone(unsigned int x, unsigned int y) const;

    void editStone(unsigned int x, unsigned int y, char value);

private:

    vector<Intersection> board;
    unsigned int size;

};


#endif /* GOBAN_H_ */
