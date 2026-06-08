// Given two integers n and i, return true if the ith bit in the binary representation of n 
// (counting from the least significant bit, 0-indexed) is set (i.e., equal to 1). Otherwise, return false.

// Example 1
// Input: n = 5, i = 0
// Output: true
// Explanation: Binary representation of 5 is 101. The 0-th bit from LSB is set (1).

// Example 2
// Input: n = 10, i = 1
// Output: true
// Explanation: Binary representation of 10 is 1010. The 1-st bit from LSB is set (1).

#include<bits/stdc++.h>
using namespace std;

bool checkIthBit(int n, int i) {
    // using left shift
    if((n & (1<<i)) != 0){
        return true;
    }
    return false;
    // using right shift
    // if((n>>1)&1 == 1) return true;
    // return false;
}

int main(){
    int num1 = 13, i1 = 2;
    cout << "The number is: " << num1 << " and the bit position is: " << i1 << endl;
    cout << "The bit is: " << checkIthBit(num1, i1) << endl;

    // Test Case 2
    int num2 = 13, i2 = 1;
    cout << "The number is: " << num2 << " and the bit position is: " << i2 << endl;
    cout << "The bit is: " << checkIthBit(num2, i2) << endl;

    // Test Case 3
    int num3 = 32, i3 = 5;
    cout << "The number is: " << num3 << " and the bit position is: " << i3 << endl;
    cout << "The bit is: " << checkIthBit(num3, i3) << endl;
    return 0;
}