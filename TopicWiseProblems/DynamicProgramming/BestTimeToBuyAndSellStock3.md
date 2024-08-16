# BestTimeToBuyAndSellStock3
[Problem Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)

## Problem desciption 
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.


## constraints
1 <= prices.length <= 105
0 <= prices[i] <= 105

## Code
```cpp

     int f(int ind, int buy, vector<int>& prices, int day,
          vector<vector<vector<int>>> dp) {
        if (ind == prices.size() || day == 0) {
            return 0;
        }

        if (dp[ind][buy][day] != -1)
            return dp[ind][buy][day];
        int profit = 0;
        if (buy) {
            profit = max(-prices[ind] + f(ind + 1, 0, prices, day, dp),
                         0 + f(ind + 1, 1, prices, day, dp));
        } else {
            profit = max(prices[ind] + f(ind + 1, 1, prices, day - 1, dp),
                         0 + f(ind + 1, 0, prices, day, dp));
        }
        return dp[ind][buy][day] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //memoisation
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, prices, 2, dp);

    }

```

Tabulation 

```cpp

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // tabulation code
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        // initialising the variables and setting up the variables
        // when day = 0 at all the values is 0 and when ind == n at all other
        // values of day and prices is 0
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int day = 1; day < 3; day++) {
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
        return dp[0][1][2];
    }

```

## Intuition


## Approach


## Complexity
- Time complexity:


- Space complexity:
