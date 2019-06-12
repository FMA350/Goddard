
#include "Coordinate.h"

Coordinate::Coordinate(long double x, long double y, long double z){
    this->x = x;
    this->y = y;
    this->z = z;

}

Coordinate::Coordinate(){   //default constructor
    x = 0;
    y = 0;
    z = 0;
}

Coordinate::~Coordinate(){
    //nothing to do here
}


void Coordinate::setCoordinate(long double x, long double y, long double z){
    this->x = x;
    this->y = y;
    this->z = z;
}


void Coordinate::sumCoordinate(long double x, long double y, long double z){
        this->x += x;
        this->y += y;
        this->z += z;
}

