#include <iostream>
using namespace std;

#define ID_LEN 20
#define MAX_SPEED 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BREAK_STEP 10

struct Car
{
    char gameID[ID_LEN];
    int fuelGauge;
    int carSpeed;

    void showCarState() {
        cout<<"소유주 ID : "<<gameID<<endl;
        cout<<"연료량 : "<<fuelGauge<<"%"<<endl;
        cout<<"현재속도 : "<<carSpeed<<"km/s"<<endl<<endl;
    }

    void Accel()
    {
        if(fuelGauge<=0){
            return;
        }else{
            fuelGauge -= FUEL_STEP;
        }
        if(carSpeed + ACC_STEP > MAX_SPEED) {
            carSpeed = MAX_SPEED;
            return;
        }
        carSpeed += ACC_STEP;
    }

    void Break() {
        if(carSpeed < BREAK_STEP) {
            carSpeed = 0;
            return;
        }
        carSpeed -= BREAK_STEP;
    }
};

int main(void) {
    Car run99={"run99", 100, 0};
    run99.Accel();
    run99.Accel();
    run99.showCarState();
    run99.Break();
    run99.showCarState();

    Car sped77={"sped77", 100, 0};
    sped77.Accel();
    sped77.Break();
    sped77.showCarState();

    return 0;
}