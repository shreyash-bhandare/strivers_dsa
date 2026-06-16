// A linked list of length n is given such that each node contains an additional random pointer, 
// which could point to any node in the list, or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, 
// where each new node has its value set to the value of its corresponding original node. 
// Both the next and random pointer of the new nodes should point to new nodes in the copied list such that 
// the pointers in the original list and copied list represent the same list state. 
// None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, 
// then for the corresponding two nodes x and y in the copied list, x.random --> y.

// Return the head of the copied linked list.

// The linked list is represented in the input/output as a list of n nodes. 
// Each node is represented as a pair of [val, random_index] where:

// val: an integer representing Node.val
// random_index: the index of the node (range from 0 to n-1) that the random pointer points to, 
// or null if it does not point to any node.
// Your code will only be given the head of the original linked list.

// Example 1:
// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

// Example 2:
// Input: head = [[1,1],[2,1]]
// Output: [[1,1],[2,1]]

// Example 3:
// Input: head = [[3,null],[3,0],[3,null]]
// Output: [[3,null],[3,0],[3,null]]

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* random;

    public:
    // constructor 1
    Node(int val1, Node* next1, Node* random1){
        val = val1;
        next = next1;
        random = random1;
    }

    public:
    // constructor 2
    Node(int val1){
        val = val1;
        next = nullptr;
        random = nullptr;
    }
};

Node* convertArr2LL(vector<int> &nums){
    Node* head = new Node(nums[0]);
    Node* mover = head;
    for(int i = 1; i < nums.size(); i++){
        Node* temp = new Node(nums[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertCopyInBetween(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        Node* copyNode = new Node(temp->val);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = temp->next->next;
    }
}

void connectRandomPointer(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        Node* copyNode = temp->next;
        if(temp->random) copyNode->random = temp->random->next;
        temp = temp->next->next;
    }
}

Node* getDeepCopyList(Node* head){
    Node* temp = head;
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    while(temp != nullptr){
        // creating new list
        res->next = temp->next;
        res = res->next;

        // disconnecting and going back to initial state of LL
        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummyNode->next;
}

Node* copyRandomList(Node* head) {
    insertCopyInBetween(head);
    connectRandomPointer(head);
    return getDeepCopyList(head);
}
// Time Complexity: 
// Space Complexity: 

int main(){
    // Test Case 1
    // List: 1 -> 2 -> 3
    // Random:
    // 1 -> 3
    // 2 -> 1
    // 3 -> 2

    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    head1->random = head1->next->next;
    head1->next->random = head1;
    head1->next->next->random = head1->next;

    cout << "Original List 1 copied." << endl;
    Node* copy1 = copyRandomList(head1);
    cout << "Copy created." << endl;
    cout << endl;

    // Test Case 2
    // List: 7 -> 13 -> 11 -> 10 -> 1
    // Random:
    // 7  -> NULL
    // 13 -> 7
    // 11 -> 1
    // 10 -> 11
    // 1  -> 7

    Node* head2 = new Node(7);
    head2->next = new Node(13);
    head2->next->next = new Node(11);
    head2->next->next->next = new Node(10);
    head2->next->next->next->next = new Node(1);

    head2->random = nullptr;
    head2->next->random = head2;
    head2->next->next->random = head2->next->next->next->next;
    head2->next->next->next->random = head2->next->next;
    head2->next->next->next->next->random = head2;

    cout << "Original List 2 copied." << endl;
    Node* copy2 = copyRandomList(head2);
    cout << "Copy created." << endl;
    cout << endl;

    // Test Case 3
    // Single Node
    // List: 5
    // Random:
    // 5 -> 5

    Node* head3 = new Node(5);
    head3->random = head3;

    cout << "Original List 3 copied." << endl;
    Node* copy3 = copyRandomList(head3);
    cout << "Copy created." << endl;
    cout << endl;
    
    return 0;
}