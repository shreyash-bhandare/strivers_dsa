#include<bits/stdc++.h>
using namespace std;

// class MyQueue {
// public:
//     // APPROACH 1: MAKE PUSH EXPENSIVE (USED WHERE PUSH OPERATIONS ARE LESS)
//     // assume stacks like this:
//     stack<int> st1;     // 4 3 1
//     stack<int> st2;     // _ _ _
//     MyQueue() {
        
//     }
    
//     void push(int x) {
//         // putting all from st1 to st2
//         while(!st1.empty()){    // st2: 1 3 4
//             st2.push(st1.top());
//             st1.pop();
//         }
//         // push element
//         st1.push(x);            // st1: x
//         // putting all from st2 to st1
//         while(!st2.empty()){    // st1: x 4 3 1
//             st1.push(st2.top());
//             st2.pop();
//         }
//     }
    
//     int pop() {
//         int topElement = st1.top();
//         st1.pop();
//         return topElement;
//     }
    
//     int peek() {
//         return st1.top();
//     }
    
//     bool empty() {
//         return st1.empty();
//     }
// };

class MyQueue {
public:
    // APPROACH 2: MAKE POP AND TOP EXPENSIVE (USED WHERE PUSH OPERATIONS ARE MORE)
    // assume stacks like this:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        // if(!st2.empty()){
        //     int frontElement = st2.top();
        //     st2.pop();
        //     return frontElement;
        // }
        // else{
        //     while(!st1.empty()){
        //         st2.push(st1.top());
        //         st1.pop();
        //     }
        //     int frontElement = st2.top();
        //     st2.pop();
        //     return frontElement;
        // }
        // converting above code into below:
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int frontElement = st2.top();
        st2.pop();
        return frontElement;
    }
    
    int peek() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int frontElement = st2.top();
        return frontElement;
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

int main(){
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl; // 10

    cout << "Popped: " << q.pop() << endl; // 10
    cout << "Front element: " << q.peek() << endl; // 20

    q.push(40);

    cout << "Popped: " << q.pop() << endl; // 20
    cout << "Popped: " << q.pop() << endl; // 30
    cout << "Popped: " << q.pop() << endl; // 40

    cout << "Is queue empty? ";
    cout << (q.empty() ? "Yes" : "No") << endl;
    
    return 0;
}