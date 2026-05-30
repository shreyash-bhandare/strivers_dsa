#include<bits/stdc++.h>
using namespace std;

void pairs(){
    //pair basic example
    pair <int, int> p1 = {1, 3};

    cout<<"First number is: "<<p1.first<<" and second is: "<<p1.second<<endl;

    //nested pair
    pair<int, pair<int, float>> p2 = {2, {5, 8.345}};

    cout <<"First number is: "<<p2.first<<" Second.first number is: "<<p2.second.first<<" and second.second is: "<<p2.second.second<<endl;

    //pair in an array (we can use pair as a data type here)
    pair <int, int> arr[] = {{1,2}, {5,3}, {9,7}};

    cout<<"First element of the second element of the array:"<<arr[1].first<<endl;
}

int main(){
    pairs();
    return 0;
}