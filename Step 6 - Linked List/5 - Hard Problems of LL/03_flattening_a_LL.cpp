// Given a special linked list containing n head nodes where every node in the linked list contains two pointers:

// ‘Next’ points to the next node in the list
// ‘Child’ pointer to a linked list where the current node is the head
// Each of these child linked lists is in sorted order and connected by a 'child' pointer.


// Flatten this linked list such that all nodes appear in a single sorted layer connected by the 'child' pointer 
// and return the head of the modified list.

// Example 1
// Input:

// 3 -> NULL
// |
// 2 -> 10 -> NULL
// |
// 1 -> 7 -> 11 -> 12 -> NULL
// |
// 4 -> 9 -> NULL
// |
// 5 -> 6 -> 8 -> NULL

// Output: head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11 -> 12
// Explanation: All the linked lists are joined together and sorted in a single level through the child pointer.

// Example 2
// Input:

// 4 -> 10 -> NULL
// |
// 2 -> 5 -> 20 -> NULL
// |
// 12 -> 13 -> 16 -> 17 -> NULL

// Output: head -> 2 -> 4 -> 5 -> 10 -> 12 -> 13 -> 16 -> 17 -> 20
// Explanation: All the linked lists are joined together and sorted in a single level through the child pointer.

#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode* child;

    // Constructor 1
    ListNode(int val1, ListNode* next1, ListNode* child1){
        val = val1;
        next = next1;
        child = child1;
    }

    // Constructor 2
    ListNode(int val1){
        val = val1;
        next = nullptr;
        child = nullptr;
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

void printChildLL(ListNode* head){
    ListNode* temp = head;
    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->child;
    }
    cout << endl;
}

ListNode* merge2SortedLists(ListNode* head1, ListNode* head2){
    ListNode* dummyNode = new ListNode(-1);
    ListNode* res = dummyNode;
    while(head1 != nullptr && head2 != nullptr){
        if(head1->val < head2->val){
            res->child = head1;
            res = head1;
            head1 = head1->child;
        }
        else{
            res->child = head2;
            res = head2;
            head2 = head2->child;
        }
        res->next = nullptr;
    }
    if(head1) res->child = head1;
    else res->child = head2;
    if(dummyNode->child) dummyNode->child->next = nullptr;
    return dummyNode->child;
}

ListNode* flattenLinkedList(ListNode* &head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* mergeHead = flattenLinkedList(head->next);
    return merge2SortedLists(head, mergeHead);
}
// Time Complexity: O(2*N*M) N for mergedHead, 2*M for merging 2 lists.
// Space Complexity: O(N)

int main(){
    // Test Case 1
    // Structure:
    // 3 -> 2 -> 1 -> 4 -> 5
    // |    |    |    |    |
    // N   10    7    9    6
    //           |         |
    //          11         8
    //           |
    //          12

    ListNode* head1 = new ListNode(3);

    head1->next = new ListNode(2);
    head1->next->next = new ListNode(1);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    head1->next->child = new ListNode(10);

    head1->next->next->child = new ListNode(7);
    head1->next->next->child->child = new ListNode(11);
    head1->next->next->child->child->child = new ListNode(12);

    head1->next->next->next->child = new ListNode(9);

    head1->next->next->next->next->child = new ListNode(6);
    head1->next->next->next->next->child->child = new ListNode(8);

    cout << "Flattened List 1 : ";
    head1 = flattenLinkedList(head1);
    printChildLL(head1);
    cout << endl;


    // Test Case 2
    // Structure:
    // 4 -> 2 -> 12
    // |    |     |
    // 10   5     13
    //      |     |
    //     20     16
    //            |
    //           17

    ListNode* head2 = new ListNode(4);

    head2->next = new ListNode(2);
    head2->next->next = new ListNode(12);

    head2->child = new ListNode(10);

    head2->next->child = new ListNode(5);
    head2->next->child->child = new ListNode(20);

    head2->next->next->child = new ListNode(13);
    head2->next->next->child->child = new ListNode(16);
    head2->next->next->child->child->child = new ListNode(17);

    cout << "Flattened List 2 : ";
    head2 = flattenLinkedList(head2);
    printChildLL(head2);
    cout << endl;


    // Test Case 3
    // Single vertical list:
    // 1
    // |
    // 2
    // |
    // 3
    // |
    // 4

    ListNode* head3 = new ListNode(1);

    head3->child = new ListNode(2);
    head3->child->child = new ListNode(3);
    head3->child->child->child = new ListNode(4);

    cout << "Flattened List 3 : ";
    head3 = flattenLinkedList(head3);
    printChildLL(head3);
    cout << endl;
    
    return 0;
}