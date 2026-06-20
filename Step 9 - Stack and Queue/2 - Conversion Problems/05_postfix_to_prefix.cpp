#include<bits/stdc++.h>
using namespace std;

string postToPre(string s) {
    int n = s.size();
    int i = 0;
    stack<string>st;
    while(i < n){
        if(isalnum(s[i])) st.push(string(1, s[i]));     // create one occurence of s[i]
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string newTop = s[i] + t2 + t1;
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
        "ab+c-",
        "ab*cd/+",
        "abc^^",
        "ABC*+D-",
        "ab/cd+*",
        "ab+cd+*"
    };

    for(string expr : testCases) {

        cout << "Postfix Expression : " << expr << endl;

        cout << "Prefix Expression  : "
             << postToPre(expr) << endl;

        cout << "----------------------------------" << endl;
    }

    return 0;
}