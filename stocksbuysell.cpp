// approach 1; brutforce
// set a pointer i at 0th index and j at i +1 
// iterate i from 0 to n-2 and j from i+1 to n-1
// and check if arr[j]>arr[i] if yes check there diff is greater than previously stored diff

// time c. = o(n2)

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.

    int maxP = 0;
    int n = prices.size();
    for(int i = 0 ; i < n-1;i++) {
        for(int j = i+1 ;j <n;j++) {
            if(prices[j]>prices[i]) {
                maxP = max(maxP,prices[j]-prices[i]);
            }
        }
    }
    return maxP;
}



int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n = prices.size(), profit = 0;
    // set profit = 0 bcz if array is in decreasing order u will never buy or sell and profit will be 0
    // and we will find the min buy price and set it to INT_MAX;
    // as we will be iterating over the array, we wiill keep track of min price on the left of the current iterator and find profit for minBuy and i th element and keep update of max profit.

    int minBuyP = INT_MAX;
    
    for(int i = 0 ; i < n ; i++) {
        minBuyP=min(minBuyP,prices[i]);
        profit = max(profit,prices[i]-minBuyP);
        
    }
    return profit;
}