#include <iostream>
using namespace std;
template <typename T>
inline T SQUARE(T x) {
    return x * x;
}

int main(void) {
    cout<<SQUARE(5.5)<<endl;
    cout<<SQUARE(12)<<endl;

    return 0;
}