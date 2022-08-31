#include <iostream>
using namespace std;

class First
{
    char * strOne;
public:
    First(char * str)
    {
        strOne = new char[strlen(str)+1];
    }
    ~First()
    {
        cout<<"~First()\n";
        delete []strOne;
    }
};

class Second : public First
{
    char * strTwo;
public:
    Second(char* str1, char* str2) : First(str1)
    {
        strTwo = new char[strlen(str2)+1];
    }
    ~Second()
    {
        cout<<"~Second()\n";
        delete []strTwo;
    }
};

int main(void)
{
    First * ptr = new Second((char*) "simple", (char*) "complex");
    delete ptr; 
    
    return 0;
}