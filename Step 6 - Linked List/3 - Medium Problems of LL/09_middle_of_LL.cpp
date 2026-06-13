// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.

// Example 2:
// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

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

ListNode* middleNode(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
// Time Complexity: O(N/2)
// Space Complexity: O(1)

int main(){
    vector<int> nums1 = {1, 2, 3, 4, 5};
    ListNode* head1 = convertArr2LL(nums1);
    cout << "Linked List 1 : ";
    printLL(head1);
    ListNode* middle1 = middleNode(head1);
    cout << "Middle Node : " << middle1->val << endl;

    vector<int> nums2 = {1, 2, 3, 4, 5, 6};
    ListNode* head2 = convertArr2LL(nums2);
    cout << "Linked List 2 : ";
    printLL(head2);
    ListNode* middle2 = middleNode(head2);
    cout << "Middle Node : " << middle2->val << endl;

    vector<int> nums3 = {10};
    ListNode* head3 = convertArr2LL(nums3);
    cout << "Linked List 3 : ";
    printLL(head3);
    ListNode* middle3 = middleNode(head3);
    cout << "Middle Node : " << middle3->val << endl;
    return 0;
}