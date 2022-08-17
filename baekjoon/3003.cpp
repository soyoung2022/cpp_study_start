/*
백준 - 3003번
시도 - 1회
*/
#include <iostream>
using namespace std;

int main(void)
{
    int total[] = {1, 1, 2, 2, 2, 8};
    for(int i = 0; i < 6; i++)
    {
        int white;
        cin>>white;
        cout<<total[i]-white<<" "; 
    }
    cout<<"\n";
    return 0;
}