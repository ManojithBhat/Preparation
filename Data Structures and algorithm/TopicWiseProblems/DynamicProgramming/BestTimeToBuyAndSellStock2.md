# Stock Buy and sell 2 
[Problem Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)

## Problem desciption 
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.


### Example 1:

> **Input:** prices = [7,1,5,3,6,4]<br>
> **Output:** 7<br>
> **Explanation:** Buy on day 2 (price = 1) and sell on day 3(price = 5), profit = 5-1 = 4.<br>
> Then buy on day 4 (price = 3) and sell on day 5 (price = 6),  profit = 6-3 = 3.<br>
> Total profit is 4 + 3 = 7.<br>
>

### Example 2:

> **Input:** prices = [1,2,3,4,5]<br>
> **Output:** 4<br>
> **Explanation:** Buy on day 1 (price = 1) and sell on day 5 <br>(price = 5), profit = 5-1 = 4.<br>
> Total profit is 4.<br>



## constraints
* 1 <= prices.length <= 3 * 104
* 0 <= prices[i] <= 104

## Code

Memoisation 
```cpp
int f(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (ind == prices.size()) {
            return 0;
        }

        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        int profit = 0;
        if (buy) {
            profit = max(-prices[ind] + f(ind + 1, 0, prices, dp),
                         0 + f(ind + 1, 1, prices, dp));
        }else{
            profit = max(prices[ind] + f(ind + 1, 1, prices, dp),
                         0 + f(ind + 1, 0, prices, dp));
        }
        return dp[ind][buy] = profit;
    }
 
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        //code for memoisation - top down approach 
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return f(0,1,prices,dp);
    } 
```

Tabulation 
```cpp

 int maxProfit(vector<int>& prices) {
        int n = prices.size();

        //code for tabulation - bottom up approach 
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][1]=dp[n][0] = 0;
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {

                int profit = 0;
                if (buy) {
                    profit = max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
                } else {
                    profit =
                        max(prices[ind] + dp[ind + 1][1], 0 + dp[ind + 1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }

```

Space optimisation

```cpp
 int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> ahead(2,0),cur(2,0);
        ahead[1] = ahead[0] = 0;

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {

                int profit = 0;
                if (buy) {
                    profit = max(-prices[ind] + ahead[0], 0 + ahead[1]);
                } else {
                    profit =
                        max(prices[ind] + ahead[1], 0 + ahead[0]);
                }
                ahead[buy] = profit;
            }
            cur = ahead;
    }
        return ahead[1];
 }

```

Greedy approach 

```cpp
int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        int buy = prices[0];
        int profit = 0;

        for(int i=0;i<n;i++){
            if(buy<prices[i]){
                profit += (prices[i]-buy);
            }
            buy = prices[i];
        }
        return profit;
    }

```

## Intuition


## Approach


## Complexity
- Time complexity: O(n)


- Space complexity:
