#include <iostream>
using namespace std;

namespace CAR_CONST
{
  enum
  {
    ID_LEN = 20,
    MAX_SPEED = 200,
    FUEL_STEP = 2,
    ACC_STEP = 10,
    BREAK_STEP = 10
  };
} 


struct Car{
    char gameID[CAR_CONST::ID_LEN];
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
            fuelGauge -= CAR_CONST::FUEL_STEP;
        }
        if(carSpeed + CAR_CONST::ACC_STEP > CAR_CONST::MAX_SPEED) {
            carSpeed = CAR_CONST::MAX_SPEED;
            return;
        }
        carSpeed += CAR_CONST::ACC_STEP;
    }

    void Break() {
        if(carSpeed < CAR_CONST::BREAK_STEP) {
            carSpeed = 0;
            return;
        }
        carSpeed -= CAR_CONST::BREAK_STEP;
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