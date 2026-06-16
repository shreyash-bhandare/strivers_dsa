// Implement browser history using class
// You need to create a constructor browser (homepage)
// function visit (url)
// function back (steps)
// function forward (steps)

// Example Queries
// 1) homepage (takeuforward.org)
// 2) visit (google.com)
// 3) visit (instagram.com)
// 4) visit (facebook.com)
// 5) back(1) ---> instagram.com
// 6) back(1) ---> google.com
// 7) forward(1) ---> instagram.com
// 8) visit (takeuforward.org)
// 9) forward(2) ---> takeuforward.org
// 10) back(2) ---> google.com
// 11) back(7) ---> takeuforward.org


// node structure:
// string url
// Node* forward
// Node* backward

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    string data;
    Node* next;
    Node* prev;
    Node(): data(0), next(nullptr), prev(nullptr){};
    Node(string s): data(s), next(nullptr), prev(nullptr){};
    Node(string s, Node* next, Node* random): data(s), next(next), prev(random){};
};

class Browser{
    Node* currentPage;
    public:
    Browser(string &homePage){
        currentPage = new Node(homePage);
    }
    void visit(string &url){
        Node* newNode = new Node(url);
        currentPage->next = newNode;
        newNode->prev = currentPage;
        currentPage = newNode;
    }

    string backward(int steps){
        while(steps){
            if(currentPage->prev) currentPage = currentPage->prev;
            else break;
            steps--;
        }
        return currentPage->data;
    }

    string forward(int steps){
        while(steps){
            if(currentPage->next) currentPage = currentPage->next;
            else break;
            steps--;
        }
        return currentPage->data;
    }
};

int main(){

    string homepage = "takeuforward.org";

    Browser browser(homepage);

    // 2) visit (google.com)
    string url1 = "google.com";
    browser.visit(url1);

    // 3) visit (instagram.com)
    string url2 = "instagram.com";
    browser.visit(url2);

    // 4) visit (facebook.com)
    string url3 = "facebook.com";
    browser.visit(url3);

    // 5) back(1) ---> instagram.com
    cout << browser.backward(1) << endl;

    // 6) back(1) ---> google.com
    cout << browser.backward(1) << endl;

    // 7) forward(1) ---> instagram.com
    cout << browser.forward(1) << endl;

    // 8) visit (takeuforward.org)
    string url4 = "takeuforward.org";
    browser.visit(url4);

    // 9) forward(2) ---> takeuforward.org
    cout << browser.forward(2) << endl;

    // 10) back(2) ---> google.com
    cout << browser.backward(2) << endl;

    // 11) back(7) ---> takeuforward.org
    cout << browser.backward(7) << endl;

    return 0;
}