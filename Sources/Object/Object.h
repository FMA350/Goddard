#include "../Coordinate/Coordinate.h"
#include<iostream>


//#include "../Interfaces/Dynamical/Dynamical.h"

class Object{
    private:
        Coordinate position;
        Coordinate speed;
        Coordinate acceleration; //needed? probably not.
        long double mass;
        long double radius;
        std::string name;
    public:
        //Initializers
        Object(char* name, Coordinate initialPosition, Coordinate initialSpeed, long double mass, long double radius);
        Object();
        ~Object();
        ///Setters
        void setPosition(Coordinate newPosition);
        void setSpeed(Coordinate newSpeed);
        void setAcceleration(Coordinate newAcceleration);
        //Getters
        Coordinate getPosition();
        Coordinate getSpeed();
        Coordinate getAcceleration();
        long double getMass();
        long double getRadius();
        std::string getObjectName();
        //Methods
        long double calculateKineticEnergy();

};