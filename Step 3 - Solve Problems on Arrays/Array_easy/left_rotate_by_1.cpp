#include<bits/stdc++.h>
using namespace std;

void rotateBy1(vector<int> &nums){
    int n = nums.size();
    int temp = nums[0];
    for(int i = 0; i < n-1; i++){
        nums[i] = nums[i+1];
    }
    nums[n-1] = temp;
}

// time complexity: O(N)
// space complexity: O(1)
// if someone asks what is the space complexity for the whole code it is O(N) but generally,
// we tell the extra space that we used, in this case it it O(1).

int main(){
    vector<int> quest = {1,2,3,4,5,6,7};
    rotateBy1(quest);
    for(auto i : quest){
        cout<<i<<" ";
    }
    return 0;
}