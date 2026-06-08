#include<bits/stdc++.h>
using namespace std;

bool isOdd(int n) {
    if((n&1) == 1) return true;
    return false;
}

int main(){
    int num1 = 13;
    cout << "The number is: " << num1 << endl;
    cout << "Is the number odd? " << isOdd(num1) << endl;

    int num2 = 20;
    cout << "The number is: " << num2 << endl;
    cout << "Is the number odd? " << isOdd(num2) << endl;

    int num3 = 1;
    cout << "The number is: " << num3 << endl;
    cout << "Is the number odd? " << isOdd(num3) << endl;
    return 0;
}