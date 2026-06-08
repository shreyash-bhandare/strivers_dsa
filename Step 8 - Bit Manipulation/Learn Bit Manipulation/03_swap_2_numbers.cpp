#include<bits/stdc++.h>
using namespace std;

void swapUsingXor(int &a, int &b){
    a = a^b;
    b = a^b;
    a = a^b;
}

int main(){
    int a1 = 5, b1 = 10;
    cout << "Before swapping: a = " << a1 << ", b = " << b1 << endl;
    swapUsingXor(a1, b1);
    cout << "After swapping: a = " << a1 << ", b = " << b1 << endl;

    int a2 = 25, b2 = 40;
    cout << "Before swapping: a = " << a2 << ", b = " << b2 << endl;
    swapUsingXor(a2, b2);
    cout << "After swapping: a = " << a2 << ", b = " << b2 << endl;

    int a3 = 100, b3 = 200;
    cout << "Before swapping: a = " << a3 << ", b = " << b3 << endl;
    swapUsingXor(a3, b3);
    cout << "After swapping: a = " << a3 << ", b = " << b3 << endl;
    return 0;
}