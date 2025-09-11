#include<bits/stdc++.h>
using namespace std;

void sm_prime_factor(vector<int> q){
    vector<int> spf(100001);
    for(int i = 0; i < 100001; i++){
        spf[i] = i;
    }

    for(int i = 2; i*i <= 100001; i++){
        if(spf[i] == i){
            for(int j = i*i; j <= 100001; j += i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
    for(int i = 0; i < q.size(); i++){          //O(Q * log2(N))
        int n = q[i];
        while(n != 1){
            cout<<spf[n]<<" ";
            n = n/spf[n];
        }
        cout<<endl;
    }
}

// time complexity: O(Nlog(log(N))) + O(Q * log2(N))
// space complexity: O(N)

int main(){

    vector<int> queries = {3547, 6345, 754, 12, 342, 20};
    sm_prime_factor(queries);
    return 0;
}