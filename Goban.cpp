#include <cassert>
#include <iostream>
#include <cmath>

using namespace std;

#include "Goban.h"


Goban::Goban() {
    createGoban(19);
}


Goban::~Goban() {

}

unsigned int Goban::getSize() const {
    return size;
}

unsigned int Goban::access(unsigned int x, unsigned int y) const {
    return getSize() * y + x;
}

void Goban::createGoban(unsigned int cote) {
    assert(cote < 20 && cote > 0);
    if (!board.empty())
        board.clear();
    board.resize(cote * cote);
    size = cote;
}


enumIntersection Goban::getStone(unsigned int x, unsigned int y) const {
    assert(x < getSize() && y < getSize());
    /*retourne la valeur de l'intersection � la position (x,y)*/
    return (board.at(access(x, y))).getStone();

}

void Goban::editStone(unsigned int x, unsigned int y, char value) {
    assert(x < getSize() && y < getSize());
    /*�dite la value de l'intersection � la position (x,y)*/
    (board.at(access(x, y))).edit((enumIntersection) value);
}
