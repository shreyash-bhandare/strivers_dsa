#include <bits/stdc++.h>
using namespace std;

bool isArmstrong(int n) {
    int x = n; 
    int arm = 0;
    string digits = to_string(n);
    int digitscount = digits.size();
    while(n > 0){
        arm = arm + (int)round(pow(n%10, digitscount));
        n /= 10;
    }
    return (x == arm);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if(isArmstrong(num)){
        cout<<"Armstrong";
    }
    else{
        cout<<"Not Armstrong";
    }
    return 0;
}