// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously 
// following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer 
// is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

// Do not modify the linked list.

// Example 1:
// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.

// Example 2:
// Input: head = [1,2], pos = 0
// Output: tail connects to node index 0
// Explanation: There is a cycle in the linked list, where tail connects to the first node.

// Example 3:
// Input: head = [1], pos = -1
// Output: no cycle
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

ListNode *detectCycle(ListNode *head) {
    if(head == nullptr || head->next == nullptr) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}
// Time Complexity: O(2N)
// Space Complexity: O(1)

int main(){
    // Test Case 1: Cycle starts at node with value 2
    // 3 -> 2 -> 0 -> -4
    //      ^---------|
    vector<int> nums1 = {3, 2, 0, -4};
    ListNode* head1 = convertArr2LL(nums1);
    ListNode* tail1 = head1;
    ListNode* cycleStart1 = head1->next; // node 2
    while(tail1->next != nullptr) {
        tail1 = tail1->next;
    }
    tail1->next = cycleStart1;
    ListNode* ans1 = detectCycle(head1);
    cout << "Cycle Start 1 : "<< (ans1 ? ans1->val : -1) << endl;


    // Test Case 2: Cycle starts at head
    // 1 -> 2
    // ^----|
    vector<int> nums2 = {1, 2};
    ListNode* head2 = convertArr2LL(nums2);
    ListNode* tail2 = head2;
    while(tail2->next != nullptr) {
        tail2 = tail2->next;
    }
    tail2->next = head2;
    ListNode* ans2 = detectCycle(head2);
    cout << "Cycle Start 2 : "<< (ans2 ? ans2->val : -1) << endl;

    // Test Case 3: No cycle
    vector<int> nums3 = {1};
    ListNode* head3 = convertArr2LL(nums3);
    ListNode* ans3 = detectCycle(head3);
    cout << "Cycle Start 3 : "<< (ans3 ? ans3->val : -1) << endl;

    return 0;
}