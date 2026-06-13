// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. 
// Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example 1:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// Example 2:
// Input: l1 = [0], l2 = [0]
// Output: [0]

// Example 3:
// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;

    public:
    // constructor 1
    ListNode(int val1, ListNode* next1){
        val = val1;
        next = next1;
    }

    public:
    // constructor 2
    ListNode(int val1){
        val = val1;
        next = nullptr;
    }
};

ListNode* convertArr2LL(vector<int> &nums){
    ListNode* head = new ListNode(nums[0]);     // constructor 2 will create this.
    ListNode* mover = head;
    for(int i = 1; i < nums.size(); i++){
        ListNode* temp = new ListNode(nums[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(ListNode* head){
    ListNode* temp = head;
    while(temp != nullptr){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* t1 = l1;
    ListNode* t2 = l2;
    ListNode* dummyNode = new ListNode(-1);
    ListNode* curr = dummyNode;
    int carry = 0;
    while(t1 != nullptr || t2 != nullptr){
        int sum = carry;
        if(t1) sum += t1->val;
        if(t2) sum += t2->val;
        ListNode* newNode = new ListNode(sum%10);
        carry = sum/10;
        curr->next = newNode;
        curr = curr->next;
        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
    }
    if(carry == 1){
        ListNode* newNode = new ListNode(carry);
        curr->next = newNode;
    }
    return dummyNode->next;
}
// Time Complexity: O(max(N1, N2))
// Space Complexity: O(max(N1, N2))

int main(){
    vector<int> nums1 = {2,3,4,7};
    vector<int> nums2 = {3,9,8,2};
    ListNode* head1 = convertArr2LL(nums1);
    ListNode* head2 = convertArr2LL(nums2);
    cout<<"Linked List 1 : ";
    printLL(head1);
    cout<<"Linked List 2 : ";
    printLL(head2);
    ListNode* head = addTwoNumbers(head1, head2);
    cout<<"Ans Linked List: ";
    printLL(head);
}