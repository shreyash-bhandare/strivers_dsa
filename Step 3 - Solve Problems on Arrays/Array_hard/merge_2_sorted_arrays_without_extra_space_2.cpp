#include<bits/stdc++.h>
using namespace std;

void swapIfGreater(vector<int> &nums1, vector<int> &nums2, int ind1, int ind2){
    if(nums1[ind1] > nums2[ind2]){
        swap(nums1[ind1], nums2[ind2]);
    }
}

void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
    int len = n+m;
    int gap = (len / 2) + (len % 2);

    while(gap > 0){

        int left = 0;
        int right = left + gap;

        while(right < len){

            // if left is in nums1 and right is in nums2
            if(left < n && right >= n){
                swapIfGreater(nums1, nums2, left, right - n);
            }

            // if both are in nums2
            else if(left >= n){

                if(nums2[left - n] > nums2[right - n]){
                    swap(nums2[left - n], nums2[right - n]);
                }
            }

            // if both are in nums1
            else{

                if(nums1[left] > nums1[right]){
                    swap(nums1[left], nums1[right]);
                }
            }

            left++, right++;
        }

        if(gap == 1) break;

        gap = ceil((double)gap/2);
    }

    for(int i = 0; i < m; i++){
        nums1[n+i] = nums2[i];
    }
}

// Time Complexity: O(logbase2(n+m)) because each time gap is getting reduced by 2 in the outer loop. 
// O(n+m) for inner loop
// Total = O(logbase2(n+m * (n+m)))
// Space Complexity: O(1)

int main(){

    vector<int> nums1 = {1,2,3,0,0,0};
    int n = 3;

    vector<int> nums2 = {2,5,6};
    int m = 3;

    cout<<"Nums1: ";
    for(int i = 0; i < n; i++){
        cout<<nums1[i]<<" ";
    }
    cout<<endl;

    cout<<"Nums2: ";
    for(int i : nums2){
        cout<<i<<" ";
    }
    cout<<endl;

    merge(nums1, n, nums2, m);

    cout<<"Merged Array: ";

    for(int i : nums1){
        cout<<i<<" ";
    }

    cout<<endl;

    return 0;
}