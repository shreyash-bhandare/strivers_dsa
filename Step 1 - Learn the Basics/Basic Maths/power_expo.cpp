#include<bits/stdc++.h>
using namespace std;

// both base and expo are positive:
/*int power(int base, int expo){
    int ans = 1;
    while(expo > 0){
        if(expo % 2 == 1){
            expo--;
            ans = ans* base;
        }
        expo /= 2;
        base *= base;
    }
    return ans;
}
*/

// for negative exponential.

double power(double base, int expo){
    double ans = 1;
    int nexpo = expo;
    if(expo < 0){
        expo = abs(expo);
    }
    while(expo > 0){
        if(expo % 2 == 1){
            expo--;
            ans = ans* base;
        }
        expo /= 2;
        base *= base;
    }
    if(nexpo < 0) return 1.0/ans;
    return ans;
}

// the time complexity will be: O(log2(N))
// the space complexity will be: O(1)

int main(){
    double a;
    int b;
    cout<<"Enter the base: ";
    cin>>a;
    cout<<"Enter the expo: ";
    cin>>b;
    cout<<power(a, b);
    return 0;
}