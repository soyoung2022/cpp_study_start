#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
    int bullet; // 장전된 총알의 수 
public:
    Gun(int bnum) : bullet(bnum)
    { }
    void Shot()
    {
        cout<<"BBANG!\n";
        bullet--;
    }
protected:
    int getBullet()
    {
       return bullet; 
    }
};

class Police : public Gun
{
    int handcuffs; // 소유한 수갑의 수
public:
    Police(int bnum, int bcuff) : Gun(bnum), handcuffs(bcuff)
    {}
    void PutHandCuff()
    {
        cout<<"SNAP!\n";
        handcuffs--;
    }
    void getBandH()
    {
        cout<<getBullet()<<", ";
        cout<<handcuffs<<"\n";
    }
};

int main(void)
{
    Police pman(5, 3);
    pman.Shot();
    pman.PutHandCuff();
    pman.getBandH();

    return 0;
}