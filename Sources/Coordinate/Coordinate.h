#include "../Interfaces/Dynamical/Dynamical.h"


class Coordinate {
    public:
        long double x;
        long double y;
        long double z;
        Coordinate(long double x, long double y, long double z);
        Coordinate();
        ~Coordinate();
        void setCoordinate(long double x, long double y, long double z);
        void sumCoordinate(long double x, long double y, long double z);
};