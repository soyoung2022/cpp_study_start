#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
    char * name;
    int age;
public:
    MyFriendInfo(char * fname, int fage) : age(fage)
    {
        name = new char[strlen(fname)+1];
        strcpy(name, fname);
    }
    void ShowMyFriendInfo()
    {
        cout<<"이름: "<<name<<"\n";
        cout<<"나이: "<<age<<"\n";
    }
    ~MyFriendInfo()
    {
        delete []name;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
    char * addr;
    char * phone;
public:
    MyFriendDetailInfo(char * fname, int fage, char * faddr, char * fphone) : MyFriendInfo(fname, fage)
    {
        addr = new char[strlen(faddr)+1];
        strcpy(addr, faddr);
        phone = new char[strlen(fphone)+1];
        strcpy(phone, fphone);
    }
    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout<<"주소: "<<addr<<"\n";
        cout<<"전화번호: "<<phone<<"\n";
    }
    ~MyFriendDetailInfo()
    {
        delete []addr;
        delete []phone;
    }
};

int main(void)
{
    MyFriendDetailInfo fren1((char*) "김진성", 22, (char*) "충남 아산", (char*) "010-1234-5678");
    MyFriendDetailInfo fren2((char*) "이주성", 19, (char*) "경기 인천", (char*) "010-3333-4444");
    fren1.ShowMyFriendDetailInfo();
    fren2.ShowMyFriendDetailInfo();
    return 0;
}