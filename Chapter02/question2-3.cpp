#include <iostream>
using namespace std;

typedef struct __Point
{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2);

int main(void) {
    Point * p1 = new Point;
    Point * p2 = new Point;
    p1->xpos = 3;
    p1->ypos = 3;
    p2->xpos = 10;
    p2->ypos = 5;
    Point &ref = PntAdder(*p1, *p2);

    cout<<ref.xpos<<endl;
    cout<<ref.ypos<<endl;

    return 0;
}

Point& PntAdder(const Point &p1, const Point &p2){
    Point * ptr = new Point;
    ptr->xpos = p1.xpos + p2.xpos;
    ptr->ypos = p1.ypos + p2.ypos;
    return *ptr;
}