#include<bits/stdc++.h>
using namespace std;

// struct Node{
//     public:
//     int data;
//     Node* next;

//     public:
//     Node(int data1, Node* next1){
//         data = data1;
//         next = next1;
//     }

//     public:
//     Node(int data1){
//         data = data1;
//         next = nullptr;
//     }
// };

class Node{
    public:
    int data;
    Node* next;

    public:
    // constructor 1
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    // constructor 2
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

int main(){
    vector<int> arr = {2,5,8,7};
    // 1) printing data and next
    Node* x = new Node(arr[0], nullptr);
    cout<<x<<endl;
    cout<<"The data is : "<<x->data<<" and the next is: "<<x->next<<endl;
    // 2) printing data and next
    Node y = Node(arr[1], x);
    cout<<"The data is : "<<y.data<<" and the next is: "<<y.next<<endl;
    // 3) not passing nullptr
    Node z = Node(arr[1], nullptr);
    cout<<"The data is : "<<z.data<<" and the next is: "<<z.next<<endl;
    return 0;
}