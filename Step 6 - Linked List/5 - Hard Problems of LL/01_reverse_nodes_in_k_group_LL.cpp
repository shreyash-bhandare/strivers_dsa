// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. 
// If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// Example 1:
// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

// Example 2:
// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]

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

ListNode* findKthNode(ListNode* head, int k){
    if(head == nullptr || head->next == nullptr) return head;
    int cnt = 1;
    while(head != nullptr){
        if(cnt == k){
            return head;
        }
        cnt++;
        head = head->next;
    }
    return nullptr;
}

ListNode* reverseLL(ListNode* head){
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* prev = nullptr;
    ListNode* front = nullptr;
    while(head != nullptr){
        front = head->next;
        head->next = prev;
        prev = head;
        head = front;
    }
    return prev;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* temp = head;
    ListNode* nextNode = nullptr;
    ListNode* prevNode = nullptr;
    while(temp != nullptr){
        ListNode* kthNode = findKthNode(temp, k);
        if(kthNode == nullptr){
            if(prevNode){
                prevNode->next = temp;
            }
            break;
        }
        nextNode = kthNode->next;
        kthNode->next = nullptr;
        kthNode = reverseLL(temp);
        if(temp == head) head = kthNode;
        else prevNode->next = kthNode;
        prevNode = temp;
        temp = nextNode;
    }
    return head;
}
// Time Complexity: O(2N)   O(N) for reversal and O(N) for finding the kthNode
// Space Complexity: O(1)

int main(){
    vector<int> nums1 = {1, 2, 3, 4, 5};
    ListNode* head1 = convertArr2LL(nums1);
    cout << "Linked List 1 : ";
    printLL(head1);
    head1 = reverseKGroup(head1, 2);
    cout << "After Reversing in Groups of 2 : ";
    printLL(head1);
    cout << endl;

    vector<int> nums2 = {1, 2, 3, 4, 5};
    ListNode* head2 = convertArr2LL(nums2);
    cout << "Linked List 2 : ";
    printLL(head2);
    head2 = reverseKGroup(head2, 3);
    cout << "After Reversing in Groups of 3 : ";
    printLL(head2);
    cout << endl;

    vector<int> nums3 = {1, 2, 3, 4, 5};
    ListNode* head3 = convertArr2LL(nums3);
    cout << "Linked List 3 : ";
    printLL(head3);
    head3 = reverseKGroup(head3, 1);
    cout << "After Reversing in Groups of 1 : ";
    printLL(head3);
    cout << endl;

    vector<int> nums4 = {1};
    ListNode* head4 = convertArr2LL(nums4);
    cout << "Linked List 4 : ";
    printLL(head4);
    head4 = reverseKGroup(head4, 2);
    cout << "After Reversing in Groups of 2 : ";
    printLL(head4);
    cout << endl;
    
    return 0;
}