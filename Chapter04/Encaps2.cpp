#include <iostream>
using namespace std;

class SnivelCap
{
public:
    void Take() const{
        cout<<"콧물이 싹~ 납니다."<<endl;
        }
};

class SneezeCap
{
public:
    void Take() const
    {
        cout<<"재채기가 멎습니다.\n";
    }
};

class SnuffleCap
{
public:
    void Take() const
    {
        cout<<"코가 뻥 뚫립니다.\n";
    }
};

class CONTAC600 // Encapsulation
{
    SnivelCap sin;
    SneezeCap sne;
    SnuffleCap snu;
public:
    void Take() const{
        sin.Take();
        sne.Take();
        snu.Take();
    }
};

class ColdPatient
{
public:
    void TakeCONTAC600(const CONTAC600 & cap) {
        cap.Take();
    }
};

int main(void) {
    CONTAC600 cap;
    ColdPatient patient;
    patient.TakeCONTAC600(cap);

    return 0;
}