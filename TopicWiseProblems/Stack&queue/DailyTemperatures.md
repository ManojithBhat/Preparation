# Daily Temperatures
[Problem Link](https://leetcode.com/problems/daily-temperatures/description/)

## Problem desciption 
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.


### Example 1:<br>
> 
> <br>**Input:**  temperatures = [73,74,75,71,69,72,76,73]<br>
> **Output:** [1,1,4,2,1,1,0,0]
> <br>
> <br>
>
 ### Example 2:<br>
> 
> <br> **Input:** temperatures = [30,40,50,60]<br>
> **Output:** [1,1,1,0]<br>
> <br>

## constraints
* 1 <= temperatures.length <= 105
* 30 <= temperatures[i] <= 100

## Code
```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<pair<int,int>> st;
        int n = temperatures.size();
        vector<int> ans(n);
        ans[n-1] = 0;
        st.push({n-1,temperatures[n-1]});

        for(int i=n-2;i>=0;i--){
            int ind = st.top().first;
            while(!st.empty() && st.top().second<=temperatures[i]){
                st.pop();
            }
            if(st.empty()) ans[i] = 0;
            else{
                ans[i] = st.top().first - i;
            }
            st.push({i,temperatures[i]});
        }
        return ans;
    }
};

```

## Intuition
This problem requires the knowledge of monotonic stack ( the stack which has elements either in the increasing or decreasing order ) and when to pop and update the elements.
<br>
As it requires us to check when is the next greater temperature, it will be obvious to keep the stack in the decreasing order ( with the greatest element at the bottom and smallest at the top ), so whenever we dont find the element greater than the current at the top of the stack, we pop it until we get the element.
<br>
As it requires that we need to say at what position from the current will the next temperature will be, we are supposed to keep track of the index ( not only the pop elements ), hence we keep a stack of ```pair<int,int>``` so that we can keep both ```index,element```.

## Approach
Keep a stack of ```pair<int,int>```, iterate from the back, whenever we get temperature lower than the current temperature, ```pop``` it. and store the index of the ```top ``` of the stack - currIndex. and push the currElement.

## Complexity
- Time complexity: O(N)


- Space complexity: O(N)
