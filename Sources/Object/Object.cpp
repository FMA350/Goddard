
#include "Object.h"
#include "math.h"

Object::Object(char* name, Coordinate initialPosition, Coordinate initialSpeed, long double mass, long double radius){
        acceleration = Coordinate();
        position = Coordinate();
        speed    = Coordinate();
        position.setCoordinate(initialPosition.x, initialPosition.y, initialPosition.z);
        speed.setCoordinate(initialSpeed.x, initialSpeed.y, initialSpeed.z);
        
        this->name = name; //TODO: port name to std::string
        this->mass = mass;
        this->radius = radius;
}

Object::Object(){
    name = "";
    acceleration = Coordinate();
    position = Coordinate();
    speed    = Coordinate();
    mass     = 9.109E-31;    //initialized as the mass of an electron
    radius   = 1E-15;        //circa the size of an electron
}

Object::~Object(){
}

void Object::setPosition(Coordinate newPosition){
    position = newPosition;
}
void Object::setSpeed(Coordinate newSpeed){
    speed.setCoordinate(newSpeed.x, newSpeed.y, newSpeed.z);
}
void Object::setAcceleration(Coordinate newAcceleration){
    acceleration.setCoordinate(newAcceleration.x,newAcceleration.y, newAcceleration.z);
}

Coordinate Object::getAcceleration(){
    return acceleration;
}
Coordinate Object::getPosition(){
    return position;
}
Coordinate Object::getSpeed(){
    return speed;
}

std::string Object::getObjectName(){
    return name;
}

long double Object::getMass(){
    return mass;
}

long double Object::getRadius(){
    return radius;
}

long double Object::calculateKineticEnergy(){
    return ((speed.x*speed.x + speed.y*speed.y + speed.z*speed.z)*mass)/2;
}






