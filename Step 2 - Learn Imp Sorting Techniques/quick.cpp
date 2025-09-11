#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){
        while(arr[i] <= pivot && i <= high-1) i++;      // reaching to the leftmost larger element than pivot
        while(arr[j] >= pivot && j >= low+1) j--;       // reaching to the rightmost smaller element than pivot
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quick(vector<int> &arr, int low, int high){
    if(low < high){
        int part = partition(arr, low, high);
        quick(arr, low, part-1);
        quick(arr, part+1, high);
    }
}

int main(){
    vector<int> q = {13, 46, 24, 52, 20, 9};
    quick(q, 0, q.size()-1);
    for(int i : q){
        cout<<i<<" ";
    }
    return 0;
}