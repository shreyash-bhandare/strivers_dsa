#include<bits/stdc++.h>
using namespace std;

int removeLastSetBit(int x){
    return x & x-1;
}

int main(){
    int num1 = 12;
    cout << "The number is: " << num1 << endl;
    cout << "The number after removing the last set bit is: " << removeLastSetBit(num1) << endl;

    // Test Case 2
    int num2 = 13;
    cout << "The number is: " << num2 << endl;
    cout << "The number after removing the last set bit is: " << removeLastSetBit(num2) << endl;

    // Test Case 3
    int num3 = 32;
    cout << "The number is: " << num3 << endl;
    cout << "The number after removing the last set bit is: " << removeLastSetBit(num3) << endl;
    return 0;
}