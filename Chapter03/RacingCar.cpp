#include <iostream>
using namespace std;

#define ID_LEN 20
#define MAX_SPEED 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BREAK_STEP 10

struct Car {
    char gameID[ID_LEN]; // 소유자 ID
    int fuelGauge; // 연료량 
    int carSpeed; // 현재속도
};

void showCarState(const Car &car) {
    cout<<"소유자 ID : "<<car.gameID<<endl;
    cout<<"연료량 : "<<car.fuelGauge<<"%"<<endl;
    cout<<"현재속도 : "<<car.carSpeed<<"km/s"<<endl<<endl;
}

void Accel(Car &car)
{
    if(car.fuelGauge<=0){
        return;
    }else{
        car.fuelGauge -= FUEL_STEP;
    }
    if(car.carSpeed + ACC_STEP > MAX_SPEED) {
        car.carSpeed = MAX_SPEED;
        return;
    }
    car.carSpeed += ACC_STEP;
}

void Break(Car &car) {
    if(car.carSpeed < BREAK_STEP) {
        car.carSpeed = 0;
        return;
    }
    car.carSpeed -= BREAK_STEP;
}

int main(void) {
    Car run99={"run99", 100, 0};
    Accel(run99);
    Accel(run99);
    showCarState(run99);
    Break(run99);
    showCarState(run99);

    Car sped77={"sped77", 100, 0};
    Accel(sped77);
    Break(sped77);
    showCarState(sped77);

    return 0;
}