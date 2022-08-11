#include <iostream>
using namespace std;

class Point
{
    int xpos;
    int ypos;
public:
    Point(int x, int y):xpos(x), ypos(y) { }
    void ShowPointInfo() const {
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
};

class Circle
{
    Point p;
    int radius;
public:
    Circle(int x, int y, int r) : p(x, y), radius(r) { }
    void ShowCircleInfo() const {
        cout<<"radius: "<<radius<<endl;
        p.ShowPointInfo();
    }
};

class Ring{
    Circle ic;
    Circle oc;
public:
    Ring(int x1, int y1, int r1, int x2, int y2, int r2): ic(x1, y1, r1), oc(x2, y2, r2)
    {

    }
    void ShowRingInfo() {
        cout<<"Inner Circle Info...\n";
        ic.ShowCircleInfo();
        cout<<"Outer Circle Info...\n";
        oc.ShowCircleInfo();
    }
};

int main(void) {
    Ring ring(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();

    return 0;
}