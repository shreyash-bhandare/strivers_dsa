// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
// This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

// Example 1:
// Input: 
// matrix = [[1,4,7,11,15],
//           [2,5,8,12,19],
//           [3,6,9,16,22],
//           [10,13,14,17,24],
//           [18,21,23,26,30]], 
// target = 5
// Output: true

// Example 2:
// Input: 
// matrix = [[1,4,7,11,15],
//           [2,5,8,12,19],
//           [3,6,9,16,22],
//           [10,13,14,17,24],
//           [18,21,23,26,30]], 
// target = 20
// Output: false

#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0, col = m-1;
    while(row < n && col >= 0){
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] > target) col--;
        else row++;
    }
    return false;
}

int main(){
    vector<vector<int>> matrix1 = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target1 = 5;
    bool ans1 = searchMatrix(matrix1, target1);
    cout << "Target " << target1 << (ans1 ? " found" : " not found") << " in matrix 1." << endl;

    vector<vector<int>> matrix2 = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target2 = 20;
    bool ans2 = searchMatrix(matrix2, target2);
    cout << "Target " << target2 << (ans2 ? " found" : " not found") << " in matrix 2." << endl;

    vector<vector<int>> matrix3 = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {9, 11, 13, 15},
        {10, 12, 14, 16}
    };
    int target3 = 14;
    bool ans3 = searchMatrix(matrix3, target3);
    cout << "Target " << target3 << (ans3 ? " found" : " not found") << " in matrix 3." << endl;

    return 0;
}