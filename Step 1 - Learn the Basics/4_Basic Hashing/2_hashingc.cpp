// //hashing for characters

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     string s; 
//     cin>>s;

//     //pre-compute
//     int hashh[26] = {0};
//     for(int i = 0; i < s.size(); i++){
//         hashh[s[i] - 'a']++;
//     }

//     int q;
//     cin>>q;
//     while(q--){
//         char c;
//         cin>>c;
//         //fetch
//         cout<<hashh[c - 'a']<<endl;
//     }
//     return 0;
// }

// for 256 characters:
//hashing for characters

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; 
    cin>>s;

    //pre-compute
    int hashh[256] = {0};
    for(int i = 0; i < s.size(); i++){
        hashh[s[i]]++;
    }

    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        //fetch
        cout<<hashh[c]<<endl;
    }
    return 0;
}