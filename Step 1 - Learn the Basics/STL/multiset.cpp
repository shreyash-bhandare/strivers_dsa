#include<bits/stdc++.h>
using namespace std;

void explainMS(){
    // everything same as set - sorted but stores duplicates also

    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);

    //ms.erase(1); // deleted all occurences of 1's

    int cnt = ms.count(1);

    //to delete only one 1
    ms.erase(ms.find(1)); // also can erase in range also.
}

int main(){
    explainMS();
    return 0;
}