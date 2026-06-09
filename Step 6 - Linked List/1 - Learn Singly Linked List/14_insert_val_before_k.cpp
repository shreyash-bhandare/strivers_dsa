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

Node* insertValBeforeK(Node* head, int k, int val){
    if(head == nullptr) return head;
    if(head->next->data == k){
        Node* temp = new Node(val, head->next);
        head->next = temp;
        return head;
    }
    Node* temp = head;
    while(temp->next->data != k){
        temp = temp->next;
    }
    temp->next = new Node(val, temp->next);
    return head;
}

int main(){
    vector<int> nums = {12,3,4,7};
    Node* head = convertArr2LL(nums);
    // cout<<head->data;
    // traversal in linked list to print.
    int val = 9;
    int k = 3;
    cout<<"Linked List before inserting after "<<k<<": ";
    print(head);
    cout<<"Linked List after inserting value "<<val<<" after value "<<k<<": ";
    head = insertValBeforeK(head, k, val);
    print(head);
}