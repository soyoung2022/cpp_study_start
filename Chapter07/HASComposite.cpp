#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
    int bullet;
public:
    Gun(int bnum) : bullet(bnum)
    { }
    void Shot()
    {
        cout<<"BANG!\n";
        bullet--;
    }
};

class Police
{
    int handcuffs;
    Gun * pistol;
public:
    Police(int bnum, int bcuff) : handcuffs(bcuff)
    {
        if(bnum > 0)
        {
            pistol = new Gun(bnum);
        }
        else
        {
            pistol = NULL;
        }
    }
    void Puthandcuff()
    {
        cout<<"SNAP!\n";
        handcuffs--;
    }
    void Shot()
    {
        if(pistol == NULL)
        {
            cout<<"Hut BBANG!\n";
        }
        else
        {
            pistol->Shot();
        }
    }
    ~Police()
    {
        if(pistol != NULL)
        {
            delete pistol;
        }
    }
};

int main(void)
{
    Police policeman1(5, 3);
    Police policeman2(0, 3);
    policeman1.Shot();
    policeman1.Puthandcuff();
    policeman2.Shot();
    policeman2.Puthandcuff();
    
    return 0;
}
