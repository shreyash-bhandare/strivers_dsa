// Given a positive integer n. Find and return its square root. If n is not a perfect square, 
// then return the floor value of sqrt(n).

// Example 1
// Input: n = 36
// Output: 6
// Explanation: 6 is the square root of 36.

// Example 2
// Input: n = 28
// Output: 5
// Explanation: The square root of 28 is approximately 5.292. So, the floor value will be 5.

#include<bits/stdc++.h>
using namespace std;

int floorSqrt(int n)  {
    int low = 1, high = n;
    while(low <= high){
        long long mid = low + (high - low)/2;
        if((long)mid*mid <= n){
            low = mid+1;
        }
        else high = mid-1;
    }
    return high;
}

int main(){
    int n = 35;
    int square_root = floorSqrt(n);
    cout<<"The Floor Square Root of "<<n<<" is "<<square_root<<endl;
    return 0;
}