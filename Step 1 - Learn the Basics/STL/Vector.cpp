#include<bits/stdc++.h>
using namespace std;

void vectors(){
    //basic vector syntax
    // vector <int> v; //v is vector name
    // v.push_back(10); // creates the object first and then moves it to the vector.
    // v.emplace_back(20); // contructs the object directly in the vector. (more efficient)

    // //pair in vector
    // vector <pair <int, int>> vp;
    // vp.push_back({1, 2});
    // vp.emplace_back(3,4);

    // //vector with size declaration
    // vector <int> vd1(5); //5 is the size of the vector
    
    // vector <int> vd2(5, 100); //5 instances of 100

    // vector <int> vd3(vd2); //copying vector vd2 into vd3

    // //iterator in vector
    // vector <int>::iterator it = vd3.begin(); //begin() points to the memory address of the first element of the vector.

    // it++;
    // cout<<*(it)<<" "<<endl; //to get the value at the specific position, we use the pointer.

    // it = it + 2;
    // cout<<*(it)<<" "<<endl;

    //vector <int>::iterator it = vd3.end(); {2, 4, 23} 'it' here points after the 23. To get elements, use it--.
    //vector <int>::iterator it = vd3.rend(); output like begin() but works like end()
    //vector <int>::iterator it = vd3.rbegin(); output like end() but works like begin()

    // cout<< vp[1].second <<endl;

    vector<int> v(2, 100);

    // insert function
    v.insert(v.begin(), 200);
    v.insert(v.begin(), 2, 10);
    for(auto vs : v){
        cout<<vs<<" ";
    }
    cout<<endl;
    v.erase(v.begin()+1, v.begin()+3); //end point is not considered
    for(auto vs : v){
        cout<<vs<<" ";
    }
    cout<<endl;
    // inserting a vector into vector
    vector<int> copy(2, 4);
    v.insert(v.begin(), copy.begin(), copy.end());
    for(auto vs : v){
        cout<<vs<<" ";
    }
    cout<<endl;

    cout<<v.size();
    cout<<endl;
    v.pop_back();
    //v.swap(v1) swaps v2 with v1
    v.clear();
    cout<< v.empty();
}

//vector for loop
// void vectorforloop(){
    
// }

int main(){
    vectors();
    // vectorforloop();
    return 0;
}