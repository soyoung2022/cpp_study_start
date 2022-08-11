#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2):upLeft(x1, y1), lowRight(x2, y2)
{
    // empty
}

/*
bool Rectangle::InitMembers(const Point &p1, const Point &p2){
    if(p1.GetX() > p2.GetX() || p1.GetY() < p2.GetY()){
        cout<<"잘못된 위치정보 전달"<<endl;
        return false;
    }
    upLeft = p1;
    lowRight = p2;
    return true;
}
*/

void Rectangle::ShowRecInfo() const {
    cout<<"좌 상단: ["<<upLeft.GetX()<<", "<<upLeft.GetY()<<"]"<<endl;
    cout<<"우 하단: ["<<lowRight.GetX()<<", "<<lowRight.GetY()<<"]"<<endl;
}