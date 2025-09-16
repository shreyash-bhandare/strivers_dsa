#include<bits/stdc++.h>
using namespace std;

void reversing(vector<int> &nums, int left, int right){
    while(left < right){
        swap(nums[left], nums[right]);
        left++;
        right--;
    }
}

void rotateByK(vector<int> &nums, int k){ // {1, 2, 3, 4, 5}, k = 3
    int n = nums.size();
    k = k % n;                  // for n > k.
    reversing(nums, 0, n-1);    // {5, 4, 3, 2, 1}
    reversing(nums, 0, k-1);    // {3, 4, 5, 2, 1}
    reversing(nums, k, n-1);    // {3, 4, 5, 1, 2}
}

int main(){
    vector<int> quest = {1,2,3,4,5,6,7};
    rotateByK(quest, 3);
    for(auto i : quest){
        cout<<i<<" ";
    }
    return 0;
}