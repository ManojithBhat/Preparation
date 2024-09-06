# BestTimeToBuyAndSellStock4
[Problem Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/)

## Problem desciption 
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


### Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.


### Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

## constraints
* 1 <= k <= 100
* 1 <= prices.length <= 1000
* 0 <= prices[i] <= 1000

## Code
```cpp
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
          vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k+1,0)));
        // initialising the variables and setting up the variables
        // when day = 0 at all the values is 0 and when ind == n at all other
        // values of day and prices is 0
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int day = 1; day <=k; day++) {
                    int profit = 0;
                    if (buy) {
                        profit =
                            max(-prices[ind] + dp[ind + 1][0][day],
                                0 + dp[ind + 1][1][day]);
                    } else {
                        profit = max(prices[ind] +
                                         dp[ind + 1][1][day-1],
                                     0 + dp[ind + 1][0][day]);
                    }
                    dp[ind][buy][day] = profit;
                }
            }
        }
        return dp[0][1][k];
    }

```

## Intuition


## Approach


## Complexity
- Time complexity:


- Space complexity:
