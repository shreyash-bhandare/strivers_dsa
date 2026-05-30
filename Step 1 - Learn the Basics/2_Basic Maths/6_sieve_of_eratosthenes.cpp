#include<bits/stdc++.h>
using namespace std;

vector<int> isPrime(int n){
    vector<int> prime(n+1, 1);                          // O(N)
    for(int i = 2; i*i <= n; i++){                      // for 25, it should only check till 5, all 7 multiples are already marked. optm 2
        if(prime[i] == 1){
            for(int j = i*i; j <= n; j += i){           // to find multiples of current number. optm 1
                prime[j] = 0;
            }
        }
    }                                                   // takes O(N*log(log(N))) time complexity.
    return prime;
}

// total time complexity: O(N) + O(N*log(log(N))) + O(N)(for printing)

int main(){
    int a;
    cout<<"Enter a number: ";
    cin>>a;

    vector<int> ans = isPrime(a);
    vector<int> mark(ans.size() - 2);
    for(int i = 2; i < ans.size(); i++){
        cout<< i <<": "<<ans[i]<<endl;
    }

    return 0;
}