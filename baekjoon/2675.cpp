/*
백준 - 2675번
시도 - 2회
*/
#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    int count;
    cin>>count;
    for(int i = 0; i < count; i++)
    {
        int r;
        cin>>r;
        char string[21];
        cin>>string;
        for(int j = 0; j < strlen(string); j++)
        {
            for(int k = 0; k < r; k++)
            {
                cout<<string[j];
            }
        }
        cout<<"\n";
    }
    return 0;
}