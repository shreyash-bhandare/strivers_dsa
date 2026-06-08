#include<bits/stdc++.h>
using namespace std;

int setIthBit(int n, int i){
    n = n | (1<<i);
    return n;
}

int main(){
    int num1 = 10, i1 = 0;
    cout << "The number is: " << num1 << " and the bit position is: " << i1 << endl;
    cout << "The number after setting the bit is: " << setIthBit(num1, i1) << endl;

    // Test Case 2
    int num2 = 8, i2 = 1;
    cout << "The number is: " << num2 << " and the bit position is: " << i2 << endl;
    cout << "The number after setting the bit is: " << setIthBit(num2, i2) << endl;

    // Test Case 3
    int num3 = 13, i3 = 2;
    cout << "The number is: " << num3 << " and the bit position is: " << i3 << endl;
    cout << "The number after setting the bit is: " << setIthBit(num3, i3) << endl;
    return 0;
}