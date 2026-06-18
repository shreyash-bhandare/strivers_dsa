#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        int size = q.size();
        q.push(x);
        for(int i = 0; i < size; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(q.empty()) return -1;
        int frontElement = q.front();
        q.pop();
        return frontElement;
    }
    
    int top() {
        if(q.empty()) return -1;
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

int main(){
    MyStack st;

    cout << "Empty: " << boolalpha << st.empty() << endl;   // 1
    cout << "Top: " << st.top() << endl;       // -1
    cout << "Pop: " << st.pop() << endl;       // -1

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;       // 30

    cout << st.pop() << endl;                  // 30
    cout << st.pop() << endl;                  // 20

    st.push(40);

    cout << st.top() << endl;                  // 40
    cout << st.pop() << endl;                  // 40
    cout << st.pop() << endl;                  // 10

    cout << "Empty: " << boolalpha << st.empty() << endl;   // 1
    return 0;
}