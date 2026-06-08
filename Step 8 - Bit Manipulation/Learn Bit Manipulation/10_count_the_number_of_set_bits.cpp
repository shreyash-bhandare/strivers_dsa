#include<bits/stdc++.h>
using namespace std;

int countSetBits(int n){
    int cnt = 0;
    while(n != 0){
        cnt += n&1;
        n = n>>1;
    }
    // while(n != 0){
    //     if(n % 2 == 1) cnt++;
    //     n /= 2;
    // }
    // another method:
    // while(n != 0){
    //     n = n & n-1;
    //     cnt++;
    // }
    return cnt;
}

int main(){
    int num1 = 13;
    cout << "The number is: " << num1 << endl;
    cout << "The count of set bits is: " << countSetBits(num1) << endl;

    int num2 = 16;
    cout << "The number is: " << num2 << endl;
    cout << "The count of set bits is: " << countSetBits(num2) << endl;

    int num3 = 31;
    cout << "The number is: " << num3 << endl;
    cout << "The count of set bits is: " << countSetBits(num3) << endl;
    return 0;
}