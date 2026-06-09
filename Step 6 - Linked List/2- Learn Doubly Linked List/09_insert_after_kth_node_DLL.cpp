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

Node* insertAfterKthNode(Node* head, int k, int val){
    if(head == nullptr) return head;
    Node* temp = head;
    Node* prev = head;
    int cnt = 1;
    while(temp != nullptr){
        if(cnt == k){
            temp->next = new Node(val, prev, temp->next);   
            break; 
        }
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    return head;
}

int main(){
    vector<int> nums = {3,2,5,6,1,2,8};
    int k = 5;
    int val = 9;
    Node* head = convertArr2DLL(nums);
    cout<<"Linked List before inserting before "<<k<<"th node: ";
    printDLL(head);
    head = insertAfterKthNode(head, k, val);
    cout<<"Linked List after inserting before "<<k<<"th node: ";
    printDLL(head);
    return 0;
}