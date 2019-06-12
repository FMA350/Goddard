#include "Universe.h"
#include "stdio.h"
#include "math.h"

#define GRAVITATIONAL_CONSTANT 6.67408E-11
using namespace std;

Universe::Universe(){
    //nothing to initialize
}

Universe::~Universe(){
    //TODO: pop every element from objects
}

int Universe::getNumberOfObjects(){                 //Prints the number of objects in the array
    return objects.size();
}

Object Universe::getObjectCopy(int position){
    if (objects.size() <= position){
        //TODO: implement error handling
        return Object();
    }
    return objects.at(position);         //Return a pointer to a copy of that object        
}

void Universe::addObject(Object newObject){        //Adds an object to the array and resizes it if necessary
   objects.push_back(newObject);
}

void Universe::removeObject(int position){
    cout << "Removing ";
    this->print(position);

    if(position >= objects.size()){
        return;
    }
    if(position!=(objects.size()-1)){ //it is not in last position, swap it
        swap(objects[position], objects[objects.size()-1]);
    }
    objects.erase(objects.end()-1); // it is the last element
}


void Universe::setObject(int n, Object newObject){ //changes the object at n position and deletes the previous one
    if(n >= objects.size()){
        return;
    }
    else{
        objects[n] = newObject;
    }
}

//FOR TESTING


void Universe::printAll(){
    for(int i = 0; i < objects.size(); i++){
        this->print(i);
    }


}
void Universe::print(int positionOfTheObject){
    cout << "Object "<< positionOfTheObject <<" name: " << objects.at(positionOfTheObject).getObjectName() << endl;
}

long double Universe::calculateDistance(int index1, int index2){
    long double absoluteDistancex = objects[index1].getPosition().x - objects[index2].getPosition().x;
    long double absoluteDistancey = objects[index1].getPosition().y - objects[index2].getPosition().y;
    long double absoluteDistancez = objects[index1].getPosition().z - objects[index2].getPosition().z;
    return sqrt(absoluteDistancex*absoluteDistancex+absoluteDistancey*absoluteDistancey+absoluteDistancez*absoluteDistancez);
}

long double Universe::calculateObjectGravitationalEnergy(int position){
    long double gravitationalEnergy = 0;
    for(int i=0; i<objects.size();i++){
        if(i != position){
            long double distance = calculateDistance(position, i);
            gravitationalEnergy -= (GRAVITATIONAL_CONSTANT*objects[i].getMass()*objects[position].getMass())/distance;
        }
    }
    return gravitationalEnergy;
}
long double Universe::calculateTotalObjectEnergy(int position){
    return calculateObjectGravitationalEnergy(position) + objects[position].calculateKineticEnergy();
}

long double Universe::calculateTotalSystemEnergy(){
    long double totalEnergy = 0;
    for(int i; i<objects.size();i++){
        totalEnergy += calculateTotalObjectEnergy(i);
    }
    return totalEnergy;
}