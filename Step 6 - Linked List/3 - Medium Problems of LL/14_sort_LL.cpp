// Given the head of a linked list, return the list after sorting it in ascending order.

// Example 1:
// Input: head = [4,2,1,3]
// Output: [1,2,3,4]

// Example 2:
// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]

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

ListNode* findMiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* merge2SortedLists(ListNode* head1, ListNode* head2){
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;
    while(head1 != nullptr && head2 != nullptr){
        if(head1->val < head2->val){
            temp->next = head1;
            temp = head1;
            head1 = head1->next;
        }
        else{
            temp->next = head2;
            temp = head2;
            head2 = head2->next;
        }
    }
    if(head1) temp->next = head1;
    else temp->next = head2;
    return dummyNode->next;
}

ListNode* mergeForLL(ListNode* head){
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* middle = findMiddle(head);
    ListNode* leftHead = head, *rightHead = middle->next;
    middle->next = nullptr;
    leftHead = mergeForLL(leftHead);
    rightHead = mergeForLL(rightHead);
    return merge2SortedLists(leftHead, rightHead);
}

ListNode* sortList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    return mergeForLL(head);
}
// Time Complexity: O((N+N/2) log N) N/2 for finding the middle and merge2SortedLists runs for log N times.
// Space Complexity: O(log N) for recursive stack space.

int main(){
    vector<int> nums1 = {4, 2, 1, 3};
    ListNode* head1 = convertArr2LL(nums1);
    cout << "Linked List 1 : ";
    printLL(head1);
    head1 = sortList(head1);
    cout << "Sorted Linked List 1 : ";
    printLL(head1);

    vector<int> nums2 = {-1, 5, 3, 4, 0};
    ListNode* head2 = convertArr2LL(nums2);
    cout << "Linked List 2 : ";
    printLL(head2);
    head2 = sortList(head2);
    cout << "Sorted Linked List 2 : ";
    printLL(head2);

    vector<int> nums3 = {5, 4, 3, 2, 1};
    ListNode* head3 = convertArr2LL(nums3);
    cout << "Linked List 3 : ";
    printLL(head3);
    head3 = sortList(head3);
    cout << "Sorted Linked List 3 : ";
    printLL(head3);

    vector<int> nums4 = {10};
    ListNode* head4 = convertArr2LL(nums4);
    cout << "Linked List 4 : ";
    printLL(head4);
    head4 = sortList(head4);
    cout << "Sorted Linked List 4 : ";
    printLL(head4);
    
    return 0;
}