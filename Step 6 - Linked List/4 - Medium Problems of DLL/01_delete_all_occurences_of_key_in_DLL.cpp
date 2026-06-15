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

ListNode * deleteAllOccurrences(ListNode* head, int target) {
    if(head == nullptr) return head;
    if(head->next == nullptr && head->val == target){
        delete head;
        return nullptr;
    }
    ListNode* temp = head;
    while(temp != nullptr){
        if(temp->val == target){
            if(temp == head){
                head = head->next;
            }
            ListNode* prevNode = temp->prev;
            ListNode* nextNode = temp->next;
            if(prevNode) prevNode->next = nextNode;
            if(nextNode) nextNode->prev = prevNode;
            delete temp;
            temp = nextNode;
        }
        else temp = temp->next;
    }
    return head;
}

int main(){
    // Test Case 1: Target occurs in the middle
    vector<int> nums1 = {3, 2, 5, 6, 1, 2, 8};
    ListNode* head1 = convertArr2DLL(nums1);

    cout << "DLL 1 : ";
    printDLL(head1);
    int target1 = 2;
    cout<<"The target is: "<<target1<<endl;
    head1 = deleteAllOccurrences(head1, target1);

    cout << "After Deletion : ";
    printDLL(head1);
    cout << endl;


    // Test Case 2: Target occurs at the head
    vector<int> nums2 = {2, 2, 3, 4, 5};
    ListNode* head2 = convertArr2DLL(nums2);

    cout << "DLL 2 : ";
    printDLL(head2);
    int target2 = 2;
    cout<<"The target is: "<<target2<<endl;
    head2 = deleteAllOccurrences(head2, target2);

    cout << "After Deletion : ";
    printDLL(head2);
    cout << endl;


    // Test Case 3: Target occurs at the tail
    vector<int> nums3 = {1, 2, 3, 4, 5, 5};
    ListNode* head3 = convertArr2DLL(nums3);

    cout << "DLL 3 : ";
    printDLL(head3);
    int target3 = 5;
    cout<<"The target is: "<<target3<<endl;
    head3 = deleteAllOccurrences(head3, target3);

    cout << "After Deletion : ";
    printDLL(head3);
    cout << endl;


    // Test Case 4: All nodes are target
    vector<int> nums4 = {7, 7, 7, 7};
    ListNode* head4 = convertArr2DLL(nums4);

    cout << "DLL 4 : ";
    printDLL(head4);
    int target4 = 7;
    cout<<"The target is: "<<target4<<endl;
    head4 = deleteAllOccurrences(head4, target4);

    cout << "After Deletion : ";
    printDLL(head4);
    cout << endl;


    // Test Case 5: Target not present
    vector<int> nums5 = {1, 2, 3, 4, 5};
    ListNode* head5 = convertArr2DLL(nums5);

    cout << "DLL 5 : ";
    printDLL(head5);
    int target5 = 10;
    cout<<"The target is: "<<target5<<endl;
    head5 = deleteAllOccurrences(head5, target5);

    cout << "After Deletion : ";
    printDLL(head5);
    cout << endl;

    return 0;
}