#include <iostream>
#include <climits> // for INT_MAX and INT_MIN
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int lastNum = 0;
        int lastDig = 0;
        while (x != 0) {
            lastDig = x % 10;
            if (lastNum > INT_MAX / 10 || lastNum < INT_MIN / 10) {
                return 0; // overflow case
            }
            lastNum = (lastNum * 10) + lastDig;
            x = x / 10;
        }
        return lastNum;
    }
};

int main() {
    Solution sol;
    int num;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Reversed number = " << sol.reverse(num) << endl;

    return 0;
}
