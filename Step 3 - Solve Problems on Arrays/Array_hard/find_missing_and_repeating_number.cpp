// You have a set of integers s, which originally contains all the numbers from 1 to n. 
// Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, 
// which results in repetition of one number and loss of another number.

// You are given an integer array nums representing the data status of this set after the error.

// Find the number that occurs twice and the number that is missing and return them in the form of an array.

// Example 1:
// Input: nums = [1,2,2,4]
// Output: [2,3]

// Example 2:
// Input: nums = [1,1]
// Output: [1,2]

#include<bits/stdc++.h>
using namespace std;

// Better Approach (Beats 100% on leetcode)
// vector<int> findErrorNums(vector<int>& nums) {
//     int n = nums.size();
//     int missing = -1;
//     int repeating = -1;
//     vector<int> hasharray(n+1, 0);
//     for(int i = 0; i < n; i++){
//         hasharray[nums[i]]++;
//     }
//     for(int i = 1; i <= n; i++){
//         if(hasharray[i] == 2) repeating = i;
//         if(hasharray[i] == 0) missing = i;
//         if(missing != -1 && repeating != -1) break;
//     }
//     return {repeating, missing};
// }

// Time Complexity: O(2N)
// Space Complexity: O(N)

// Optimal Solution
vector<int> findErrorNums(vector<int>& nums) {  // Check out ChatGPT if it gives integer overflow on Leetcode(Set Mismatch Problem).
    // Notations: 
    // S: sum of the elements of array.
    // S2: sum of square of the elements of array.
    // Sn: sum of first N natural numbers.
    // S2n: sum of square of first N natural numbers.
    // x: repeating number.
    // y: missing number.

    // S - Sn = x - y
    // S2- S2n = x + y
    int n = nums.size();

    // Sum of first N natural numbers:
    long long Sn = (n * (n+1))/2;
    // Sum of square of first N natural numbers:
    long long S2n = (n * (n+1)* (2*n + 1))/6;

    // Sum of all the elements and sum of square of all the elements of array:
    long long S = 0;
    long long S2 = 0;
    for(int i = 0; i < n; i++){
        S += nums[i];
        S2 += (long long)nums[i] * (long long)nums[i];
    }
    long long val1 = S - Sn;    // x - y
    long long val2 = S2 - S2n; 
    val2 = val2 / val1;         // x + y
    long long x = (val1 + val2)/2;
    long long y = x - val1;
    return {(int)x, (int)y};
}
// Time Complexity: O(N)
// Space Complexity: O(1)

int main(){
    vector<int> query = {1,2,2,4};
    cout<<"For the Array: ";
    for(int i : query){
        cout<<i<<" ";
    }
    cout<<endl;
    vector<int> ans = findErrorNums(query);
    cout<<"The Repeating Number: "<<ans[0]<<" and Missing Number is: "<<ans[1]<<endl;
    return 0;
}