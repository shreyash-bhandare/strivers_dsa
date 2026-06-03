#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& nums, int target){
    int ans = nums.size();
    int low = 0, high = nums.size()-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] >= target){
            high = mid-1;
            ans = mid;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int upperBound(vector<int>& nums, int target){
    int ans = nums.size();
    int low = 0, high = nums.size()-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] > target){
            high = mid-1;
            ans = mid;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int countOccurrences(vector<int>& arr, int target) {
    return upperBound(arr, target) - lowerBound(arr, target);
}

int main(){
    vector<int> nums = {1,2,3,3,5,8,8,8,8,9,10,10,11};
    int target = 8;

    int ans = countOccurrences(nums, target);

    cout << "Array: [ ";
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;

    cout << "Target = " << target << endl;
    cout << "Count of Occurences = " << ans << endl;
    return 0;
}