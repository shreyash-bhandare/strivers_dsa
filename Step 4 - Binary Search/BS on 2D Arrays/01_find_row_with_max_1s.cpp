// Given a non-empty grid mat consisting of only 0s and 1s, where all the rows are sorted in ascending order, 
// find the index of the row with the maximum number of ones.
// If two rows have the same number of ones, consider the one with a smaller index. 
// If no 1 exists in the matrix, return -1.

// Example 1
// Input : mat = [ [1, 1, 1], [0, 0, 1], [0, 0, 0] ]
// Output: 0
// Explanation: The row with the maximum number of ones is 0 (0 - indexed).

// Example 2
// Input: mat = [ [0, 0], [0, 0] ]
// Output: -1
// Explanation: The matrix does not contain any 1. So, -1 is the answer.

#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &nums, int target){  // O(log M)
    int low = 0;
    int high = nums.size()-1;
    int mid = low + (high-low)/2;
    int lb = nums.size();
    while(low <= high){
        if(nums[mid] >= target) {
            lb = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
        mid = (low+high)/2;
    }
    return lb;
}

int rowWithMax1s(vector < vector < int >> & mat) {
    int n = mat.size();
    int m = mat[0].size();
    int cnt_max = 0;
    int ind = -1;
    for(int i = 0; i < n; i++){     // O(N)
        int cnt_ones = m - lowerBound(mat[i], 1);
        if(cnt_ones > cnt_max){
            cnt_max = cnt_ones;
            ind = i;
        }
    }
    return ind;
}

int main(){
    vector<vector<int>> mat1 = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1},
        {0, 1, 1, 1}
    };
    int ans1 = rowWithMax1s(mat1);
    cout << "Row with maximum 1's in matrix 1 is: " << ans1 << endl;

    vector<vector<int>> mat2 = {
        {0, 0, 0, 0},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };
    int ans2 = rowWithMax1s(mat2);
    cout << "Row with maximum 1's in matrix 2 is: " << ans2 << endl;


    vector<vector<int>> mat3 = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    int ans3 = rowWithMax1s(mat3);
    cout << "Row with maximum 1's in matrix 3 is: " << ans3 << endl;
    return 0;
}