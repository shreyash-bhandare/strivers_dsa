// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

// Example 1:
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted linked list:
// 1->1->2->3->4->4->5->6

// Example 2:
// Input: lists = []
// Output: []

// Example 3:
// Input: lists = [[]]
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

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0) return nullptr;
    if(lists.size() == 1) return lists[0];
    // GENERAL SYNTAX
    // priority_queue<DataType, Container, Comparator> pq;
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
    for(int i = 0; i < lists.size(); i++){      // O(K)
        if(lists[i]){
            pq.push({lists[i]->val, lists[i]}); // O(log K)
        }
    }
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;
    while(!pq.empty()){                         // N*K nodes, N is avg length of each LL.
        auto it = pq.top();                     // 3 * log K for 3 pq operations.
        pq.pop();
        if(it.second->next){
            pq.push({it.second->next->val, it.second->next});
        }
        temp->next = it.second;
        temp = temp->next;
    }
    return dummyNode->next;
}
// Time Complexity: O(K log K + 3*N*K log K)
// Space Complexity: O(K)   pq.size()

int main(){
    // Test Case 1
    vector<int> nums11 = {1, 4, 5};
    vector<int> nums12 = {1, 3, 4};
    vector<int> nums13 = {2, 6};

    ListNode* head11 = convertArr2LL(nums11);
    ListNode* head12 = convertArr2LL(nums12);
    ListNode* head13 = convertArr2LL(nums13);

    vector<ListNode*> lists1 = {head11, head12, head13};

    cout << "Lists 1 :" << endl;
    printLL(head11);
    printLL(head12);
    printLL(head13);

    ListNode* ans1 = mergeKLists(lists1);

    cout << "Merged List : ";
    printLL(ans1);
    cout << endl;


    // Test Case 2
    vector<int> nums21 = {1};
    vector<int> nums22 = {2};
    vector<int> nums23 = {3};

    ListNode* head21 = convertArr2LL(nums21);
    ListNode* head22 = convertArr2LL(nums22);
    ListNode* head23 = convertArr2LL(nums23);

    vector<ListNode*> lists2 = {head21, head22, head23};

    cout << "Lists 2 :" << endl;
    printLL(head21);
    printLL(head22);
    printLL(head23);

    ListNode* ans2 = mergeKLists(lists2);

    cout << "Merged List : ";
    printLL(ans2);
    cout << endl;


    // Test Case 3
    vector<int> nums31 = {1, 2, 2};
    vector<int> nums32 = {1, 1, 2};
    vector<int> nums33 = {2, 6};

    ListNode* head31 = convertArr2LL(nums31);
    ListNode* head32 = convertArr2LL(nums32);
    ListNode* head33 = convertArr2LL(nums33);

    vector<ListNode*> lists3 = {head31, head32, head33};

    cout << "Lists 3 :" << endl;
    printLL(head31);
    printLL(head32);
    printLL(head33);

    ListNode* ans3 = mergeKLists(lists3);

    cout << "Merged List : ";
    printLL(ans3);
    cout << endl;
        
    return 0;
}