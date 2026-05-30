#include<bits/stdc++.h>
using namespace std;

void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans){
    // base case: if index reached at the last position, return ans.
    if(index==nums.size()){
        ans.push_back(nums);
        return;
    }

    // generate permutations using swapping.
    for(int i = index; i < nums.size(); i++){
        swap(nums[index], nums[i]);
        recurPermute(index+1, nums, ans);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums){
    vector<vector<int>> ans;
    recurPermute(0, nums, ans);
    return ans;
}

int main(){
    vector<int> nums = {1,2,3};

    vector<vector<int>> ans = permute(nums);

    for(auto v : ans){

        for(auto x : v){
            cout << x << " ";
        }

        cout << endl;
    }
    return 0;
}