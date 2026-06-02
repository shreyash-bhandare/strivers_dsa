// Given a grid of dimensions n x n. A rat is placed at coordinates (0, 0) and wants to reach at coordinates (n-1, n-1).
// Find all possible paths that rat can take to travel from (0, 0) to (n-1, n-1). 
// The directions in which rat can move are 'U' (up) , 'D' (down) , 'L' (left) , 'R' (right).
// The value 0 in grid denotes that the cell is blocked and rat cannot use that cell for travelling, 
// whereas value 1 represents that rat can travel through the cell. If the cell (0, 0) has 0 value, 
// then mouse cannot move to any other cell.

// Note :
// In a path no cell can be visited more than once.
// If there is no possible path then return empty vector.

// Example 1
// Input : n = 4 , grid = [ [1, 0, 0, 0] , [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1] ]
// Output : [ "DDRDRR" , "DRDDRR" ]
// Explanation : The rat has two different path to reach (3, 3).
// The first path is (0, 0) => (1, 0) => (2, 0) => (2, 1) => (3, 1) => (3, 2) => (3, 3).
// The second path is (0,0) => (1,0) => (1,1) => (2,1) => (3,1) => (3,2) => (3,3).

// Example 2
// Input : n = 2 , grid = [ [1, 0] , [1, 0] ]
// Output : -1
// Explanation : There is no path that rat can choose to travel from (0,0) to (1,1).

#include<bits/stdc++.h>
using namespace std;

// void solve(int i, int j, vector<vector<int> > &grid, int n, vector<string>&ans, string move, vector<vector<int> > &visited){
//         if(i == n-1 && j == n-1){
//             ans.push_back(move);
//             return;
//         }
//         // down
//         if(i+1 < n && visited[i+1][j] != 1 && grid[i+1][j] == 1){
//             visited[i+1][j] = 1;
//             solve(i+1, j, grid, n, ans, move + 'D', visited);
//             // backtrack
//             visited[i+1][j] = 0;
//         }
//         // left
//         if(j-1 >= 0 && visited[i][j-1] != 1 && grid[i][j-1] == 1){
//             visited[i][j-1] = 1;
//             solve(i, j-1, grid, n, ans, move + 'L', visited);
//             // backtrack
//             visited[i][j-1] = 0;
//         }
//         // right
//         if(j+1 < n && visited[i][j+1] != 1 && grid[i][j+1] == 1){
//             visited[i][j+1] = 1;
//             solve(i, j+1, grid, n, ans, move + 'R', visited);
//             // backtrack
//             visited[i][j+1] = 0;
//         }
//         // up
//         if(i-1 >= 0 && visited[i-1][j] != 1 && grid[i-1][j] == 1){
//             visited[i-1][j] = 1;
//             solve(i-1, j, grid, n, ans, move + 'U', visited);
//             // backtrack
//             visited[i-1][j] = 0;
//         }
//     }

// vector<string> findPath(vector<vector<int> > &grid) {
//     int n = grid.size();
//     vector<string> ans;
//     vector<vector<int>> visited(n, vector<int>(n, 0));
//     solve(0, 0, grid, n, ans, "", visited);
//     return ans;
// }

void solve(int i, int j, vector<vector<int> > &grid, int n, vector<string>&ans, string move, vector<vector<int> > &visited, int di[], int dj[]){
    if(i == n-1 && j == n-1){
        ans.push_back(move);
        return;
    }
    string dir = "DLRU";
    for(int ind = 0; ind < 4; ind++){
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        if(nexti >= 0 && nexti < n && nextj >= 0 && nextj < n && !visited[nexti][nextj] && grid[nexti][nextj] == 1){
            visited[i][j] = 1;
            solve(nexti, nextj, grid, n, ans, move + dir[ind], visited, di, dj);
            // backtrack
            visited[i][j] = 0;
        }
    }
}

vector<string> findPath(vector<vector<int> > &grid) {
    int n = grid.size();
    vector<string> ans;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    int di[] = {1,0,0,-1};
    int dj[] = {0,-1,1,0};
    if(grid[0][0] == 1)solve(0, 0, grid, n, ans, "", visited, di, dj);
    return ans;
}

int main(){
    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> ans = findPath(grid);

    cout << "All possible paths are:\n";

    if(ans.empty()){
        cout << "-1\n";
    }
    else{
        for(string path : ans){
            cout << path << endl;
        }
    }

    return 0;
}