#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;

    int count = 0;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            count++;
            if(i != n / i) {
                count++;
            }
        }
    }
    return (count == 2);
}

/*vector<int> allDiv(int n){
    vector<int> ans;
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            if(isPrime(i)) ans.push_back(i);
            if(i != n/i){
                if(isPrime(n/i)) ans.push_back(n/i);
            }
        }
    }
    return ans;
}*/

// time complexity: O(sqrt(N)*2*sqrt(N))

vector<int> allDiv(int n){
    vector<int> ans;
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            if(isPrime(i)) ans.push_back(i);
        }
        while(n % i == 0){
            n /= i;
        }
    }
    if(n != 1) ans.push_back(n);
    return ans;
}

// takes time complexity: O(sqrt(N) * log(N)), sqrt(N) for when no. is prime and log(N) for division.

int main(){
    vector<int> ans = allDiv(780);
    for(auto a : ans){
        cout<<a<<" ";
    }
    return 0;
}