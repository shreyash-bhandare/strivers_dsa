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

ListNode* sortList(ListNode* &head) {
    ListNode* zeroHead = new ListNode(-1);
    ListNode* oneHead = new ListNode(-1);
    ListNode* twoHead = new ListNode(-1);
    ListNode* zero = zeroHead;
    ListNode* one = oneHead;
    ListNode* two = twoHead;
    ListNode* temp = head;
    while(temp != nullptr){
        if(temp->val == 0){
            zero->next = temp;
            zero = temp;
        }
        else if(temp->val == 1){
            one->next = temp;
            one = temp;
        }
        else{
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    temp = head;

    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;

    ListNode* newHead = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}
// Time Complexity: O(N)
// Space Complexity: O(1)

int main(){
    vector<int> nums1 = {1,0,2,0,1};
    ListNode* head = convertArr2LL(nums1);
    cout<<"Linked List 1 : ";
    printLL(head);
    head = sortList(head);
    cout<<"Sorted Linked List: ";
    printLL(head);

    vector<int> nums2 = {2, 2, 1, 1, 0, 0};
    ListNode* head2 = convertArr2LL(nums2);
    cout << "Linked List 2 : ";
    printLL(head2);
    head2 = sortList(head2);
    cout << "Sorted Linked List 2 : ";
    printLL(head2);

    vector<int> nums3 = {2, 0, 1, 2, 1, 0, 2, 0};
    ListNode* head3 = convertArr2LL(nums3);
    cout << "Linked List 3 : ";
    printLL(head3);
    head3 = sortList(head3);
    cout << "Sorted Linked List 3 : ";
    printLL(head3);
}