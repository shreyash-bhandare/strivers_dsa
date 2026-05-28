// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
// DO NOT allocate another 2D matrix and do the rotation.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

// Example 2:
// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // do the transpose
    for(int i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // now reverse each row
    for(int i = 0; i < n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
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

    rotate(matrix1);

    cout << "Rotated Matrix:" << endl;

    for(auto row : matrix1){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    cout << endl;


    // Test Case 2
    vector<vector<int>> matrix2 = {
        {5,1,9,11},
        {2,4,8,10},
        {13,3,6,7},
        {15,14,12,16}
    };

    cout << "Test Case 2 Matrix:" << endl;

    for(auto row : matrix2){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    rotate(matrix2);

    cout << "Rotated Matrix:" << endl;

    for(auto row : matrix2){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    cout << endl;


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

    rotate(matrix3);

    cout << "Rotated Matrix:" << endl;

    for(auto row : matrix3){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    cout << endl;


    // Test Case 4
    vector<vector<int>> matrix4 = {
        {1,2},
        {3,4}
    };

    cout << "Test Case 4 Matrix:" << endl;

    for(auto row : matrix4){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    rotate(matrix4);

    cout << "Rotated Matrix:" << endl;

    for(auto row : matrix4){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    cout << endl;


    // Test Case 5
    vector<vector<int>> matrix5 = {
        {10,20,30},
        {40,50,60},
        {70,80,90}
    };

    cout << "Test Case 5 Matrix:" << endl;

    for(auto row : matrix5){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    rotate(matrix5);

    cout << "Rotated Matrix:" << endl;

    for(auto row : matrix5){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}