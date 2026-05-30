#include<bits/stdc++.h>
using namespace std;

int missing_num(int nums[], int n){
    int xor1 = 0;
    int xor2 = 0;

    for(int i = 0; i < n-1; i++){
        xor1 = xor1 ^ (i+1);        // calculating xor for n-1 numbers.
        xor2 = xor2 ^ nums[i];      // calculating xor for array.
    }
    xor1 = xor1 ^ n;

    return xor1 ^ xor2;
}

int main(){
    int arr[4] = {1, 5, 2, 3};
    int n = 5;
    cout<<missing_num(arr, n);
    return 0;
}