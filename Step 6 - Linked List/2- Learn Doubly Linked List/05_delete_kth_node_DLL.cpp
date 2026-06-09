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

Node* deleteKthNode(Node* head, int k){
    if(head == nullptr) return head;
    if(k == 1){
        delete head;
        return nullptr;
    }
    int cnt = 1;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        prev = temp;
        temp = temp->next;
        cnt++;
        if(cnt == k){
            temp->next->prev = temp->prev;
            prev->next = temp->next;
            delete temp;
        }
    }
    return head;
}

int main(){
    vector<int> nums = {3,2,5,6,1,2,8};
    int k = 5;
    Node* head = convertArr2DLL(nums);
    cout<<"Linked List before deleting "<<k<<"th node: ";
    printDLL(head);
    head = deleteKthNode(head, k);
    cout<<"Linked List after deleting "<<k<<"th node: ";
    printDLL(head);
    return 0;
}