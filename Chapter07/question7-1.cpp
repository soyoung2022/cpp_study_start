#include <iostream>
using namespace std;

class Car
{
    int gasolineGauge;
public:
    Car(int gas) : gasolineGauge(gas)
    {
        cout<<"Car(int gas) : "<<gasolineGauge<<"\n";
    }
    int GetGasGauge()
    {
        return gasolineGauge;
    }
};

class HybridCar : public Car
{
    int electricGauge;
public:
    HybridCar(int gas, int electric) : electricGauge(electric), Car(gas)
    {
        cout<<"HybridCar(int gas, int electric) : "<<electricGauge<<"\n";
    }
    int GetElecGauge()
    {
        return electricGauge;
    }
};

class HybridWaterCar : public HybridCar
{
    int waterGauge;
public:
    HybridWaterCar(int gas, int electric, int water) : HybridCar(gas, electric), waterGauge(water)
    {
        cout<<"HybridWaterCar(int gas, int electric, int water) : "<<waterGauge<<"\n";
    }
    void ShowCurrentGauge()
    {
        cout<<"잔여 가솔린: "<<GetGasGauge()<<"\n";
        cout<<"잔여 전기량: "<<GetElecGauge()<<"\n";
        cout<<"잔여 워터량: "<<waterGauge<<"\n";
    }
};

int main(void)
{
    HybridWaterCar hybridWaterCar(2, 3, 7);
    hybridWaterCar.ShowCurrentGauge();

    return 0;
}