#include<bits/stdc++.h>
using namespace std;

void explainMap(){
    map <int, int> mp; //stores value as key - value pair
    // key can be any data type, same for value
    // key should be unique(in sorted order), but value can be or can not be.
    // map <pair<int, int>, int> mp;
    // map <int, pair<int, int>> mp;
    mp[1] = 2;
    mp.insert({2,3});
    mp.emplace(3,4);
    for(auto it: mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<mp[1]<<endl;
    cout<<mp[5];
    auto it = mp.find(3);
    cout<<(*it).second<<endl;

    auto it = mp.find(5); // return the pointer after the map

    auto it = mp.upper_bound(2);
    auto it = mp.lower_bound(3);

    // works in O(logN) time complexity
}

void explainMultiMap(){
    //stores duplicate keys also
    // stores in sorted fashion.
}

void explainUnorderedMap(){
    // does not store duplicate keys also
    // stores in unsorted fashion.
    // works in O(1) time.
}

int main(){
    explainMap();
    explainMultiMap();
    explainUnorderedMap();
    return 0;
}