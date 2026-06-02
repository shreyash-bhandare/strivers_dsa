#include<bits/stdc++.h>
using namespace std;

// bool isSafe()
bool isSafe(int row, int col, vector<string>&board, int n){
    int duprow = row;
    int dupcol = col;

    // checking in the top-left diagonal
    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }
    row = duprow;
    col = dupcol;
    // checking in the left side
    while(col >= 0){
        if(board[row][col] == 'Q') return false;
        col--;
    }
    col = dupcol;
    // checking in the bottom left diagonal
    while(row < n && col >= 0){
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }
    return true;
}

void solve(int col, vector<string>&board, vector<vector<string>>&ans, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int row = 0; row < n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 'Q';
            solve(col+1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');   // if n = 4, it creates a string of "...."
    // for n = 4, creating the board as:
    // ["....", "....", "....", "....",]
    for(int i = 0; i < n; i++){
        board[i] = s;
    }
    // on leetcode, do this instead:
    // vector<string> board(n, string(n, '.'));
    solve(0, board, ans, n);
    return ans;
}

int main(){
    int n = 5;
    vector<vector<string>> ans = solveNQueens(n);
    cout<<"The boards with solution for "<<n<<" Queens are: "<<endl;
    for(int i = 0; i < ans.size(); i++){
        cout<<"[ ";
        for(int j = 0; j < ans[0].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}