#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int minimum = prices[0];
    int profit = 0;

    for(int i = 1 ; i < prices.size() ; i++){
        int difference = prices[i] - minimum;
        profit = max(profit, difference);

        if(minimum > prices[i]) minimum = prices[i];
    }

    return profit;
}
