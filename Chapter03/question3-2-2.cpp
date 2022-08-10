#include <iostream>
#include <cstring>
using namespace std;

class Printer
{
private:
    char string[100];
public:
    void SetString(char *str);
    void ShowString(void);
};

int main(void) {
    Printer pnt;
    pnt.SetString((char *)"Hello world!");
    pnt.ShowString();

    pnt.SetString((char *)"I love C++");
    pnt.ShowString();

    return 0;
}

inline void Printer::SetString(char *str){
    strcpy(string, str);
}

inline void Printer::ShowString() {
    cout<<string<<endl;
}
