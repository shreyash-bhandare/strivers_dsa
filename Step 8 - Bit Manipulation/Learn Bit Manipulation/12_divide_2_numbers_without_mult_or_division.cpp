// Given two integers dividend and divisor, divide two integers without using multiplication, division, and 
// mod operator.

// The integer division should truncate toward zero, which means losing its fractional part. 
// For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

// Return the quotient after dividing dividend by divisor.

// Note: Assume we are dealing with an environment that could only store integers within the 
// 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, 
// then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

// Example 1:
// Input: dividend = 10, divisor = 3
// Output: 3
// Explanation: 10/3 = 3.33333.. which is truncated to 3.

// Example 2:
// Input: dividend = 7, divisor = -3
// Output: -2
// Explanation: 7/-3 = -2.33333.. which is truncated to -2.

#include<bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
    // Base case
    if(dividend == divisor) return 1;
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;
    if(divisor == 1) return dividend;
    
    // Variable to store the sign of result
    bool isPositive = true;
    
    // Updating the sign of quotient
    if(dividend >= 0 && divisor < 0) isPositive = false;
    else if(dividend < 0 && divisor > 0) isPositive = false;
        
    // Storing absolute dividend & divisor
    long long n = dividend;
    long long d = divisor;

    n = abs(n);
    d = abs(d);
    
    // Variable to store the answer and sum
    long long ans = 0, sum = 0;
    
    /* Looping while sum added to divisor is
    less than or equal to divisor */
    while(sum + d <= n) {
        
        // Increment the count
        ans++;
        // Update the sum
        sum += d;
    }
    
    // Handling overflowing condition
    if(ans > INT_MAX && isPositive) 
        return INT_MAX;
    if(ans > INT_MAX && !isPositive)
        return INT_MIN;
    
    // Returning the quotient with proper sign 
    return isPositive ? ans : -1*ans;
}

int main(){
    int dividend1 = 10, divisor1 = 3;
    cout << "The dividend is: " << dividend1 << " and the divisor is: " << divisor1 << endl;
    cout << "The quotient is: " << divide(dividend1, divisor1) << endl;

    int dividend2 = 7, divisor2 = -3;
    cout << "The dividend is: " << dividend2 << " and the divisor is: " << divisor2 << endl;
    cout << "The quotient is: " << divide(dividend2, divisor2) << endl;

    int dividend3 = INT_MIN, divisor3 = -1;
    cout << "The dividend is: " << dividend3 << " and the divisor is: " << divisor3 << endl;
    cout << "The quotient is: " << divide(dividend3, divisor3) << endl;
    return 0;
}