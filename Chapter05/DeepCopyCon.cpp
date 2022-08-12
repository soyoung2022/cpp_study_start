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
        int len=strlen(myname)+1;
        name = new char[len];
        strcpy(name, myname);
        age=myage;
    }
    Person(const Person &copy):age(copy.age)
    {
        name = new char[strlen(copy.name)+1]; // 메모리 공간 별도 할당 
        strcpy(name, copy.name);
    }
    void ShowPersonInfo() const {
        cout<<"이름: "<<name<<endl;
        cout<<"나이: "<<age<<endl;
    }
    ~Person() {
        delete []name; // 여기서 실행 에러 발생하는 듯!
        cout<<"called destructor!"<<endl;
    }
};

int main(void)
{
    Person man1((char *)"Lee dong woo", 29);
    Person man2 = man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}