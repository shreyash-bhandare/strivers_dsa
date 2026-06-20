#include<bits/stdc++.h>
using namespace std;

string reverseString(string s){

    reverse(s.begin(), s.end());

    for(char &c : s){
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }

    return s;
}

int priority(char c){
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    return -1;
}

string infixToPrefix(string s) {

    // Step 1: Reverse and swap brackets
    s = reverseString(s);

    stack<char> st;
    string ans = "";

    for(char ch : s){

        // Operand
        if(isalnum(ch)){
            ans += ch;
        }

        // Opening bracket
        else if(ch == '('){
            st.push(ch);
        }

        // Closing bracket
        else if(ch == ')'){

            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }

            if(!st.empty())
                st.pop(); // remove '('
        }

        // Operator
        else{

            while(!st.empty() &&
                  st.top() != '(' &&
                  (
                    priority(ch) < priority(st.top()) ||                // this condition is to make sure +,- are not pushed on *,/,^.
                    (priority(ch) == priority(st.top()) && ch == '^')   // this condition is to avoid 2 '^' operators in stack.
                  )){

                ans += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    // Pop remaining operators
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    // Step 2: Reverse postfix to get prefix
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {

    vector<string> testCases = {
        "a+b",
        "a+b*c",
        "(a+b)*c",
        "a+b*c-d/e",
        "a*(b+c)",
        "(a+b)*(c-d)",
        "a+b*(c^d-e)^(f+g*h)-i",
        "A+B",
        "((a+b))",
        "a+b-c",
        "a*b+c/d",
        "a^b^c",
        "(A-B/C)*(A/K-L)"
    };

    for(string expr : testCases) {

        cout << "Infix Expression  : " << expr << endl;
        cout << "Prefix Expression : "
             << infixToPrefix(expr) << endl;

        cout << "----------------------------------" << endl;
    }

    return 0;
}