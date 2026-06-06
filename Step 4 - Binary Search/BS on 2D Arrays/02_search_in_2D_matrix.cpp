// You are given an m x n integer matrix matrix with the following two properties:
// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.
// You must write a solution in O(log(m * n)) time complexity.

// Example 1:
// Input: 
// matrix = [[1,3,5,7],
//           [10,11,16,20],
//           [23,30,34,60]], 
// target = 3
// Output: true

// Example 2:
// Input: 
// matrix = [[1,3,5,7],
//           [10,11,16,20],
//           [23,30,34,60]], 
// target = 13
// Output: false

#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0, high = (n*m - 1);
    while(low <= high){
        int mid = low + (high - low)/2;
        int row = mid/m;
        int col = mid%m;
        if(matrix[row][col] ==  target) return true;
        else if(matrix[row][col] > target) high = mid - 1;
        else low = mid+1;
    }
    return false;
}

int main(){
    vector<vector<int>> matrix1 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target1 = 3;
    bool ans1 = searchMatrix(matrix1, target1);
    cout << "Target " << target1 << (ans1 ? " found" : " not found") << " in matrix 1." << endl;

    vector<vector<int>> matrix2 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target2 = 13;
    bool ans2 = searchMatrix(matrix2, target2);
    cout << "Target " << target2 << (ans2 ? " found" : " not found") << " in matrix 2." << endl;

    vector<vector<int>> matrix3 = {
        {2, 4, 6},
        {8, 10, 12},
        {14, 16, 18}
    };
    int target3 = 16;
    bool ans3 = searchMatrix(matrix3, target3);
    cout << "Target " << target3 << (ans3 ? " found" : " not found") << " in matrix 3." << endl;

    return 0;
}