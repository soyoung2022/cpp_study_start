#include <iostream>
using namespace std;

class Calculator
{
private:
    int cnt_add;
    int cnt_sub;
    int cnt_mul;
    int cnt_div;
public:
    void Init();
    void ShowOpCount();
    double Add(double a, double b);
    double Div(double a, double b);
    double Min(double a, double b);
    double Mul(double a, double b);
};

int main(void) {
    Calculator cal;
    cal.Init();
    cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<endl;
    cout<<"3.5 / 1.7= "<<cal.Div(3.5, 1.7)<<endl;
    cout<<"2.2 - 1.5 = "<<cal.Min(2.2, 1.5)<<endl;
    cout<<"4.9 / 1.2 = "<<cal.Div(4.9, 1.2)<<endl;
    cal.ShowOpCount();
    cout<<endl;

    return 0;
}

inline void Calculator::Init(){
    cnt_add = 0;
    cnt_sub = 0;
    cnt_mul = 0;
    cnt_div = 0;
}

inline void Calculator::ShowOpCount() {
    cout<<"덧셈 : "<<cnt_add<<" 뺄셈 : "<<cnt_sub<<" 곱셈 : "<<cnt_mul<<" 나눗셈 : "<<cnt_div<<endl;
}

inline double Calculator::Add(double a, double b) {
    cnt_add++;
    return (a+b);
}
inline double Calculator::Min(double a, double b) {
    cnt_sub++;
    return (a-b);
}
inline double Calculator::Div(double a, double b) {
    cnt_div++;
    return (a/b);
}
inline double Calculator::Mul(double a, double b) {
    cnt_mul++;
    return (a*b);
}