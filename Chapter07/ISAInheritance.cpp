#include <iostream>
#include <cstring>
using namespace std;

class Computer
{
    char owner[50];
public:
    Computer(char * name)
    {
        strcpy(owner, name);
    }
    void Calculate()
    {
        cout<<"요청 내용을 계산합니다.\n";
    }
};

class NoteBookComp : public Computer
{
    int Battery;
public:
    NoteBookComp(char * name, int initChag) : Computer(name), Battery(initChag)
    {}
    void Charging() {Battery += 5;}
    void UseBattery() {Battery -= 1;}
    void MovingCal()
    {
        if(GetBatteryInfo()<1)
        {
            cout<<"충전이 필요합니다.\n";
            return;
        }
        cout<<"이동하면서 ";
        Calculate();
        UseBattery();
    }
    int GetBatteryInfo()
    {
        return Battery;
    }
};

class TableNotebook : public NoteBookComp
{
    char regstPenModel[50];
public:
    TableNotebook(char * name, int initChag, char * pen) : NoteBookComp(name, initChag)
    {
        strcpy(regstPenModel, pen);
    }
    void Write(char * penInfo)
    {
        if(GetBatteryInfo() < 1)
        {
            cout<<"충전이 필요합니다.\n";
            return;
        }
        if(strcmp(regstPenModel, penInfo) != 0)
        {
            cout<<"등록된 펜이 아닙니다.\n";
            return;
        }
        cout<<"필기 내용을 처리합니다.\n";
        UseBattery();
    }
};

int main(void)
{
    NoteBookComp nc((char*) "이수종", 5);
    nc.MovingCal();
    TableNotebook tn((char *)"정수영", 5, (char*) "ISE-241-242");
    tn.Write((char*)"ISE-241-242");

    return 0;
}