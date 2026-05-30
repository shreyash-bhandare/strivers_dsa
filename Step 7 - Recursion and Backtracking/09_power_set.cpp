#include<bits/stdc++.h>
using namespace std;

// 1<<2 means 100

void printSubstrings(string s){
    int n = s.size();
    for(int num = 0; num < (1<<n); num++){
        string sub = "";
        for(int i = 0; i < n; i++){
            if((num & (1<<i)) != 0) sub += s[i];        // check if that bit is set in particular number.
        }
        cout<<sub<<endl;
    }
}

int main(){
    string s = "abc";
    printSubstrings(s);
    return 0;
}