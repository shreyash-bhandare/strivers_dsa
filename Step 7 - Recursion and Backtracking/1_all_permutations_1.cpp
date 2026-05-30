#include<bits/stdc++.h>
using namespace std;

void recurPermute(vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, int freq[]){
    // if the size of generated array and given array is same, that means the permutation is generated.
    if(ds.size()==nums.size()){
        ans.push_back(ds);
        return;
    }
    // check for each element if it is put in the ds or not. if it is not put, put it. then flag it as taken (i.e. 1).
    // now go for recursion call with that number. find permutations with it.
    // now backtrack and mark it as not taken and generate permutation with next number.
    for(int i = 0; i < nums.size(); i++){
        if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i]=1;
            recurPermute(nums, ans, ds, freq);
            freq[i]=0;
            ds.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &nums){
    vector<vector<int>> ans;    // for storing answer and returning all the generated permutations.
    vector<int>ds;              // for generating the permutation.
    int freq[nums.size()]={0};  // to mark if a number is taken or not. freq[i]=1 if taken, otherwise 0. 
                                // in the beginning, all numbers are flaged/marked as 0
    recurPermute(nums, ans, ds, freq);
    return ans;
}

// time complexity: o(N! * N)
// number of permutations: N! and number of elements: N

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