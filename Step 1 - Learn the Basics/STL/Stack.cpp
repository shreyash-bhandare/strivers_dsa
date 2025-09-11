#include<bits/stdc++.h>

using namespace std;

void explainStack(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.emplace(3);
    cout<< st.top();
    cout<<endl;
    st.pop();
    cout<< st.top();
    cout<<endl;
    cout<< st.size();
    cout<<endl;
    cout<< st.empty();
    cout<<endl;
    // can also swap stacks:
    // stack<int> st2;
    // st.swap(st2);
}

int main(){
    explainStack();
    return 0;
}