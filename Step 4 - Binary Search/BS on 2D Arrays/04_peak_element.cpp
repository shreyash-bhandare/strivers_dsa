// A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the 
// left, right, top, and bottom.

// Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, 
// find any peak element mat[i][j] and return the length 2 array [i,j].

// You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

// You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

// Example 1:
// Input: mat = [[1,4],[3,2]]
// Output: [0,1]
// Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.

// Example 2:
// Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
// Output: [1,1]
// Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.

#include<bits/stdc++.h>
using namespace std;

int findMaxInd(vector<vector<int>>& mat, int n, int col){
    int maxValue = -1;
    int ind = -1;
    for(int i = 0; i < n; i++){
        if(mat[i][col] > maxValue){
            maxValue = mat[i][col];
            ind = i;
        }
    }
    return ind;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = m-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        int maxRowInd = findMaxInd(mat, n, mid);
        int left = mid - 1 >= 0 ? mat[maxRowInd][mid-1] : -1;
        int right = mid + 1 < m ? mat[maxRowInd][mid+1] : -1;
        if(mat[maxRowInd][mid] > left && mat[maxRowInd][mid] > right){
            return {maxRowInd, mid};
        }
        else if(mat[maxRowInd][mid] < right) low = mid+1;
        else high = mid-1;
    }
    return {-1, -1};
}

int main(){
    vector<vector<int>> mat1 = {
        {1, 4},
        {3, 2}
    };
    vector<int> ans1 = findPeakGrid(mat1);
    cout << "Peak element in matrix 1 found at: [ " << ans1[0] << ", " << ans1[1] << " ]" << endl;

    vector<vector<int>> mat2 = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };
    vector<int> ans2 = findPeakGrid(mat2);
    cout << "Peak element in matrix 2 found at: [ " << ans2[0] << ", " << ans2[1] << " ]" << endl;

    vector<vector<int>> mat3 = {
        {1,  2,  3,  6,  5},
        {16, 41, 23, 22, 6},
        {15, 17, 24, 21, 7},
        {14, 18, 19, 20, 10},
        {13, 14, 11, 10, 9}
    };
    vector<int> ans3 = findPeakGrid(mat3);
    cout << "Peak element in matrix 3 found at: [ " << ans3[0] << ", " << ans3[1] << " ]" << endl;
    return 0;
}