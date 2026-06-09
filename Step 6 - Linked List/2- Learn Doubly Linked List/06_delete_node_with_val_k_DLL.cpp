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

Node* deleteNodeWithValK(Node* head, int k){
    if(head == nullptr) return head;
    if(head->val == k){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        prev = temp;
        temp = temp->next;
        if(temp->val == k){
            prev->next = temp->next;
            temp->next->prev = prev;
            delete temp;
            break;
        }
    }
    return head;
}

int main(){
    vector<int> nums = {3,2,5,6,1,2,8};
    int k = 6;
    Node* head = convertArr2DLL(nums);
    cout<<"Linked List before deleting after "<<k<<": ";
    printDLL(head);
    head = deleteNodeWithValK(head, k);
    cout<<"Linked List after deleting after "<<k<<": ";
    printDLL(head);
    return 0;
}