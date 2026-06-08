#include<bits/stdc++.h>
using namespace std;

int findRangeXOR(int l,int r){
    // finding till r
    if(r%4 == 1) r = 1;
    else if(r%4 == 2) r = r+1;
    else if(r%4 == 3) r = 0;
    else r = r;

    // finding till l-1
    l = l-1;
    if(l%4 == 1) l = 1;
    else if(l%4 == 2) l = l+1;
    else if(l%4 == 3) l = 0;
    else l = l;
    return l^r;
}

int main(){
    int l1 = 3, r1 = 7;
    cout << "The range is: [" << l1 << ", " << r1 << "]" << endl;
    cout << "The XOR of all numbers in the range is: " << findRangeXOR(l1, r1) << endl;

    int l2 = 1, r2 = 4;
    cout << "The range is: [" << l2 << ", " << r2 << "]" << endl;
    cout << "The XOR of all numbers in the range is: " << findRangeXOR(l2, r2) << endl;

    int l3 = 5, r3 = 10;
    cout << "The range is: [" << l3 << ", " << r3 << "]" << endl;
    cout << "The XOR of all numbers in the range is: " << findRangeXOR(l3, r3) << endl;
    return 0;
}