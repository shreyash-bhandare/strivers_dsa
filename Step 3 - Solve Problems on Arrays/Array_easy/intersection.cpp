// Intersection of the Arrays. 
// Repetition is allowed.

#include<bits/stdc++.h>
using namespace std;

// Brute force
vector<int> doIntersection(vector<int> &nums1, vector<int> &nums2){
    vector<int> ans = {};
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> visited(n2, 0);
    
    for(int i = 0; i < nums1.size(); i++){
        for(int j = 0; j < nums2.size(); j++){
            if(nums1[i] == nums2[j] && visited[j] != 1){
                ans.push_back(nums2[j]);
            }
            if(nums1[i] < nums2[j]){
                break;
            }
        }
    }

    return ans;
}

int main(){
    vector<int> nums1 = {1, 2, 3, 3, 4};
    vector<int> nums2 = {2, 3, 3, 4, 5, 6, 6};
    vector<int> ans = doIntersection(nums1, nums2);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}