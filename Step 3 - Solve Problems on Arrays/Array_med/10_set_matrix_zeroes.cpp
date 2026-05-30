// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.

// Example 1:

// Input: matrix = [[1,1,1],
//                  [1,0,1],
//                  [1,1,1]]
// Output: [[1,0,1],
//          [0,0,0],
//          [1,0,1]]

// Example 2:

// Input: matrix = [[0,1,2,0],
//                  [3,4,5,2],
//                  [1,3,1,5]]
// Output: [[0,0,0,0],
//          [0,4,5,0],
//          [0,3,1,0]]         

#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int col0 = matrix[0][0];
    int m = matrix.size();      // no of rows
    int n = matrix[0].size();   // no of cols
    // find the cells with 0 and mark those rows and cols to 0
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                if(j != 0){
                    matrix[0][j] = 0;
                }
                else{
                    col0 = 0;
                }
            }
        }
    }
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(matrix[i][j] != 0){      // if current element is 0, no point in checking.
                if(matrix[i][0] == 0 || matrix[0][j] == 0){     // check if that row or col is marked as 0.
                    matrix[i][j] = 0;
                }
            }
                
        }
    }
    if(matrix[0][0] == 0){
        for(int i = 1; i < n; i++){
            matrix[0][i] = 0;
        }
    }
    if(col0 == 0){
        for(int i = 0; i < m; i++){
            matrix[i][0] = 0;
        }
    }
    
}

int main(){
    // Test Case 1
    vector<vector<int>> matrix1 = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    cout << "Test Case 1 Matrix:" << endl;

    for(auto row : matrix1){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    setZeroes(matrix1);

    cout << "Output Matrix:" << endl;

    for(auto row : matrix1){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    cout << endl;


    // Test Case 2
    vector<vector<int>> matrix2 = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };

    cout << "Test Case 2 Matrix:" << endl;

    for(auto row : matrix2){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    setZeroes(matrix2);

    cout << "Output Matrix:" << endl;

    for(auto row : matrix2){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    cout << endl;


    // Test Case 3
    vector<vector<int>> matrix3 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    cout << "Test Case 3 Matrix:" << endl;

    for(auto row : matrix3){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    setZeroes(matrix3);

    cout << "Output Matrix:" << endl;

    for(auto row : matrix3){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    cout << endl;


    // Test Case 4
    vector<vector<int>> matrix4 = {
        {1,0,3},
        {4,5,6},
        {0,8,9}
    };

    cout << "Test Case 4 Matrix:" << endl;

    for(auto row : matrix4){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    setZeroes(matrix4);

    cout << "Output Matrix:" << endl;

    for(auto row : matrix4){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    cout << endl;


    // Test Case 5
    vector<vector<int>> matrix5 = {
        {1}
    };

    cout << "Test Case 5 Matrix:" << endl;

    for(auto row : matrix5){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    setZeroes(matrix5);

    cout << "Output Matrix:" << endl;

    for(auto row : matrix5){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    cout << endl;

    return 0;
}