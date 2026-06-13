// Given the head of a singly linked list, reverse the list, and return the reversed list.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

// Example 2:
// Input: head = [1,2]
// Output: [2,1]

// Example 3:
// Input: head = []
// Output: []

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

// iterative solution
// ListNode* reverseList(ListNode* head) {
//     if(head == nullptr || head->next == nullptr) return head;
//     ListNode* temp = head;
//     ListNode* prev = nullptr;
//     while(temp != nullptr){
//         ListNode* front = temp->next;
//         temp->next = prev;
//         prev = temp;
//         temp = front;
//     }
//     return prev;
// }

// Time Complexity: O(N)
// Space Complexity: O(1)

// recursive solution
ListNode* reverseList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* newHead = reverseList(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

// Time Complexity: O(N)
// Space Complexity: O(1)

int main(){
    vector<int> nums1 = {1, 2, 3, 4, 5};
    ListNode* head1 = convertArr2LL(nums1);
    cout << "Linked List 1 : ";
    printLL(head1);
    head1 = reverseList(head1);
    cout << "Reversed Linked List 1 : ";
    printLL(head1);
    cout << endl;

    vector<int> nums2 = {10};
    ListNode* head2 = convertArr2LL(nums2);
    cout << "Linked List 2 : ";
    printLL(head2);
    head2 = reverseList(head2);
    cout << "Reversed Linked List 2 : ";
    printLL(head2);
    cout << endl;

    vector<int> nums3 = {7, 8};
    ListNode* head3 = convertArr2LL(nums3);
    cout << "Linked List 3 : ";
    printLL(head3);
    head3 = reverseList(head3);
    cout << "Reversed Linked List 3 : ";
    printLL(head3);
    cout << endl;

    vector<int> nums4 = {11, 22, 33, 44, 55, 66};
    ListNode* head4 = convertArr2LL(nums4);
    cout << "Linked List 4 : ";
    printLL(head4);
    head4 = reverseList(head4);
    cout << "Reversed Linked List 4 : ";
    printLL(head4);
}