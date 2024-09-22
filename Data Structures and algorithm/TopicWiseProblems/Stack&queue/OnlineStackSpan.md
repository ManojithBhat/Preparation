# Online stock span
[Problem Link]()

## Problem desciption 
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.
 

### Example 1:

**Input:**
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]<br>
[[], [100], [80], [60], [70], [60], [75], [85]]<br>
**Output:**<br>
[null, 1, 1, 1, 2, 1, 4, 6]<br>

Explanation
StockSpanner stockSpanner = new StockSpanner();<br>
stockSpanner.next(100); // return 1<br>
stockSpanner.next(80);  // return 1<br>
stockSpanner.next(60);  // return 1<br>
stockSpanner.next(70);  // return 2<br>
stockSpanner.next(60);  // return 1<br>
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.<br>
stockSpanner.next(85);  // return 6<br>


## constraints
* 1 <= price <= 105
* At most 104 calls will be made to next.

## Code
```cpp
class StockSpanner {
public:
    stack<int> st;
    vector<int> arr;
    int cnt;
    StockSpanner() {
        cnt = -1;
    }

    int next(int price) {
        arr.push_back(price);
        cnt++;
        int topval;
        while (!st.empty() && arr[st.top()] <= price) {
            st.pop();
        }
        st.size() ? topval = cnt - st.top() : topval = cnt+1;
        st.push(cnt);
        return topval;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

```

## Intuition
The intution of using the stack comes from the fact that it can store the element in either increasing or decreasing order. so here we need to keep the count of the prev day at which the stock was greater so we keep a monotonically decreasing stack. here i have used the array but we can use ```stack<pari<int,int>>``` to eliminiate the extra vector. 


## Complexity
- Time complexity:O(N)


- Space complexity:O(N)
