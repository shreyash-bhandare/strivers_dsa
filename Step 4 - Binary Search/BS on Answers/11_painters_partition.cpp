// You are given A painters and an array C of N integers where C[i] denotes the length of the ith board. 
// Each painter takes B units of time to paint 1 unit of board. You must assign boards to painters such that:

// Each painter paints only contiguous segments of boards.
// No board can be split between painters.
// The goal is to minimize the time to paint all boards.

// Return the minimum time required to paint all boards modulo 10000003.

// Example 1
// Input: A = 2, B = 5, C = [1, 10]
// Output: 50
// Explanation:
// Painter 1 paints board 0 (length = 1), time = 5
// Painter 2 paints board 1 (length = 10), time = 50
// Max time = 50
// Return 50 % 10000003 = 50

// Example 2
// Input: A = 10, B = 1, C = [1, 8, 11, 3]
// Output: 11
// Explanation:
// Assign each board to a different painter
// Max time = max(1, 8, 11, 3) = 11
// Return 11 % 10000003 = 11

#include<bits/stdc++.h>
using namespace std;

int countPainters(vector<int>& boards, long long maxLen){
    int painters = 1;
    long long currLen = 0;

    for(int i = 0; i < boards.size(); i++){
        if(currLen + boards[i] <= maxLen){
            currLen += boards[i];
        }
        else{
            painters++;
            currLen = boards[i];
        }
    }
    return painters;
}

int paint(int A, int B, vector<int>& C) {
    long long low = *max_element(C.begin(), C.end());
    long long high = accumulate(C.begin(), C.end(), 0LL);

    while(low <= high){
        long long mid = low + (high - low) / 2;
        int painters = countPainters(C, mid);
        if(painters > A){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return (low * 1LL * B) % 10000003;
}

int main(){
    vector<int> boards1 = {1, 10};
    int painters1 = 2;
    int timePerUnit1 = 5;
    int ans1 = paint(painters1, timePerUnit1, boards1);
    cout << "Minimum time for boards [ ";
    for(int board : boards1){
        cout << board << " ";
    }
    cout << "] is " << ans1 << " for " << painters1 << " painters and " << timePerUnit1 << " units of time per board length." << endl;

    vector<int> boards2 = {1, 8, 11, 3};
    int painters2 = 10;
    int timePerUnit2 = 1;
    int ans2 = paint(painters2, timePerUnit2, boards2);
    cout << "Minimum time for boards [ ";
    for(int board : boards2){
        cout << board << " ";
    }
    cout << "] is " << ans2 << " for " << painters2 << " painters and " << timePerUnit2 << " units of time per board length." << endl;

    vector<int> boards3 = {10, 20, 30, 40};
    int painters3 = 2;
    int timePerUnit3 = 5;
    int ans3 = paint(painters3, timePerUnit3, boards3);
    cout << "Minimum time for boards [ ";
    for(int board : boards3){
        cout << board << " ";
    }
    cout << "] is " << ans3 << " for " << painters3 << " painters and " << timePerUnit3 << " units of time per board length." << endl;
    return 0;
}