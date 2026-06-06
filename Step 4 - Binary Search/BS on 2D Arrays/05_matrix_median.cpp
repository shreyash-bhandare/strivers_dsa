// Given a 2D array matrix that is row-wise sorted. The task is to find the median of the given matrix.

// Example 1
// Input: matrix=[ [1, 4, 9], [2, 5, 6], [3, 7, 8] ] 
// Output: 5
// Explanation: If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. So, median = 5

// Example 2
// Input: matrix=[ [1, 3, 8], [2, 3, 4], [1, 2, 5] ] 
// Output: 3
// Explanation: If we find the linear sorted array, the array becomes 1 1 2 2 3 3 4 5 8. So, median = 3

#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &nums, int target){
    int low = 0;
    int high = nums.size()-1;
    int mid = low + (high-low)/2;
    int lb = nums.size();
    while(low <= high){
        if(nums[mid] > target) {
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

int computeSmallerEquals(vector<vector<int>> &matrix, int target){
    int cnt = 0;
    for(int i = 0; i < matrix.size(); i++){
        cnt += upperBound(matrix[i], target);
    }
    return cnt;
}

int findMedian(vector<vector<int>>&matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0, high = 0;
    int required = (n*m)/2;
    for(int i = 0; i < n; i++){
        if(low > matrix[1][i]) low = matrix[1][i];          // fetching low from first row
        if(high < matrix[n-1][i]) high = matrix[n-1][i];    // fetching high from last row
    }
    while(low <= high){
        int mid = low + (high - low)/2;
        int smallerEquals = computeSmallerEquals(matrix, mid);
        if(smallerEquals <= required) low = mid+1;
        else high = mid-1;
    }
    return low;
}

int main(){
    vector<vector<int>> matrix1 = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    int ans1 = findMedian(matrix1);
    cout << "Median of matrix 1 is: " << ans1 << endl;

    vector<vector<int>> matrix2 = {
        {1, 10, 20},
        {15, 25, 35},
        {5, 30, 40}
    };
    int ans2 = findMedian(matrix2);
    cout << "Median of matrix 2 is: " << ans2 << endl;

    vector<vector<int>> matrix3 = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };
    int ans3 = findMedian(matrix3);
    cout << "Median of matrix 3 is: " << ans3 << endl;
    return 0;
}