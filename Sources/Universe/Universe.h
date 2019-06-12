
//#include "../Interfaces/Dynamical/Dynamical.h"
#include "../Object/Object.h"
#include <vector>

class Universe{
    private:
        std::vector <Object> objects; // std::vector<Object> contains all the universe objects
        void resizeObjects();
        bool ObjectsIsFull();
    public:
        //Initializers
        Universe();
        ~Universe();
        //Getters
        int getNumberOfObjects();
        Object getObjectCopy(int position);
        //Setters
        void setObject(int position, Object newObject);
        //Vector handling
        void addObject(Object newObject);
        void removeObject(int position);

        //Simulation related
        long double calculateDistance(int index1, int index2);
        long double calculateObjectGravitationalEnergy(int position);
        long double calculateTotalObjectEnergy(int position);
        long double calculateTotalSystemEnergy();

        //for testing
        void printAll();
        void print(int i);
};