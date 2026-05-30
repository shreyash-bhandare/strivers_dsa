#include<bits/stdc++.h>
using namespace std;

// brute force:
/*int gcd(int n1, int n2){
    int num = 1;
    for(int i = 1; i < min(n1, n2); i++){
        if(n1 % i == 0 and n2 % i == 0) num = i;
    }
    return num;
}
// takes O(min(n1, n2)) time complexity.*/

// euclidean algorithm

int gcd(int a, int b){
    while(a > 0 and b > 0){
        if(a > b) a = a % b;
        else b = b % a;
    }
    if(a == 0) return b;
    else return a;
}

// time complexity: O(log(min(n1, n2)))

int main(){
    cout<<gcd(55, 10)<<endl;
    return 0;
}