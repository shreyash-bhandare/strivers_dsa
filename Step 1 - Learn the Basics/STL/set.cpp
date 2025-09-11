#include <bits/stdc++.h>
using namespace std;

void printSet(const set<int>& st) {
    for (int s : st) {
        cout << s << " ";
    }
    cout << endl;
}

void explainSet() {
    set<int> st;
    st.insert(3);
    st.emplace(5);
    st.insert(3);
    st.insert(2);
    printSet(st);

    auto it = st.find(3);
    if (it != st.end())
        cout << "it: " << *it << endl;
    else
        cout << "it: not found" << endl;

    auto it1 = st.find(4);
    if (it1 != st.end())
        cout << "it1: " << *it1 << endl;
    else
        cout << "it1: not found" << endl;

    st.erase(3);
    st.insert(3);
    st.insert(4);
    printSet(st);

    int cnt = st.count(3);
    cout << "count: " << cnt << endl;

    it1 = st.find(3);
    auto it2 = st.find(5);
    if (it1 != st.end() && it2 != st.end())
        st.erase(it1, it2);

    printSet(st);
}

int main() {
    explainSet();
    return 0;
}
