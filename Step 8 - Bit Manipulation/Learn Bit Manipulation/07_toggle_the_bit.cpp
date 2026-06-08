#include<bits/stdc++.h>
using namespace std;

int toggleIthBit(int x, int i){
    return x ^ (1<<i);
}

int main(){
    int num1 = 10, i1 = 1;
    cout << "The number is: " << num1 << " and the bit position is: " << i1 << endl;
    cout << "The number after toggling the bit is: " << toggleIthBit(num1, i1) << endl;

    // Test Case 2
    int num2 = 13, i2 = 2;
    cout << "The number is: " << num2 << " and the bit position is: " << i2 << endl;
    cout << "The number after toggling the bit is: " << toggleIthBit(num2, i2) << endl;

    // Test Case 3
    int num3 = 32, i3 = 5;
    cout << "The number is: " << num3 << " and the bit position is: " << i3 << endl;
    cout << "The number after toggling the bit is: " << toggleIthBit(num3, i3) << endl;
    return 0;
}