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

Node* deleteKthElement(Node* head, int k){
    if(head == nullptr) return head;    // if LL is empty
    if(k == 1){                         // if k = 1
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* prev = nullptr;
    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        if(cnt == k){
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> nums = {12,3,4,7};
    Node* head = convertArr2LL(nums);
    // cout<<head->data;
    // traversal in linked list to print.
    cout<<"Linked List before deleting k th element: ";
    print(head);
    cout<<"Linked List after deleting k th element: ";
    head = deleteKthElement(head, 3);
    print(head);
}