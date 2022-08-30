#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    char name[50];
    int age;
public:
    Person(int myage, char* myname) : age(myage)
    {
        strcpy(name, myname);
    }
    void WhatYourName() const
    {
        cout<<"My name is "<<name<<"\n";
    }
    void HowOldAreYou() const
    {
        cout<<"I'm "<<age<<" years old\n";
    }
};

class UnivStudent : public Person
{
    char major[50];
public:
    UnivStudent(int myage, char* myname, char* mymajor) : Person(myage, myname)
    {
        strcpy(major, mymajor);
    }
    void WhoAreYou() const
    {
        WhatYourName();
        HowOldAreYou();
        cout<<"My major is "<<major<<"\n\n";
    }
};

int main(void)
{
    UnivStudent ustd1(22, (char*)"Lee", (char*) "Computer eng.");
    UnivStudent ustd2(21, (char*)"Yoon",(char*) "Electronic emg.");

    ustd1.WhoAreYou();
    ustd2.WhoAreYou();

    return 0;
}