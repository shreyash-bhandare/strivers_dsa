#include<bits/stdc++.h>
using namespace std;

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

Node* convertArr2LL(vector<int> &nums){
    Node* head = new Node(nums[0]);     // constructor 2 will create this.
    Node* mover = head;
    for(int i = 1; i < nums.size(); i++){
        Node* temp = new Node(nums[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* insertTail(Node* head, int val){
    if(head == nullptr) return new Node(val);
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = new Node(val);
    return head;
}

int main(){
    vector<int> nums = {12,3,4,7};
    Node* head = convertArr2LL(nums);
    // cout<<head->data;
    // traversal in linked list to print.
    int val = 9;
    cout<<"Linked List before inserting value "<<val<<" at tail : ";
    print(head);
    cout<<"Linked List after inserting tail: ";
    head = insertTail(head, val);
    print(head);
}