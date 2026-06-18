// Implement a Last-In-First-Out (LIFO) stack using an array. The implemented stack should support the following 
// operations: push, pop, peek, and isEmpty.

// Implement the ArrayStack class:

// void push(int x): Pushes element x onto the stack.
// int pop(): Removes and returns the top element of the stack.
// int top(): Returns the top element of the stack without removing it.
// boolean isEmpty(): Returns true if the stack is empty, false otherwise.

// Please note that this section might seem a bit difficult without prior knowledge on what stacks is, 
// we will soon try to add basics concepts for your ease! If you know the concepts already please go ahead to 
// give a shot to the problem. Cheers!

// Example 1
// Input: ["ArrayStack", "push", "push", "top", "pop", "isEmpty"]
// [[], [5], [10], [], [], []]
// Output: [null, null, null, 10, 10, false]
// Explanation:
// ArrayStack stack = new ArrayStack();
// stack.push(5);
// stack.push(10);
// stack.top(); // returns 10
// stack.pop(); // returns 10
// stack.isEmpty(); // returns false

// Example 2
// Input: ["ArrayStack","isEmpty", "push", "pop", "isEmpty"]
// [[], [], [1], [], []]
// Output: [null, true, null, 1, true]
// Explanation: 
// ArrayStack stack = new ArrayStack();
// stack.push(1);
// stack.pop(); // returns 1
// stack.isEmpty(); // returns true

#include<bits/stdc++.h>
using namespace std;

class ArrayStack {
public:
    int topIndex;
    static const int max_size = 100;
    int st[max_size];

    ArrayStack() {
        topIndex = -1;
    }

    void push(int x) {
        if (topIndex >= max_size - 1)
            return;
        st[++topIndex] = x;
    }

    int pop() {
        if (topIndex == -1)
            return -1;
        return st[topIndex--];
    }

    int top() {
        if (topIndex == -1)
            return -1;
        return st[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

int main(){
    ArrayStack stack;

    stack.push(5);

    stack.push(10);

    cout<<stack.top()<<endl; // returns 10

    cout<<stack.pop()<<endl; // returns 10

    cout<<stack.isEmpty()<<endl; // returns false
    return 0;
}