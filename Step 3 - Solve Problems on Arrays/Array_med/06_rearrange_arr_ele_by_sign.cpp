#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v){
    for(int x : v) cout << x << " ";
    cout<<endl;
}

// brute force: creating 2 separate arrays.
// vector<int> rearrangeArray(vector<int>& nums) {
//     int n = nums.size();
//     int pos[n/2];
//     int neg[n/2];
//     int p = 0, ng = 0;
//     for(int i = 0; i < n; i++){
//         if(nums[i] > 0){
//             pos[p] = nums[i];
//             p++;
//         }
//         else{
//             neg[ng] = nums[i];
//             ng++;
//         }
//     }
//     for(int i = 0; i < n/2; i++){
//         nums[2*i] = pos[i];
//         nums[2*i+1] = neg[i];
//     }
//     return nums;
// }

// optimal solution: using 2 separate pointers.
vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 0);
    int pos = 0, neg = 1;
    for(int i = 0; i < n; i++){
        if(nums[i] > 0){
            ans[pos] = nums[i];
            pos += 2;
        }
        else {
            ans[neg] = nums[i];
            neg += 2;
        }
    }
    return ans;
}

int main(){
    // Test case 1: Alternating signs
    vector<int> nums1 = {3,1,-2,-5,2,-4};
    vector<int> ans1 = rearrangeArray(nums1);
    cout << "Test 1: ";
    printVector(ans1);  // Expected: 3 -2 1 -5 2 -4

    // Test case 2: Positives first, then negatives
    vector<int> nums2 = {1,2,3,-1,-2,-3};
    vector<int> ans2 = rearrangeArray(nums2);
    cout << "Test 2: ";
    printVector(ans2);  // Expected: 1 -1 2 -2 3 -3

    // Test case 3: Negatives first, then positives
    vector<int> nums3 = {-5,-2,-1,2,4,3};
    vector<int> ans3 = rearrangeArray(nums3);
    cout << "Test 3: ";
    printVector(ans3);  // Expected: 2 -5 4 -2 3 -1

    // Test case 4: Smallest valid input
    vector<int> nums4 = {1,-1};
    vector<int> ans4 = rearrangeArray(nums4);
    cout << "Test 4: ";
    printVector(ans4);  // Expected: 1 -1

    return 0;
}