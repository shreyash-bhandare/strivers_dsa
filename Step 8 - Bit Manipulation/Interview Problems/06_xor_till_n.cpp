#include<bits/stdc++.h>
using namespace std;

int xorUptoN(int n){
    if(n%4 == 1) return 1;
    else if(n%4 == 2) return n+1;
    else if(n%4 == 3) return 0;
    return n;
}

int main(){
    int num1 = 4;
    cout << "The number is: " << num1 << endl;
    cout << "The XOR from 1 to " << num1 << " is: " << xorUptoN(num1) << endl;

    int num2 = 7;
    cout << "The number is: " << num2 << endl;
    cout << "The XOR from 1 to " << num2 << " is: " << xorUptoN(num2) << endl;

    int num3 = 10;
    cout << "The number is: " << num3 << endl;
    cout << "The XOR from 1 to " << num3 << " is: " << xorUptoN(num3) << endl;
    return 0;
}