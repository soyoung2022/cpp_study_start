#include <iostream>
using namespace std;

void swap(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void swap(double *d1, double *d2) {
    double temp = *d1;
    *d1 = *d2;
    *d2 = temp;
}

int main(void) {
    int num1=30, num2=20;
    swap(&num1, &num2);
    cout<<num1<<' '<<num2<<endl;

    char ch1='A', ch2='Z';
    swap(&ch1, &ch2);
    cout<<ch1<<' '<<ch2<<endl;

    double dbl1=1.111, dbl2=5.555;
    swap(&dbl1, &dbl2);
    cout<<dbl1<<' '<<dbl2<<endl;
    return 0;
}