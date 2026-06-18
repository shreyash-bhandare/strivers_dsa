#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(): data(0), next(nullptr){};
    Node(int data1): data(data1), next(nullptr){};
    Node(int data1, Node* next1): data(data1), next(next1){};
};

class LinkedListQueue {
public:
    Node* start;
    Node* end;
    int size;
    LinkedListQueue() {
        start = nullptr;
        end = nullptr;
        size = 0;
    }
    
    void push(int x) {
        Node* temp = new Node(x);
        if(start == nullptr){
            start = end = temp;
        }
        else {
            end->next = temp;
            end = temp;
        }
        size++;
    }
    
    int pop() {
        if(start == nullptr) return -1;
        Node* temp = start;
        start = start->next;
        int dataToReturn = temp->data;
        delete temp;
        size--;
        return dataToReturn;
    }
    
    int peek() {
        if(start == nullptr) return -1;
        return start->data;
    }
    
    bool isEmpty() {
        return size == 0;
    }
};

int main(){
    LinkedListQueue q;

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl;

    cout << "Popped: " << q.pop() << endl;
    cout << "Popped: " << q.pop() << endl;

    cout << "Front element after popping: " << q.peek() << endl;

    q.push(40);

    while (!q.isEmpty()) {
        cout << "Popped: " << q.pop() << endl;
    }

    cout << "Queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    
    return 0;
}