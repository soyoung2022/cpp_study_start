#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(const int &xpos, const int &ypos) {
    x=xpos;
    y=ypos;
}

/*
bool Point::InitMember(int xpos, int ypos){
    if(xpos < 0 || ypos < 0){
        cout<<"벗어난 범위의 값 전달"<<endl;
        return false;
    }
    x = xpos;
    y = ypos;
    return true;
}
*/

int Point::GetX() const { // const 함수
    return x;
}

int Point::GetY() const {
    return y;
}

bool Point::SetX(int xpos) {
    if(xpos < 0 || xpos > 100){
        cout<<"벗어난 범위의 값 전달"<<endl;
        return false;
    }
    x = xpos;
    return true;
}

bool Point::SetY(int ypos) {
    if(ypos < 0 || ypos > 100){
        cout<<"벗어난 범위의 값 전달"<<endl;
        return false;
    }
    y = ypos;
    return true;
}