#include <bits/stdc++.h>
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

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if(isPrime(num))
        cout << num << " is Prime" << endl;
    else
        cout << num << " is Not Prime" << endl;

    return 0;
}
