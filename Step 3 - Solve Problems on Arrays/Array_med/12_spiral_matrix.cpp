// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// Example 2:
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]


#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    int left = 0, right = col - 1;
    int top = 0, bottom = row - 1;
    vector<int> ans;            // vector to store traversal

    while(left <= right && top <= bottom){
        for(int i = left; i <= right; i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i = top; i <= bottom; i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top <= bottom){
            for(int i = right; i >= left; i--){
                ans.push_back(matrix[bottom][i]);
            }
        }
        bottom--;
        if(left <= right){
            for(int i = bottom; i >= top; i--){
            ans.push_back(matrix[i][left]);
            }
        }
        left++;
    }
    return ans;
}

int main(){
    // Test Case 1
    vector<vector<int>> matrix1 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    cout << "Test Case 1 Matrix:" << endl;

    for(auto row : matrix1){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    vector<int> ans1 = spiralOrder(matrix1);

    cout << "Spiral Order: ";

    for(int x : ans1){
        cout << x << " ";
    }

    cout << endl << endl;


    // Test Case 2
    vector<vector<int>> matrix2 = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    cout << "Test Case 2 Matrix:" << endl;

    for(auto row : matrix2){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    vector<int> ans2 = spiralOrder(matrix2);

    cout << "Spiral Order: ";

    for(int x : ans2){
        cout << x << " ";
    }

    cout << endl << endl;


    // Test Case 3
    vector<vector<int>> matrix3 = {
        {1}
    };

    cout << "Test Case 3 Matrix:" << endl;

    for(auto row : matrix3){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    vector<int> ans3 = spiralOrder(matrix3);

    cout << "Spiral Order: ";

    for(int x : ans3){
        cout << x << " ";
    }

    cout << endl << endl;


    // Test Case 4
    vector<vector<int>> matrix4 = {
        {1,2,3,4}
    };

    cout << "Test Case 4 Matrix:" << endl;

    for(auto row : matrix4){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    vector<int> ans4 = spiralOrder(matrix4);

    cout << "Spiral Order: ";

    for(int x : ans4){
        cout << x << " ";
    }

    cout << endl << endl;


    // Test Case 5
    vector<vector<int>> matrix5 = {
        {1},
        {2},
        {3},
        {4}
    };

    cout << "Test Case 5 Matrix:" << endl;

    for(auto row : matrix5){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    vector<int> ans5 = spiralOrder(matrix5);

    cout << "Spiral Order: ";

    for(int x : ans5){
        cout << x << " ";
    }

    cout << endl << endl;
    return 0;
}