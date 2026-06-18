// Implement a First-In-First-Out (FIFO) queue using an array. 
// The implemented queue should support the following operations: push, peek, pop, and isEmpty.

// Implement the ArrayQueue class:

// void push(int x): Adds element x to the end of the queue.
// int pop(): Removes and returns the front element of the queue.
// int peek(): Returns the front element of the queue without removing it.
// boolean isEmpty(): Returns true if the queue is empty, false otherwise.

// Example 1

// Input:
// ["ArrayQueue", "push", "push", "peek", "pop", "isEmpty"]
// [[], [5], [10], [], [], []]
// Output: [null, null, null, 5, 5, false]
// Explanation:
// ArrayQueue queue = new ArrayQueue();
// queue.push(5);
// queue.push(10);
// queue.peek(); // returns 5
// queue.pop(); // returns 5
// queue.isEmpty(); // returns false

// Example 2

// Input:
// ["ArrayQueue", "isEmpty"]
// [[]]
// Output:[null, true]
// Explanation:
// ArrayQueue queue = new ArrayQueue();
// queue.isEmpty(); // returns true

#include<bits/stdc++.h>
using namespace std;

class ArrayQueue {
public:
    static const int size = 100;
    int start, end, currSize;
    int q[size];
    ArrayQueue() {
        start = -1;
        end = -1;
        currSize = 0;
    }
    
    void push(int x) {
        if(currSize == size) return;
        if(currSize == 0){
            start = 0;
            end = 0;
        }
        else end = (end+1)%size;
        q[end] = x;
        currSize++;
    }
    
    int pop() {
        if(currSize == 0) return -1;
        int el = q[start];
        if(currSize == 1){
            start = -1;
            end = -1;
        }
        else{
            start = (start+1)%size;
        }
        currSize--;
        return el;
    }
    
    int peek() {
        if(currSize == 0) return -1;
        return q[start];
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
};

int main(){
    ArrayQueue queue;

    queue.push(5);
    queue.push(10);

    cout << "Peek: " << queue.peek() << endl;      // 5
    cout << "Pop: " << queue.pop() << endl;        // 5
    cout << "isEmpty: " << boolalpha << queue.isEmpty() << endl; // false
    return 0;
}