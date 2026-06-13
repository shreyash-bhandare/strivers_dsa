// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

// Example 1:
// Input: head = [1,2,2,1]
// Output: true

// Example 2:
// Input: head = [1,2]
// Output: false

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

ListNode* reverseLL(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* temp = head;
    ListNode* prev = nullptr;
    while(temp != nullptr){
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return true;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr){    // O(N/2)
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* newHead = reverseLL(slow->next);
    ListNode* first = head, *second = newHead;
    while(second != nullptr){                                       // O(N/2)
        if(first->val != second->val){
            reverseLL(newHead);  // return answer without modifying LL  // O(N/2)
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(newHead);         // returning answer without modifying list  // O(N/2)
    return true;
}
// Time Complexity: O(2N)
// Space Complexity: O(1)

int main(){
    vector<int> nums1 = {1, 2, 2, 1};
    ListNode* head1 = convertArr2LL(nums1);
    cout << "Linked List 1 : ";
    printLL(head1);
    cout << "Is Palindrome? : "<< (isPalindrome(head1) ? "True" : "False") << endl;

    vector<int> nums2 = {1, 2, 3, 2, 1};
    ListNode* head2 = convertArr2LL(nums2);
    cout << "Linked List 2 : ";
    printLL(head2);
    cout << "Is Palindrome? : "<< (isPalindrome(head2) ? "True" : "False") << endl;

    vector<int> nums3 = {1, 2, 3, 4};
    ListNode* head3 = convertArr2LL(nums3);
    cout << "Linked List 3 : ";
    printLL(head3);
    cout << "Is Palindrome? : " << (isPalindrome(head3) ? "True" : "False") << endl;

    vector<int> nums4 = {7};
    ListNode* head4 = convertArr2LL(nums4);
    cout << "Linked List 4 : ";
    printLL(head4);
    cout << "Is Palindrome? : "<< (isPalindrome(head4) ? "True" : "False") << endl;

}