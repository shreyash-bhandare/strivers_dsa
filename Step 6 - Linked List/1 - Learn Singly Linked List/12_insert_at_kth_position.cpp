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

Node* insertKthPosition(Node* head, int k, int val){
    if(head == NULL) return head;
    if(k == 1){
        Node* temp = new Node(val, head->next);
        head->next = temp;
        return head;
    }
    Node* temp = head;
    Node* prev = nullptr;
    int cnt = 0;
    while(temp != nullptr){
        prev = temp;
        temp = temp->next;
        cnt++;
        if(cnt == k){
            prev->next = new Node(val, temp);
            break;
        }
    }
    return head;
}

int main(){
    vector<int> nums = {12,3,4,7};
    Node* head = convertArr2LL(nums);
    // cout<<head->data;
    // traversal in linked list to print.
    int val = 9;
    int k = 2;
    cout<<"Linked List before inserting value "<<val<<" after "<<k<<"th position: ";
    print(head);
    cout<<"Linked List after inserting after "<<k<<"th position: ";
    head = insertKthPosition(head, k, val);
    print(head);
}