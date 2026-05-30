// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Example 1:
// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

// Example 2:
// Input: numRows = 1
// Output: [[1]]

#include<bits/stdc++.h>
using namespace std;

vector<int> funNCR(int row){
        long long ans = 1;
        vector<int> temp;
        temp.push_back(1);
        for(int i = 1; i < row; i++){
            ans = ans * (row - i);
            ans = ans / i;
            temp.push_back(ans);
        }
        return temp;
    }

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for(int i = 0; i < numRows; i++){
        ans.push_back(funNCR(i + 1));
    }
    return ans;
}

int main(){
    // Test Case 1
    int numRows1 = 1;
    cout << "Test Case 1:" << endl;
    cout << "numRows = " << numRows1 << endl;
    vector<vector<int>> ans1 = generate(numRows1);
    cout << "Pascal Triangle:" << endl;
    for(auto row : ans1){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Test Case 2
    int numRows2 = 2;
    cout << "Test Case 2:" << endl;
    cout << "numRows = " << numRows2 << endl;
    vector<vector<int>> ans2 = generate(numRows2);
    cout << "Pascal Triangle:" << endl;
    for(auto row : ans2){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Test Case 3
    int numRows3 = 5;
    cout << "Test Case 3:" << endl;
    cout << "numRows = " << numRows3 << endl;
    vector<vector<int>> ans3 = generate(numRows3);
    cout << "Pascal Triangle:" << endl;
    for(auto row : ans3){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Test Case 4
    int numRows4 = 7;
    cout << "Test Case 4:" << endl;
    cout << "numRows = " << numRows4 << endl;
    vector<vector<int>> ans4 = generate(numRows4);
    cout << "Pascal Triangle:" << endl;
    for(auto row : ans4){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Test Case 5
    int numRows5 = 10;
    cout << "Test Case 5:" << endl;
    cout << "numRows = " << numRows5 << endl;
    vector<vector<int>> ans5 = generate(numRows5);
    cout << "Pascal Triangle:" << endl;
    for(auto row : ans5){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}