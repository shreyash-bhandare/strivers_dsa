#include<bits/stdc++.h>
using namespace std;

string postToInfix(string s) {
    int n = s.size();
    int i = 0;
    stack<string>st;
    while(i < n){
        if(isalnum(s[i])) st.push(string(1, s[i]));     // create one occurence of s[i].
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string newTop = "(" + t2 + s[i] + t1 + ")";
            st.push(newTop);
        }
        i++;
    }
    return st.top();
}

int main() {

    vector<string> testCases = {
        "ab+",
        "abc*+",
        "ab+c*",
        "abc*+de/-",
        "abc+*",
        "ab+cd-*",
        "abcd^e-fgh*+^*+i-",
        "AB+",
        "ab+",
        "ab+c-",
        "ab*cd/+",
        "abc^^"
    };

    for(string expr : testCases) {

        cout << "Postfix Expression : " << expr << endl;
        cout << "Infix Expression   : "
             << postToInfix(expr) << endl;

        cout << "----------------------------------" << endl;
    }

    return 0;
}