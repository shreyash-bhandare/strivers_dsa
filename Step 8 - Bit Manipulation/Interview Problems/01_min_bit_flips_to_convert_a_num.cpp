// A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from 
// either 0 to 1 or 1 to 0.

// For example, for x = 7, the binary representation is 111 and we may choose any bit 
// (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, 
// flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
// Given two integers start and goal, return the minimum number of bit flips to convert start to goal.

// Example 1:
// Input: start = 10, goal = 7
// Output: 3
// Explanation: The binary representation of 10 and 7 are 1010 and 0111 respectively. We can convert 10 to 7 in 3 steps:
// - Flip the first bit from the right: 1010 -> 1011.
// - Flip the third bit from the right: 1011 -> 1111.
// - Flip the fourth bit from the right: 1111 -> 0111.
// It can be shown we cannot convert 10 to 7 in less than 3 steps. Hence, we return 3.

// Example 2:
// Input: start = 3, goal = 4
// Output: 3
// Explanation: The binary representation of 3 and 4 are 011 and 100 respectively. We can convert 3 to 4 in 3 steps:
// - Flip the first bit from the right: 011 -> 010.
// - Flip the second bit from the right: 010 -> 000.
// - Flip the third bit from the right: 000 -> 100.
// It can be shown we cannot convert 3 to 4 in less than 3 steps. Hence, we return 3.

#include<bits/stdc++.h>
using namespace std;

int countSetBits(int n){
    int cnt = 0;
    while(n != 0){
        cnt += n&1;     // checking if the last bit is set. (if last bit is set = odd number)
        n = n>>1;       // dividing by 2
    }
    return cnt;
}

int minBitFlips(int start, int goal) {
    int n = start ^ goal;
    return countSetBits(n);
}

int main(){
    int start1 = 10, goal1 = 7;
    cout << "The start number is: " << start1 << " and the goal number is: " << goal1 << endl;
    cout << "The minimum bit flips required are: " << minBitFlips(start1, goal1) << endl;

    int start2 = 3, goal2 = 4;
    cout << "The start number is: " << start2 << " and the goal number is: " << goal2 << endl;
    cout << "The minimum bit flips required are: " << minBitFlips(start2, goal2) << endl;

    int start3 = 15, goal3 = 15;
    cout << "The start number is: " << start3 << " and the goal number is: " << goal3 << endl;
    cout << "The minimum bit flips required are: " << minBitFlips(start3, goal3) << endl;
    return 0;
}