/*
백준 10951번
시도 - 6번
*/
#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int d1, d2, d3;
    cin>>d1>>d2>>d3;
    if((d1 == d2) && (d2 == d3))
    {
        cout<<10000+1000*d1;
    }else if((d1 != d2) && (d2 != d3) && (d1 != d3))
    {
        cout<<max(d1, max(d2, d3))*100;
    }else if(d1 == d2 || d1 == d3)
    {
        cout<<1000+100*d1;
    }else
    {
        cout<<1000+100*d2;
    }

    return 0;
}