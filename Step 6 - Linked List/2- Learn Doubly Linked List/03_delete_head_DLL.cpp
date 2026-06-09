#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* prev;
    Node* next;

    public:
    // constructor 1
    Node(int val1, Node*prev1, Node*next1){
        val = val1;
        prev = prev1;
        next = next1;
    }

    public:
    // constructor 2
    Node(int val1){
        val = val1;
        prev = nullptr;
        next = nullptr;
    }
};

Node* convertArr2DLL(vector<int> &nums){
    Node* head = new Node(nums[0]);
    Node* prev = head;
    for(int i = 1; i < nums.size(); i++){
        Node* temp = new Node(nums[i], prev, nullptr);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void printDLL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* deleteHead(Node* head){
    if(head == nullptr) return head;
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }
    Node* temp = head;
    head = temp->next;
    head->prev = nullptr;
    delete temp;
    return head;
}

int main(){
    vector<int> nums = {3,2,5,6,1,2,8};    
    Node* head = convertArr2DLL(nums);
    cout<<"Linked List before deleting head: ";
    printDLL(head);
    head = deleteHead(head);
    cout<<"Linked List after deleting head: ";
    printDLL(head);
    return 0;
}