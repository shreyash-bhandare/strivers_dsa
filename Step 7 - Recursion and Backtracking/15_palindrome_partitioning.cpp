#include<bits/stdc++.h>
using namespace std;

// check if string before partitioning is palindrome.
bool isPalindrome(string s, int start, int end){
    while(start <= end){
        if(s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

void findPalindromePartitioning(int ind, string s, vector<string> &path, vector<vector<string>> &ans){
    if(ind == s.size()){
        ans.push_back(path);
        return;
    }
    for(int i = ind; i < s.size(); i++){
        if(isPalindrome(s, ind, i)){
            path.push_back(s.substr(ind, i-ind+1));
            findPalindromePartitioning(i+1, s, path, ans);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> path; // individual list of substrings for each recursion
    findPalindromePartitioning(0, s, path, ans);
    return ans;
}

int main(){
    string s = "aabb";
    vector<vector<string>> ans = partition(s);
    cout<<"The string is "<<s<<" and partitions are: "<<endl;
    for(int i = 0; i < ans.size(); i++){
        cout<<"[ ";
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}