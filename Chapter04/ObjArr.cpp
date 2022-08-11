#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    char * name;
    int age;
public:
    Person(char * myname, int myage)
    {
        int len = strlen(myname)+1;
        name = new char(len);
        strcpy(name, myname);
        age = myage;
    }
    Person()
    {
        name = NULL;
        age=0;
        cout<<"called Person()\n";
    }
    void setPersonInfo(char * myname, int myage) {
        name=myname;
        age=myage;
    }
    void ShowPersonInfo() 
    {
        cout<<"이름: "<<name<<endl;
        cout<<"나이: "<<age<<endl;
    }
    ~Person()
    {
        delete []name;
        cout<<"called destructor!\n";
    }
};

int main(void) 
{
    Person parr[3];
    char namestr[100];
    char * strptr;
    int age;
    int len;

    for(int i = 0; i < 3; i++) {
        cout<<"이름: ";
        cin>>namestr;
        cout<<"나이: ";
        cin>>age;
        len=strlen(namestr)+1;
        strptr = new char[len];
        strcpy(strptr, namestr);
        parr[i].setPersonInfo(strptr, age);
    }
   parr[0].ShowPersonInfo();
   parr[1].ShowPersonInfo();
   parr[2].ShowPersonInfo();

    return 0;
}