#include <iostream>
using namespace std;

class Girl;

class Boy
{
    int height;
    friend class Girl;
public:
    Boy(int len) : height(len) { }
    void ShowYourFriendInfo(Girl &frn);
};

class Girl
{
    char phNum[20];
public:
    Girl(char * num){
        strcpy(phNum, num);
    }
    void ShowYourFriendInfo(Boy &frn);
    friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl &frn)
{
    cout<<"Her phone number: "<<frn.phNum<<"\n";
}

void Girl::ShowYourFriendInfo(Boy &frn)
{
    cout<<"His height: "<<frn.height<<"\n";
}

int main(void)
{
    Boy boy(170);
    Girl girl((char *)"010-1234-5678");
    boy.ShowYourFriendInfo(girl);
    girl.ShowYourFriendInfo(boy);

    return 0;
}