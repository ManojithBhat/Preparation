# Minimum Time Difference
[Problem Link](https://leetcode.com/problems/minimum-time-difference/description/?envType=daily-question&envId=2024-09-16)

## Problem desciption 
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

### Example 1:

Input: timePoints = ["23:59","00:00"]<br>
Output: 1<br>


## constraints
* 2 <= timePoints.length <= 2 * 104
* timePoints[i] is in the format "HH:MM".

## Code
```cpp
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
         int n = timePoints.size();
        vector<int> minutes(n);

        for(int i = 0; i < n; i++) {
            string time = timePoints[i];

            string hourSubstr = time.substr(0, 2); //"HH"
            string minSubstr = time.substr(3); //"MM"

            int hourInt = stoi(hourSubstr);
            int minInt  = stoi(minSubstr);

            minutes[i] = hourInt*60 + minInt;
        }

        sort(begin(minutes), end(minutes));

        int result = INT_MAX;
        for(int i = 1; i < n; i++) {
            result = min(result, minutes[i] - minutes[i-1]);
        }

        return min(result, (24*60 - minutes[n-1]) + minutes[0]);
    }
};
```

## Intuition
the intution is find the time length keeping the 00:00 as the time referance, once you have done that, find the time diff between all the time, but there is a edge case, if the time is 23:59 and 00:02 then the time for both will be 1438 and other is 2 but the actual difference is only 3 to overcome this, we need to take the diff of last and first element and compare with the prev min element. 

## Approach
for such fixed length string to convert integer use stoi and substr concept. 

## Complexity
- Time complexity: O(NlogN)


- Space complexity: O(N)
