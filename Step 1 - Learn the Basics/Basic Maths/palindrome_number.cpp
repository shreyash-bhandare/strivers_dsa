#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long lastNum = 0;
        int dup = x;
        while (dup > 0) {
            lastNum = (lastNum * 10) + dup % 10;
            dup = dup / 10;
        }
        return (lastNum == x);
    }
};

int main() {
    Solution sol;
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if (sol.isPalindrome(num)) {
        cout << num << " is a Palindrome!" << endl;
    } else {
        cout << num << " is NOT a Palindrome!" << endl;
    }

    return 0;
}