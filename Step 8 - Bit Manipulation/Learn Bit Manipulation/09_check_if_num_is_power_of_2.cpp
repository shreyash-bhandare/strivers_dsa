#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
    if(n <= 0) return false;
    if((n & n-1) == 0) return true;
    return false;
}

int main(){
    int num1 = 16;
    cout << "The number is: " << num1 << endl;
    cout << "Is it a power of two? " << isPowerOfTwo(num1) << endl;

    int num2 = 18;
    cout << "The number is: " << num2 << endl;
    cout << "Is it a power of two? " << isPowerOfTwo(num2) << endl;

    int num3 = 1;
    cout << "The number is: " << num3 << endl;
    cout << "Is it a power of two? " << isPowerOfTwo(num3) << endl;
    return 0;
}