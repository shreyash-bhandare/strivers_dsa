#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1;
    int j = n-1;
    int k = m+n-1;
    while(j >= 0){
        if(i >= 0 && nums1[i] > nums2[j]){
            nums1[k] = nums1[i];
            i--;
        }
        else{
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
}

int main(){
    vector<int> nums1 = {3,7,8,0,0,0};
    vector<int> nums2 = {2,4,5};
    merge(nums1, 3, nums2, 3);
    cout<<"Merged Sorted Array: ";
    for(int i : nums1){
        cout<<i<<" ";
    }
    return 0;
}