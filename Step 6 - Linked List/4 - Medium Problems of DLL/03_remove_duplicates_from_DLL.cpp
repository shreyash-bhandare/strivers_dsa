// The DLL is sorted.

#include<bits/stdc++.h>
using namespace std;

class ListNode
{
    public:
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

ListNode* convertArr2DLL(vector<int> &nums){
    ListNode* head = new ListNode(nums[0]);
    ListNode* prev = head;
    for(int i = 1; i < nums.size(); i++){
        ListNode* temp = new ListNode(nums[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void printDLL(ListNode* head){
    ListNode* temp = head;
    while(temp != nullptr){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

ListNode * removeDuplicates(ListNode *head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* temp = head;
    while(temp != nullptr && temp->next != nullptr){
        ListNode* nextNode = temp->next;
        while(nextNode != nullptr && temp->val == nextNode->val){
            ListNode* duplicate = nextNode;
            nextNode = nextNode->next;
            free(duplicate);
        }
        temp->next = nextNode;
        if(nextNode) nextNode->prev = temp;
        temp = temp->next;
    }
    return head;
}

int main(){
    // Test Case 1: Duplicates in the middle
    vector<int> nums1 = {1, 2, 2, 3, 4, 4, 5};
    ListNode* head1 = convertArr2DLL(nums1);

    cout << "DLL 1 : ";
    printDLL(head1);

    head1 = removeDuplicates(head1);

    cout << "After Removing Duplicates : ";
    printDLL(head1);
    cout << endl;


    // Test Case 2: All elements are same
    vector<int> nums2 = {7, 7, 7, 7, 7};
    ListNode* head2 = convertArr2DLL(nums2);

    cout << "DLL 2 : ";
    printDLL(head2);

    head2 = removeDuplicates(head2);

    cout << "After Removing Duplicates : ";
    printDLL(head2);
    cout << endl;


    // Test Case 3: No duplicates
    vector<int> nums3 = {1, 2, 3, 4, 5};
    ListNode* head3 = convertArr2DLL(nums3);

    cout << "DLL 3 : ";
    printDLL(head3);

    head3 = removeDuplicates(head3);

    cout << "After Removing Duplicates : ";
    printDLL(head3);
    cout << endl;

    return 0;
}