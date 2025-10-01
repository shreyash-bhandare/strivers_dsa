#include<bits/stdc++.h>
using namespace std;

// Another Solution: Keep count of 0, 1, 2. Place the no. of 0s then 1s and then 2s.

// DNF Algorithm
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size()-1;
        
    while(mid <= high) {
        if(nums[mid] == 0){
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

void printVector(vector<int>& nums) {
    for(int x : nums) cout << x << " ";
    cout << endl;
}

int main() {
    // Test case 1: Mixed order
    vector<int> nums1 = {2,0,2,1,1,0};
    sortColors(nums1);
    cout << "Test 1: ";
    printVector(nums1); // Expected: 0 0 1 1 2 2

    // Test case 2: Already sorted
    vector<int> nums2 = {0,0,1,1,2,2};
    sortColors(nums2);
    cout << "Test 2: ";
    printVector(nums2); // Expected: 0 0 1 1 2 2

    // Test case 3: Reverse order
    vector<int> nums3 = {2,2,1,1,0,0};
    sortColors(nums3);
    cout << "Test 3: ";
    printVector(nums3); // Expected: 0 0 1 1 2 2

    // Test case 4: Single element
    vector<int> nums4 = {1};
    sortColors(nums4);
    cout << "Test 4: ";
    printVector(nums4); // Expected: 1

    // Test case 5: Only one type
    vector<int> nums5 = {0,0,0,0};
    sortColors(nums5);
    cout << "Test 5: ";
    printVector(nums5); // Expected: 0 0 0 0

    vector<int> nums6 = {2,2,2,2};
    sortColors(nums6);
    cout << "Test 6: ";
    printVector(nums6); // Expected: 2 2 2 2

    return 0;
}