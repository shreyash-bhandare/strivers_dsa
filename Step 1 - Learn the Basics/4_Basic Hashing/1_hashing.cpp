//hashing for numbers
#include<bits/stdc++.h>
using namespace std;

//input format:
//take size of array
//take array elements
//take no of queries
//take queries

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    //pre-compute
    int hash[13] = {0};
    for(int i = 0; i < n; i++){
        hash[arr[i]] += 1;
    }

    int q;
    cin>>q;

    while(q--){
        int num;
        cin>>num;
        
        //fetch
        cout<<hash[num]<<endl;
    }
    return 0;
}

//note: 
// we can declare array of size:
//             in main function          globally
// int arr            10^6                 10^7
// bool arr           10^7                 10^8
// 1e7 means 10^7
// when we declare an array globally, all values are 0
// when we declare an array in int main function, all values are garbage values.
