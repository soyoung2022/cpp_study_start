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
    Person man1((char *)"Lee dong woo", 29);
    Person man2((char *)"Jang dong gun", 41);
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}