#include<bits/stdc++.h>
using namespace std;

int large(vector<int> nums){
    int max = nums[0];
    for(int i = 0; i < nums.size(); i++){
        if(max < nums[i]) max = nums[i];
    }
    return max;
}

int main(){
    vector<int> quest = {12, 23, 64, 21, 44};
    cout<<large(quest);
    return 0;
}