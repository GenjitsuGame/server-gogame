#include <cassert>
#include <iostream>
#include <cmath>

using namespace std;

#include "Goban.h"


Goban::Goban() {
    createGoban(19);
}

Goban::Goban(std::string serializedGoban) {
    if (serializedGoban.length() % SERIALIZED_MOVE_LENGTH != 0) {
        throw new std::invalid_argument("Invalid serialized goban.");
    }

    Goban();
    for (int i = 0; i < serializedGoban.length(); i += SERIALIZED_MOVE_LENGTH) {
        editStone(serializedGoban.substr(i, SERIALIZED_MOVE_LENGTH));
    }
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
    return (board.at(access(x, y))).getStone();
}

void Goban::editStone(unsigned int i, char value) {
    board.at(i).edit((enumIntersection) value);
}

void Goban::editStone(unsigned int x, unsigned int y, char value) {
    assert(x < getSize() && y < getSize());
    (board.at(access(x, y))).edit((enumIntersection) value);
}

void Goban::editStone(std::string serializedMove) {
    assert(serializedMove.length() == SERIALIZED_MOVE_LENGTH);
    char player = serializedMove[0];
    unsigned int x = (unsigned int) stoi(serializedMove.substr(1, 2));
    unsigned int y = (unsigned int) stoi(serializedMove.substr(3, 2));
    editStone(x, y, player);
}

std::string Goban::serialize() {
    std::string serialized("C");
    int i = 0;
    for (vector<Intersection>::const_iterator it = board.begin(); it < board.end(); ++it, ++i) {
        Intersection intersection = *it;
        if (intersection.getStone() != EMPTY) {
            serialized += intersection.getStone();
            serialized += i;
        }
    }
    return serialized;
}