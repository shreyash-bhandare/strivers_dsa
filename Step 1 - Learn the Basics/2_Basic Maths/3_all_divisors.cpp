#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> divisors(int n) {
        vector<int> div;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                div.push_back(i);
                if (i != n / i) {  // avoid duplicate when i == sqrt(n)
                    div.push_back(n / i);
                }
            }
        }
        sort(div.begin(), div.end());  // sort the divisors
        return div;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> ans = sol.divisors(n);

    cout << "Divisors of " << n << " are: ";
    for (int d : ans) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
