#include <iostream>
using namespace std;

class Rectangle
{
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h)
    {}
    void ShowAreaInfo()
    {
        cout<<"면적: "<<width*height<<"\n";
    }
};

class Square : public Rectangle
{
public:
    Square(int length) : Rectangle(length, length)
    {}
};

int main(void)
{
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();

    return 0;
}