#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int price = prices[0];
    int profit = 0;
    for(int i = 1; i < prices.size(); i++){
        if(prices[i] < price){
            price = prices[i];
        }
        else{
            profit = max(profit, prices[i] - price);
        }
    }
    return profit;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout<<maxProfit(prices)<<endl;
    return 0;
}