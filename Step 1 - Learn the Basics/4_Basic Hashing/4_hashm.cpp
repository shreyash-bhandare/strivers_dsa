#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];

    // pre-compute while taking input
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        mpp[arr[i]]++;
    }

    // iterate in the map
    // for(auto it : mpp){
    //     cout<<it.first<<" -> "<<it.second<<endl;
    // }
    // map stores values in sorted order.

    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        // fetch
        cout<<mpp[num]<<endl;
    }
    return 0;
}