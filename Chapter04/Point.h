#ifndef __POINT_H_
#define __POINT_H_

class Point
{
    // private --> 정보 은닉 
    int x;
    int y;
public:
    Point(const int &xpos, const int &ypos);
    // bool InitMember(int xpos, int ypos);
    int GetX() const;
    int GetY() const;
    bool SetX(int xpos);
    bool SetY(int ypos);
};

#endif