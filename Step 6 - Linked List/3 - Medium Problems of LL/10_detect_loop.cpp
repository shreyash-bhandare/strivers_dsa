// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously 
// following the next pointer. Internally, pos is used to denote the index of the node that 
// tail's next pointer is connected to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

// Example 1:
// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

// Example 2:
// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

// Example 3:
// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.

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

bool hasCycle(ListNode *head) {
    if(head == nullptr || head->next == nullptr) return false;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}
// Time Complexity: O(N)
// Space Complexity: O(1)

int main(){
    vector<int> nums1 = {3, 2, 0, -4};
    ListNode* head1 = convertArr2LL(nums1);
    ListNode* tail1 = head1;
    ListNode* node2 = head1->next;
    while(tail1->next != nullptr) {
        tail1 = tail1->next;
    }
    tail1->next = node2;
    cout << "Has Cycle 1 : "<< (hasCycle(head1) ? "True" : "False") << endl;

    vector<int> nums2 = {1, 2};
    ListNode* head2 = convertArr2LL(nums2);
    ListNode* tail2 = head2;
    while(tail2->next != nullptr) {
        tail2 = tail2->next;
    }
    tail2->next = head2;
    cout << "Has Cycle 2 : "<< (hasCycle(head2) ? "True" : "False") << endl;

    vector<int> nums3 = {1};
    ListNode* head3 = convertArr2LL(nums3);
    cout << "Has Cycle 3 : "<< (hasCycle(head3) ? "True" : "False") << endl;

    return 0;
}