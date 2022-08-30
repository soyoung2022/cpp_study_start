#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    char * name;
public:
    Person(char * myname)
    {
        name = new char[strlen(myname)+1];
        strcpy(name, myname);
    }
    ~Person()
    {
        delete []name;
    }
    void WhatYourName() const
    {
        cout<<"My name is "<<name<<".\n";
    }
};

class UnivStudent : public Person
{
    char * major;
public:
    UnivStudent(char * myname, char * mymajor) : Person(myname)
    {
        major = new char[strlen(mymajor)+1];
        strcpy(major, mymajor);
    }
    ~UnivStudent() 
    {
        delete []major;
    }
    void WhoAreYou() const
    {
        WhatYourName();
        cout<<"My major is "<<major<<".\n\n";
    }
};

int main(void)
{
    UnivStudent st1((char*)"Kim", (char*) "Mathematics");
    UnivStudent st2((char*)"Hong",(char*) "Physics");
    st1.WhoAreYou();
    st2.WhoAreYou();
    return 0;
}