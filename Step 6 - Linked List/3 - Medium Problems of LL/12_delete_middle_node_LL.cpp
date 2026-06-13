// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Example 1:
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

// Example 2:
// Input: head = [1], n = 1
// Output: []

// Example 3:
// Input: head = [1,2], n = 1
// Output: [1]

// Given the head of a singly linked list consisting of only 0, 1 or 2.
// Sort the given linked list and return the head of the modified list.
// Do it in-place by changing the links between the nodes without creating new nodes.

// Example 1
// Input: linkedList = [1, 0, 2, 0 , 1]
// Output: [0, 0, 1, 1, 2]
// Explanation: The values after sorting are [0, 0, 1, 1, 2].

// Example 2
// Input: linkedList = [1, 1, 1, 0]
// Output: [0, 1, 1, 1]
// Explanation: The values after sorting are [0, 1, 1, 1].

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

ListNode* deleteMiddle(ListNode* head) {
    if(head == nullptr) return nullptr;
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    fast = fast->next->next;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;
}
// Time Complexity: O(N/2)
// Space Complexity: O(1)

int main(){
    // Test Case 1: Odd length list
    vector<int> nums1 = {1, 2, 3, 4, 5};
    ListNode* head1 = convertArr2LL(nums1);
    cout << "Linked List 1 : ";
    printLL(head1);
    head1 = deleteMiddle(head1);
    cout << "After Deleting Middle : ";
    printLL(head1);

    // Test Case 2: Even length list
    vector<int> nums2 = {1, 2, 3, 4, 5, 6};
    ListNode* head2 = convertArr2LL(nums2);
    cout << "Linked List 2 : ";
    printLL(head2);
    head2 = deleteMiddle(head2);
    cout << "After Deleting Middle : ";
    printLL(head2);

    // Test Case 3: Single node list
    vector<int> nums3 = {10};
    ListNode* head3 = convertArr2LL(nums3);
    cout << "Linked List 3 : ";
    printLL(head3);
    head3 = deleteMiddle(head3);
    cout << "After Deleting Middle : ";
    printLL(head3);

    return 0;
}