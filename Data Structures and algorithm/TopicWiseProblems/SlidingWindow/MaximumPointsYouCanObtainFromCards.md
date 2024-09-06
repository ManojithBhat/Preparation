# Maximum points you can obtain from cards
[Problem Link](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/submissions/1372854592/)

## Problem desciption 
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

### Example 1:

**Input:** cardPoints = [1,2,3,4,5,6,1], k = 3<br>
**Output:** 12<br>
**Explanation:** After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
### Example 2:

**Input:** cardPoints = [2,2,2], k = 2<br>
**Output:** 4<br>
**Explanation:** Regardless of which two cards you take, your score will always be 4.
### Example 3:

**Input:** cardPoints = [9,7,7,9,7,7,9], k = 7<br>
**Output:** 55<br>
Explanation: You have to take all the cards. Your score is the sum of points of all cards.


## constraints
* 1 <= cardPoints.length <= 105
* 1 <= cardPoints[i] <= 104
* 1 <= k <= cardPoints.length

## Code
```cpp
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int m = n - k;

        int sum = accumulate(cardPoints.begin(),cardPoints.end(),0);
        
        if( m == 0 ) return sum;

        int i = 0,j=0;

        int currSum = 0;
        int maxSum = 0;
        
        while( j < n ){
            
            currSum += cardPoints[j];

            if( j-i+1 >= m){
                maxSum = max(maxSum, sum - currSum);
                currSum -= cardPoints[i];
                i++;
            }

            j++;
        }

        return maxSum;
    }
};
```

## Intuition
The problem requires find the max sum right and left of the size k. For this we calculate the total sum of the array, then we use the fixed size sliding window template where in we calculate the totaSum - currSum till n - k ( where n is the total size of the array and k is the given size) and move the window untill the j < n. By this method we are finding the remaining sum which is of size k and taking the max to obtain the solution.

## Approach


## Complexity
- Time complexity:


- Space complexity:
