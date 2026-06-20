#include<bits/stdc++.h>
using namespace std;

string prefixToInfix(string s) {
    int n = s.size();
    int i = n-1;
    stack<string> st;
    while(i >= 0){
        if(isalnum(s[i])) st.push(string(1, s[i]));     // create one occurence of s[i]
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string newTop = "(" + t1 + s[i] + t2 + ")";
            st.push(newTop);
        }
        i--;
    }
    return st.top();
}

int main() {

    vector<string> testCases = {
        "+ab",
        "*+abc",
        "+a*bc",
        "-+a*bcd",
        "*+ab-cd",
        "+A/Bc",
        "^ab",
        "^a^bc",
        "-/*ab+cd^ef",
        "+*ABC",
        "/+ab*cd",
        "*-A/BC-/AKL"
    };

    for(string expr : testCases) {

        cout << "Prefix Expression : " << expr << endl;

        cout << "Infix Expression  : "
             << prefixToInfix(expr) << endl;

        cout << "----------------------------------" << endl;
    }

    return 0;
}