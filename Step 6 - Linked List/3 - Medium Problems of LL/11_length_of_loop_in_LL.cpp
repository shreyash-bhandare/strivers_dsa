// Given the head of a singly linked list, find the length of the loop in the linked list if it exists. 
// Return the length of the loop if it exists; otherwise, return 0.

// A loop exists in a linked list if some node in the list can be reached again by continuously following 
// the next pointer. Internally, pos is used to denote the index (0-based) of the node from where the loop starts.

// Note that pos is not passed as a parameter.

// Example 1
// Input: head -> 1 -> 2 -> 3 -> 4 -> 5, pos = 1
// Output: 4
// Explanation: 2 -> 3 -> 4 -> 5 - >2, length of loop = 4.

// Example 2
// Input: head -> 1 -> 3 -> 7 -> 4, pos = -1
// Output: 0
// Explanation: No loop is present in the linked list.

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
    ListNode* head = new ListNode(nums[0]);
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

int findLengh(ListNode* slow, ListNode* fast){
    int cnt = 1; 
    fast = fast->next;
    while(slow != fast){
        fast = fast->next;
        cnt++;
    }
    return cnt;
}

int findLengthOfLoop(ListNode *head) {
    if(head == nullptr) return 0;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return findLengh(slow, fast);
    }
    return 0;
}
// Time Complexity: O(2N)
// Space Complexity: O(1)

int main(){
    vector<int> nums1 = {1, 2, 3, 4, 5};
    ListNode* head1 = convertArr2LL(nums1);

    ListNode* tail1 = head1;
    ListNode* node3 = head1->next->next;

    while(tail1->next != nullptr) {
        tail1 = tail1->next;
    }
    tail1->next = node3;
    cout << "Length of Loop 1 : "<< findLengthOfLoop(head1) << endl;


    // Test Case 2: Entire list forms a loop
    // 1 -> 2 -> 3 -> 4
    // ^--------------|
    vector<int> nums2 = {1, 2, 3, 4};
    ListNode* head2 = convertArr2LL(nums2);

    ListNode* tail2 = head2;
    while(tail2->next != nullptr) {
        tail2 = tail2->next;
    }
    tail2->next = head2;
    cout << "Length of Loop 2 : "<< findLengthOfLoop(head2) << endl;

    vector<int> nums3 = {10, 20, 30, 40};
    ListNode* head3 = convertArr2LL(nums3);
    cout << "Length of Loop 3 : "<< findLengthOfLoop(head3) << endl;

    return 0;
}