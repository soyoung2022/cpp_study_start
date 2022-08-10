#include <cstring>
#include "CarInline.h"
using namespace std;

void Car::InitMembers(char * ID, int fuel)
{
    strcpy(gamerID, ID);
    fuelGauge=fuel;
    carSpeed=0;
}

void Car::Accel() 
{
    if(fuelGauge<=0)
    {
        return;
    }else{
        fuelGauge -= CAR_CONST::FUEL_STEP;
    }
    if((carSpeed+CAR_CONST::ACC_STEP)>=CAR_CONST::MAX_SPD){
        carSpeed=CAR_CONST::MAX_SPD;
        return;
    }
    carSpeed += CAR_CONST::ACC_STEP;
}