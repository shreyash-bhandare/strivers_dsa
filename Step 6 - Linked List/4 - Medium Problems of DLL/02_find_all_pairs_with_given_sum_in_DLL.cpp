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

ListNode* findTail(ListNode* head){
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    return tail;
}

vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
    ListNode* left = head, *right = findTail(head);
    vector<vector<int>> ans;
    while(left->val < right->val){
        int sum = left->val + right->val;
        if(sum == target){
            ans.push_back({left->val, right->val});
            left = left->next;
            right = right->prev;
        }
        else if(sum < target){
            left = left->next;
        }
        else right = right->prev;
    }
    return ans;
}

int main(){
    // Test Case 1: Multiple pairs
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    ListNode* head1 = convertArr2DLL(nums1);

    cout << "DLL 1 : ";
    printDLL(head1);

    vector<vector<int>> ans1 = findPairsWithGivenSum(head1, 8);

    cout << "Pairs : ";
    for(auto &pair : ans1){
        cout << "[" << pair[0] << "," << pair[1] << "] ";
    }
    cout << endl << endl;


    // Test Case 2: No pairs
    vector<int> nums2 = {1, 2, 3, 4, 5};
    ListNode* head2 = convertArr2DLL(nums2);

    cout << "DLL 2 : ";
    printDLL(head2);

    vector<vector<int>> ans2 = findPairsWithGivenSum(head2, 20);

    cout << "Pairs : ";
    for(auto &pair : ans2){
        cout << "[" << pair[0] << "," << pair[1] << "] ";
    }
    cout << endl << endl;


    // Test Case 3: One pair
    vector<int> nums3 = {1, 2, 4, 6, 8};
    ListNode* head3 = convertArr2DLL(nums3);

    cout << "DLL 3 : ";
    printDLL(head3);

    vector<vector<int>> ans3 = findPairsWithGivenSum(head3, 10);

    cout << "Pairs : ";
    for(auto &pair : ans3){
        cout << "[" << pair[0] << "," << pair[1] << "] ";
    }

    return 0;
}