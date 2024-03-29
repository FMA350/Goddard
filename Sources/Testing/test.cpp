#include "../Universe/Universe.h"
#include <iostream>

using namespace std;

bool test1(){
    char names[4][20]= {"Pluto", "Venus", "Mars","Jupiter"};

    Universe universe =  Universe();
    cout << "Number of objects at creation: " << universe.getNumberOfObjects() << "\n";
    for(int i=0;i<4;i++){
        Coordinate position = Coordinate(i*1.23+i*i, i*24/1.8, (i*100)/45);
        Coordinate speed    = Coordinate(i*1.23+i*i, i*24/1.8, (i*100)/45);
        Object obj = Object(names[i], position, speed, i*i*100, i*i*10);
        universe.addObject(obj);
    }
    cout << "Number of objects after addition: " << universe.getNumberOfObjects() << "\n";
    Object tmp2 = universe.getObjectCopy(1);
    cout << "Number of objects after copy is: " << universe.getNumberOfObjects() << "\n";
    Coordinate newPosition =  Coordinate(150, 150.23, 23.150);
    tmp2.setPosition(newPosition);
    universe.printAll();
    universe.setObject(2, tmp2);
    cout << "Coping object in position 1 to position 2\n";
    universe.printAll();
    universe.removeObject(0);
    universe.removeObject(1);
    universe.printAll();
    return true;
    //test passed on ? (11/24/2019)
}


bool test2(){
    char names[4][20]= {"Pluto", "Venus", "Mars","Jupiter"};

    //create a simulationEnvironment;
    //set it up
    Universe universe =  Universe();
    //add the newly created universe to the simulation environment
    //calculate energy before and after the addition of every object
    for(int i=0;i < 4;i++){

        Coordinate position = Coordinate(i*1.23+i*i, i*24/1.8, (i*100)/45);
        Coordinate speed    = Coordinate(i*1.23+i*i, i*24/1.8, (i*100)/45);
        Object obj = Object(names[i], position, speed, i*i*100, i*i*10);
        universe.addObject(obj);


        cout << "Object added name: " << obj.getObjectName() << endl;
        cout << "newly added object kinetic energy: " << obj.calculateKineticEnergy() <<endl;
        cout << "newly added object grav potential energy " << universe.calculateObjectGravitationalEnergy(universe.getNumberOfObjects()-1) <<endl;
        cout << "total system energy: " <<universe.calculateTotalSystemEnergy() <<endl;
    }
    return true;
    //test passed on ? (11/24/2019)

}

bool test3(){
    //test saving and loading functionalities of the program

    Universe universe =  Universe(); //create a universe
    char names[4][20]= {"Pluto", "Venus", "Mars","Jupiter"};
    for(int i=0;i<4;i++){
        Coordinate position = Coordinate(i*1.23+i*i, i*24/1.8, (i*100)/45);
        Coordinate speed    = Coordinate(i*1.23+i*i, i*24/1.8, (i*100)/45);
        Object obj = Object(names[i], position, speed, i*i*100, i*i*10);
        universe.addObject(obj);
    }
    cout << "Printing all the element of the universe" << endl;
    universe.printAll();

    cout << "total system energy: " << universe.calculateTotalSystemEnergy() << endl;

    cout << "saving this universe with name \"test3save\" " << endl;
    universe.saveSimulation("test3save");

    universe = Universe();
    universe.loadSimulation("test3save");
    cout << "Printing all the element of the second universe" << endl;
    universe.printAll();
    cout << "total system energy: " << universe.calculateTotalSystemEnergy() << endl;
    if(universe.getNumberOfObjects() !=  4){return false;}
    
    return true;

    //test passed on 11/24/2019
}
