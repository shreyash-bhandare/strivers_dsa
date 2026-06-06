// Given an array nums of n integers, where nums[i] represents the number of pages in the i-th book, 
// and an integer m representing the number of students, allocate all the books to the students 
// so that each student gets at least one book, each book is allocated to only one student, 
// and the allocation is contiguous.
// Allocate the books to m students in such a way that the maximum number of pages assigned to a student is minimized. 
// If the allocation of books is not possible, return -1.

// Example 1
// Input: nums = [12, 34, 67, 90], m=2
// Output: 113
// Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.

// Example 2
// Input: nums = [25, 46, 28, 49, 24], m=4
// Output: 71
// Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.

#include<bits/stdc++.h>
using namespace std;

int countStudents(vector<int>&nums, int pages){
    int students = 1;
    long long pagesStudent = 0;
    for(int i = 0; i < nums.size(); i++){
        if(pagesStudent + nums[i] <= pages){
            pagesStudent += nums[i];
        }
        else{
            students++;
            pagesStudent = nums[i];
        }
    }
    return students;
}

int findPages(vector<int> &nums, int m)  {
    int n = nums.size();
    if(m > n) return -1;
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    while(low <= high){
        int mid = low + (high - low)/2;
        int students = countStudents(nums, mid);
        if(students > m) low = mid+1;
        else high = mid-1;
    }
    return low;
}

int main(){
    vector<int> books1 = {12, 34, 67, 90};
    int students1 = 2;
    int ans1 = findPages(books1, students1);
    cout << "Minimum possible maximum pages for books [ ";
    for(int pages : books1){
        cout << pages << " ";
    }
    cout << "] is " << ans1 << " for " << students1 << " students." << endl;

    vector<int> books2 = {25, 46, 28, 49, 24};
    int students2 = 4;
    int ans2 = findPages(books2, students2);
    cout << "Minimum possible maximum pages for books [ ";
    for(int pages : books2){
        cout << pages << " ";
    }
    cout << "] is " << ans2 << " for " << students2 << " students." << endl;

    vector<int> books3 = {10, 20, 30, 40};
    int students3 = 2;
    int ans3 = findPages(books3, students3);
    cout << "Minimum possible maximum pages for books [ ";
    for(int pages : books3){
        cout << pages << " ";
    }
    cout << "] is " << ans3 << " for " << students3 << " students." << endl;
    return 0;
}