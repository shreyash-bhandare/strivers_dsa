// Given the head of a singly linked list, group all the nodes with odd indices together 
// followed by the nodes with even indices, and return the reordered list.

// The first node is considered odd, and the second node is even, and so on.

// Note that the relative order inside both the even and odd groups should remain as it was in the input.

// You must solve the problem in O(1) extra space complexity and O(n) time complexity

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]

// Example 2:
// Input: head = [2,1,3,5,6,4,7]
// Output: [2,3,6,7,1,5,4]

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

ListNode* oddEvenList(ListNode* head) {
    if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;
    ListNode* odd = head, *even = head->next, *evenHead = even;
    while(even != nullptr && even->next != nullptr){    // for odd nodes and even nodes resp.
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
// Time Complexity: O(N) not O(N/2) as two operations are happening. So, O(N/2) * 2 = O(N)
// Space Complexity: O(1)

int main(){
    vector<int> nums1 = {2,1,3,5,6,4,7};
    ListNode* head = convertArr2LL(nums1);
    cout<<"Linked List 1 : ";
    printLL(head);
    head = oddEvenList(head);
    cout<<"Answer Linked List: ";
    printLL(head);
}