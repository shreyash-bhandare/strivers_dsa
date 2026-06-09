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

Node* deleteTail(Node* head){
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node* temp = head;
    while(temp->next->next != nullptr) temp = temp->next;
    delete temp->next;            // or use free(temp)
    temp->next = nullptr;    
    return head;
}

int main(){
    vector<int> nums = {12,3,4,7};
    Node* head = convertArr2LL(nums);
    // cout<<head->data;
    // traversal in linked list to print.
    cout<<"Linked List before deleting tail: ";
    print(head);
    head = deleteTail(head);
    cout<<"Linked List after deleting tail: ";
    print(head);
    return 0;
}