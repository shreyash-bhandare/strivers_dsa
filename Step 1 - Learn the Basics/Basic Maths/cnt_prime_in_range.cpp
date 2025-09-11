#include<bits/stdc++.h>
using namespace std;

vector<int> getSieve(int n){
    vector<int> prime(n+1, 1);
    for(int i = 2; i*i <= n; i++){
        if(prime[i] == 1){
            for(int j = i*i; j <= n; j+=i){
                prime[j] = 0;
            }
        }
    }
    prime[0] = 0;
    prime[1] = 0;
    return prime;
}

// O(N(log(logN)))

void primeRange(int left, int right){                   // calculating sieve upto 10^6 as per constraint.
    vector<int> ans = getSieve(1000000);
    for(int i = 1; i < ans.size(); i++){       // calculate prefix sum
        ans[i] = ans[i] + ans[i-1];             // O(n)
    }
    cout<<ans[right] - ans[left - 1]<<endl;
}

int main(){
    primeRange(100, 200);
    return 0;
}