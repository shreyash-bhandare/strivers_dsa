// Given the head of a linked list, rotate the list to the right by k places.

// Example 1:
// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]

// Example 2:
// Input: head = [0,1,2], k = 4
// Output: [2,0,1]

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

ListNode* findNewLastNode(ListNode* head, int n){
    int newLast = 1;
    while(head != nullptr){
        if(newLast == n) return head;
        newLast++;
        head = head->next;
    }
    return head;
}

ListNode* rotateRight(ListNode* head, int k) {
    if(head == nullptr || head->next == nullptr) return head;
    int len = 1;
    ListNode* tail = head;
    while(tail->next != nullptr){
        len++;
        tail = tail->next;
    }
    if(k % len == 0) return head;
    tail->next = head;
    k = k % len;
    ListNode* newLastNode = findNewLastNode(head, len-k);
    head = newLastNode->next;
    newLastNode->next = nullptr;
    return head;
}
// Time Complexity: O(2N) = O(N) for finding the length and tail, O(N) for finding newLastNode
// Space Complexity: O(1)

int main(){
    vector<int> nums1 = {1, 2, 3, 4, 5};
    ListNode* head1 = convertArr2LL(nums1);
    cout << "Linked List 1 : ";
    printLL(head1);
    head1 = rotateRight(head1, 2);
    cout << "After Rotating by 2 : ";
    printLL(head1);
    cout << endl;

    vector<int> nums2 = {0, 1, 2};
    ListNode* head2 = convertArr2LL(nums2);
    cout << "Linked List 2 : ";
    printLL(head2);
    head2 = rotateRight(head2, 4);
    cout << "After Rotating by 4 : ";
    printLL(head2);
    cout << endl;

    vector<int> nums3 = {1, 2, 3, 4, 5};
    ListNode* head3 = convertArr2LL(nums3);
    cout << "Linked List 3 : ";
    printLL(head3);
    head3 = rotateRight(head3, 0);
    cout << "After Rotating by 0 : ";
    printLL(head3);
    cout << endl;

    vector<int> nums4 = {1};
    ListNode* head4 = convertArr2LL(nums4);
    cout << "Linked List 4 : ";
    printLL(head4);
    head4 = rotateRight(head4, 3);
    cout << "After Rotating by 3 : ";
    printLL(head4);
    cout << endl;
    
    return 0;
}