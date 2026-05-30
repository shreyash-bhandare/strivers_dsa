// Given a collection of candidate numbers (candidates) and a target number (target), 
// find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

// Example 1:
// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [[1,1,6],[1,2,5],[1,7],[2,6]]

// Example 2:
// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [[1,2,2],[5]]

#include<bits/stdc++.h>
using namespace std;

void findCombination(int ind, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int>&ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = ind; i < candidates.size(); i++){
            // for the same i, we can't pick same number. but for different i, i.e. i greater than ind is allowed.
            // i.e. on the same recursion level, we can't take same number twice.
            // but for different level(i.e. greater level), we can pick another element even though it is same as previous one.
            if(i > ind && candidates[i] == candidates[i-1]) continue; 
            if(candidates[i] > target) break;
            ds.push_back(candidates[i]);
            findCombination(i+1, target-candidates[i], candidates, ans, ds);
            ds.pop_back();
        }
    }

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}

int main(){
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans = combinationSum2(candidates, target);
    cout<<"These will be the arrays with combination sum "<<target<<": "<<endl;
    for(int i = 0; i < ans.size(); i++){
        cout<<"[";
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}