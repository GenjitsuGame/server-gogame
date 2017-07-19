#ifndef GOBAN_H_
#define GOBAN_H_

#include<vector>
#include <string>
#include "Intersections.h"


using namespace std;

class Goban {
public:

    Goban();

    Goban(string serializedGoban);

    ~Goban();

    unsigned int getSize() const;

    unsigned int access(unsigned int x, unsigned int y) const;

    void createGoban(unsigned int cote);

    enumIntersection getStone(unsigned int x, unsigned int y) const;

    void editStone(unsigned int i, char value);

    void editStone(unsigned int x, unsigned int y, char value);

    void editStone(string serializedMove);

    string serialize();

    static const unsigned int SERIALIZED_MOVE_LENGTH = 5;
private:
    vector<Intersection> board;
    unsigned int size;

};


#endif /* GOBAN_H_ */
