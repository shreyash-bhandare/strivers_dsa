#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node():data(0), next(nullptr){};
    Node(int data1): data(data1), next(nullptr){};
    Node(int data1, Node* next1): data(data1), next(next1){};
};

class LinkedListStack {
public:
    Node* topElement;
    int size;
    LinkedListStack() {
        topElement = nullptr;
        size = 0;
    }
    
    void push(int x) {
        Node* temp = new Node(x);
        temp->next = topElement;
        topElement = temp;
        size++;
    }
    
    int pop() {
        if (topElement == nullptr) return -1;
        Node* temp = topElement;
        topElement = topElement->next;
        int dataToReturn = temp->data;
        delete temp;
        size--;
        return dataToReturn;
    }
    
    int top() {
        if (topElement == nullptr) return -1;
        return topElement->data;
    }
    
    bool isEmpty() {
        return size == 0;
    }
};

int main(){
    LinkedListStack st;

    // Test isEmpty on empty stack
    cout << "Is Empty: " << boolalpha<<st.isEmpty() << endl; // (true)

    // Test push
    st.push(10);
    st.push(20);
    st.push(30);

    // Test top
    cout << "Top Element: " << st.top() << endl; // 30

    // Test pop
    cout << "Popped: " << st.pop() << endl; // 30
    cout << "Top Element: " << st.top() << endl; // 20

    cout << "Popped: " << st.pop() << endl; // 20
    cout << "Top Element: " << st.top() << endl; // 10

    // Test isEmpty after some pops
    cout << "Is Empty: " << st.isEmpty() << endl; // 0 (false)

    cout << "Popped: " << st.pop() << endl; // 10

    // Test isEmpty after removing all elements
    cout << "Is Empty: " << st.isEmpty() << endl; // 1 (true)

    return 0;
}