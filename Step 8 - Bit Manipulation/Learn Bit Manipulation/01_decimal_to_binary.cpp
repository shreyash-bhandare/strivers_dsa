#include<bits/stdc++.h>
using namespace std;

string convert2binary(int x){
    string result = "";
    while(x != 0){
        if(x % 2 == 1) result += "1";
        else result += "0";
        x = x/2;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    int num = 13;
    cout << "The number is: " << num << " and binary representation is: " << convert2binary(num) << endl;

    num = 25;
    cout << "The number is: " << num << " and binary representation is: " << convert2binary(num) << endl;

    num = 100;
    cout << "The number is: " << num << " and binary representation is: " << convert2binary(num) << endl;
    return 0;
}