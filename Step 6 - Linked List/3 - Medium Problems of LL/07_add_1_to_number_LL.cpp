// Given the head of a singly linked list representing a positive integer number. 
// Each node of the linked list represents a digit of the number, 
// with the 1st node containing the leftmost digit of the number and so on. 
// The task is to add one to the value represented by the linked list and 
// return the head of a linked list containing the final value.

// The number will contain no leading zeroes except when the value represented is zero itself.

// Example 1
// Input: head -> 1 -> 2 -> 3
// Output: head -> 1 -> 2 -> 4
// Explanation: The number represented by the linked list = 123.
// 123 + 1 = 124.

// Example 2
// Input: head -> 9 -> 9
// Output: head -> 1 -> 0 -> 0
// Explanation: The number represented by the linked list = 99.
// 99 + 1 = 100.

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

int findCarry(ListNode* temp){
    if(temp == nullptr) return 1;
    int carry = findCarry(temp->next);
    temp->val = temp->val + carry;
    if(temp->val < 10){
        return 0;
    }
    temp->val = 0;
    return 1;
}

ListNode *addOne(ListNode *head) {
    int carry = findCarry(head);
    if(carry == 1){
        ListNode* newHead = new ListNode(1);
        newHead->next = head;
        return newHead;
    }
    return head;
}
// Time Complexity: O(N)
// Space Complexity: O(N)

int main(){
    vector<int> nums1 = {1, 2, 3};
    ListNode* head1 = convertArr2LL(nums1);
    cout << "Linked List 1 : ";
    printLL(head1);
    head1 = addOne(head1);
    cout << "After Adding One : ";
    printLL(head1);

    vector<int> nums2 = {1, 2, 9};
    ListNode* head2 = convertArr2LL(nums2);
    cout << "Linked List 2 : ";
    printLL(head2);
    head2 = addOne(head2);
    cout << "After Adding One : ";
    printLL(head2);

    vector<int> nums3 = {9, 9, 9};
    ListNode* head3 = convertArr2LL(nums3);
    cout << "Linked List 3 : ";
    printLL(head3);
    head3 = addOne(head3);
    cout << "After Adding One : ";
    printLL(head3);

    return 0;
}