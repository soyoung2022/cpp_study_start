#include <iostream>
#include <cstring>
#include "Car.h"
using namespace std;

void Car::InitMembers(char * ID, int fuel) {
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    carSpeed = 0;
}

void Car::ShowCarState()
{
    cout<<"소유주 ID : "<<gamerID<<endl;
    cout<<"연료량 : "<<fuelGauge<<"%"<<endl;
    cout<<"현재속도 : "<<carSpeed<<"km/s"<<endl<<endl;
}

void Car::Accel() 
{
    if(fuelGauge <=0)
    {
        return;
    }else{
        fuelGauge -= FUEL_STEP;
    }
    if((carSpeed + ACC_STEP) > MAX_SPD)
    {
        carSpeed = MAX_SPD;
        return;
    }
    carSpeed += ACC_STEP;
}

void Car::Break()
{
    if(carSpeed < BRK_STEP){
        carSpeed = 0;
        return;
    }
    carSpeed -= BRK_STEP;
}