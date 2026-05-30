#include<bits/stdc++.h>
using namespace std;

//Brute Force
// using set
// vector<int> doUnion(vector<int> &nums1, vector<int> &nums2){
//     vector<int> ans;
//     set<int> st;
//     for(int i = 0; i < nums1.size(); i++){      // O(n1*logn1)
//         st.insert(nums1[i]);
//     }
//     for(int i = 0; i < nums2.size(); i++){      // O(n2*logn2)
//         st.insert(nums2[i]);
//     }
//     for(auto i : st){
//         ans.push_back(i);                       // O(n1+n2)
//     }
//     return ans;
// }
// TC : O(n1*logn1 + n2*logn2) + O(n1+n2)
// SC : O(n1+n2)(for set) + O(n1+n2)(to return the ans)

// optimal approach
vector<int> doUnion(vector<int> &nums1, vector<int> &nums2){
    int n1 = nums1.size();
    int n2 = nums2.size();
    int i = 0;
    int j = 0;
    vector<int> ans;
    while(i < n1 && j < n2){
        if(nums1[i] <= nums2[j]){
            if(ans.size() == 0 || ans.back() != nums1[i]){
                ans.push_back(nums1[i]);
            }
            i++;
        }
        else{
            if(ans.size() == 0 || ans.back() != nums2[j]){
                ans.push_back(nums2[j]);
            }
            j++;
        }
    }
    while(i < n1){
        if(ans.size() == 0 || ans.back() != nums1[i]){
            ans.push_back(nums1[i]);
        }
        i++;
    }
    while(j < n2){
        if(ans.size() == 0 || ans.back() != nums2[j]){
            ans.push_back(nums2[j]);
        }
        j++;
    }
    return ans;
}
// time complexity: O(n1 + n2)
// space complexity: O(n1 + n2) // for returning the ans.

int main(){
    vector<int> nums1 = {1, 2, 3, 3, 4};
    vector<int> nums2 = {2, 4, 5, 6, 6};
    vector<int> ans = doUnion(nums1, nums2);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}