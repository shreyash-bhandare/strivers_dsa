#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    // pre-compute while taking input
    unordered_map<char, int> mpp;
    for(int i = 0; i < s.size(); i++){
        mpp[s[i]]++;
    }

    // iterate in the map
    for(auto it : mpp){
        cout<<it.first<<" -> "<<it.second<<endl;
    }
    // map stores values in unsorted order.

    int q;
    cin>>q;
    while(q--){
        char ch;
        cin>>ch;
        // fetch
        cout<<mpp[ch]<<endl;
    }
    return 0;
}