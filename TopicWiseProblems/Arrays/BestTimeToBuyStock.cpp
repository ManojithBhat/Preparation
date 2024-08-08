

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.


Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104

 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = prices[0];
        int n = prices.size();
        int maxProfit = 0;
        for(int i=1;i<n;i++){
            if(minPrice < prices[i]){ //O(N)
                maxProfit = max(maxProfit,prices[i]-minPrice);
            }
            else{
                minPrice = prices[i];
            }
        }
        return maxProfit;

    }
};


/*

 Intution : In this particular question, we are required to buy the stock once and sell that once, we are not allowed to multiple buy and sell nor we can buy and sell on the same day.
 Hence in the greedy approach we can achieve max profit only by taking the stock on the day with least amount and selling the stock the next subsequent day with the highest prices, so as we iterate through the array we try to keep track of the min element and try to find the max profit by selling the stock on the day with the highest price.

 Time Complexity : O(N) as we are traversing the array only once. 
 Space Complexity : O(1) as we are not using any extra space.


*/