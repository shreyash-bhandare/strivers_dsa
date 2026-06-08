#include<bits/stdc++.h>
using namespace std;

int convert2Decimal(string binary){
    int n = binary.size();
    int result = 0;
    int powerOf2 = 1;
    for(int i = n-1; i >= 0; i--){
        if(binary[i] == '1') result += powerOf2;
        powerOf2 *= 2;
    }
    return result;
}

int main(){
    string binary1 = "1101";
    cout << "The binary number is: " << binary1 << " and decimal representation is: " << convert2Decimal(binary1) << endl;

    string binary2 = "10101";
    cout << "The binary number is: " << binary2 << " and decimal representation is: " << convert2Decimal(binary2) << endl;

    string binary3 = "1100100";
    cout << "The binary number is: " << binary3 << " and decimal representation is: " << convert2Decimal(binary3) << endl;
    return 0;
}