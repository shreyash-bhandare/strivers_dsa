#include<bits/stdc++.h>
using namespace std;

int countDigits(int n){
    int count = 0;
    while(n > 0){
        n = n/10;
        count++;
    }
    return count;
}

/*
another way of doing this:
int count = (int)(log(n) + 1);
return count;
*/

int main(){
    int cn = countDigits(12432325);
    cout<<cn<<endl;
    return 0;
}

// the time complexity is: O(log10(N)) as it is divided by 10, for 2, it is O(log2(N)).