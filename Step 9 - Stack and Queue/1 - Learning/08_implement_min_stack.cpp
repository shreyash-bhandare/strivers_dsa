// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int value) pushes the element value onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

// Example 1:
// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]
// Output
// [null,null,null,null,-3,null,0,-2]
// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2

#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    MinStack() {
        
    }
    stack<pair<int, int>> st;
    void push(int value) {
        if(st.empty()) st.push({value, value});
        else st.push({value, min(value, st.top().second)});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return st.top().second;
    }
};

int main(){
    MinStack st;

    // Push elements
    st.push(5);
    cout << "Pushed: 5" << endl;
    cout << "Top: " << st.top() << endl;
    cout << "Min: " << st.getMin() << endl;
    cout << "-------------------" << endl;

    st.push(3);
    cout << "Pushed: 3" << endl;
    cout << "Top: " << st.top() << endl;
    cout << "Min: " << st.getMin() << endl;
    cout << "-------------------" << endl;

    st.push(7);
    cout << "Pushed: 7" << endl;
    cout << "Top: " << st.top() << endl;
    cout << "Min: " << st.getMin() << endl;
    cout << "-------------------" << endl;

    st.push(2);
    cout << "Pushed: 2" << endl;
    cout << "Top: " << st.top() << endl;
    cout << "Min: " << st.getMin() << endl;
    cout << "-------------------" << endl;

    // Pop elements
    st.pop();
    cout << "Popped one element" << endl;
    cout << "Top: " << st.top() << endl;
    cout << "Min: " << st.getMin() << endl;
    cout << "-------------------" << endl;

    st.pop();
    cout << "Popped one element" << endl;
    cout << "Top: " << st.top() << endl;
    cout << "Min: " << st.getMin() << endl;
    cout << "-------------------" << endl;

    st.pop();
    cout << "Popped one element" << endl;
    cout << "Top: " << st.top() << endl;
    cout << "Min: " << st.getMin() << endl;
    cout << "-------------------" << endl;

    st.pop();
    cout << "Popped last element" << endl;
    cout << "Min: " << st.getMin() << endl; // -1 because empty
    cout << "-------------------" << endl;

    return 0;
}