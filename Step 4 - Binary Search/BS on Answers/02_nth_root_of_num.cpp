// Given two numbers N and M, find the Nth root of M. 
// The Nth root of a number M is defined as a number X such that when X is raised to the power of N, it equals M. 
// If the Nth root is not an integer, return -1.

// Example 1
// Input: N = 3, M = 27
// Output: 3
// Explanation: The cube root of 27 is equal to 3.

// Example 2
// Input: N = 4, M = 69
// Output:-1
// Explanation: The 4th root of 69 does not exist. So, the answer is -1.

#include<bits/stdc++.h>
using namespace std;

//write function:
// return 1 if == m
// return 0 if < m
// return 2 if > m
int power(int mid, int n, int m){
    long long ans = 1; 
    for(int i = 1; i <= n; i++){
        ans *= mid;
        if(ans > m) return 2;
    }
    if(ans == m) return 1;
    return 0;
}

// causes overflow
// int power(int mid, int n){
//     int ans = 1;
//     while(n>0){
//         if(n%2 == 0){
//             mid = mid*mid;
//             n = n/2;
//         }
//         else{
//             ans = ans * mid;
//             n--;
//         }
//     }
//     return ans;
// }

int NthRoot(int N, int M) {
    int low = 1, high = M;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(power(mid, N, M) == 1) return mid;
        else if(power(mid, N, M) == 2) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int main(){
    int n1 = 3;
    int m1 = 27;
    int nth_root_1 = NthRoot(n1, m1);
    cout<<"The "<<n1<<"th Root of "<<m1<<" is "<<nth_root_1<<endl;
    int n2 = 4;
    int m2 = 69;
    int nth_root_2 = NthRoot(n2, m2);
    cout<<"The "<<n2<<"th Root of "<<m2<<" is "<<nth_root_2<<endl;
    return 0;
}