#include<bits/stdc++.h>
using namespace std;

// sort it according to second element.
// if second element is same, sort acc to first element but in descending order.
bool comp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    // if both are same
    if(p1.first > p2.first) return true;
    return false;
}

void extra(){
    vector<int> vc;
    vc.emplace_back(3);
    vc.emplace_back(9);
    vc.emplace_back(5);
    vc.emplace_back(7);
    vc.emplace_back(4);
    //sorting the vector:
    //sort(vc.begin(), vc.end());
    sort(vc.begin()+1, vc.begin()+4);
    for(auto v : vc)
        cout<<v<<" "<<endl;

    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};
    // sort it according to second element.
    // if second element is same, sort acc to first element but in descending order.
    sort(a, a+3, comp);
    for(auto p : a)
        cout<<p.first<<" "<<p.second<<endl;

    // 7 in binary is 111, 3 1's 
    int num = 7;
    int cnt = __builtin_popcount(num); // returns no. of set bits, i.e. 3 here
    // if it was 6, i.e. 110, would have returned 2
    cout<<cnt<<endl;

    long long num2 = 24379274475;
    int cnt1 = __builtin_popcountll(num2);
    cout<<cnt1<<endl;

    //print all permutations of a string:
    string s = "123";
    do{
        cout<<s<<endl;
    }
    while(next_permutation(s.begin(), s.end()));
    // prints 123 132 213 231 312 321 returns false after end of permutations.
    // follows dictionary order.
    
    string s1 = "231";
    do{
        cout<<s1<<endl;
    }
    while(next_permutation(s1.begin(), s1.end()));
    //prints 231 312 321 returns false
    // doesn't print all permutations
    // for that, need to sort the string. sort(s1.begin(), s1.end())

    int arr[] = {1, 10, 23 , 12, 13, 43};
    int maxi = *max_element(arr, arr+4);
    int mini = *min_element(arr+2, arr+6);
    cout<<maxi<<" "<<mini<<endl;
}

int main(){
    extra();
    return 0;
}