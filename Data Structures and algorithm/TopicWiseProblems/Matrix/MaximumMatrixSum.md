# Maximum Matrix Sum
[Problem Link](https://leetcode.com/problems/maximum-matrix-sum/)

## Problem desciption 
You are given an n x n integer matrix. You can do the following operation any number of times:

Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.
 
### Example 
> **Input:** matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]<br>
> **Output:** 16<br>
> **Explanation:** We can follow the following step to reach sum equals 16:<br>
> - Multiply the 2 last elements in the second row by -1.<br>


## constraints
* n == matrix.length == matrix[i].length
* 2 <= n <= 250
* -105 <= matrix[i][j] <= 105

## Code
```cpp
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int minEle = INT_MAX;
        long long sum = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //count the number of negative elements
                cnt += (matrix[i][j] < 0 ? 1:0);
                sum += abs(matrix[i][j]); //calculate the sum of all the absolute values of matrix elements
                minEle = min(abs(matrix[i][j]),minEle); //find out the min element 
            }
        }
        if(cnt%2!=0) return sum - 2*minEle; //if the count of negative element is odd then remove the least element as we would have calculated the min element among the sum so we remove twice
        return sum; //else return the sum
    }
};
```

## Intuition
Given we can multiply any adjacent elements, it is always possible to populate the negative sign or convert into all positive.With this 3 situation are possible:

If there are even number of negative numbers we can all the elements positive by populating the negative sign and converting them into positive numbers.
If there are odd number of negative numbers then we can make all the elements except one positive and the left out one should be populated the least number in the matrix.

## Approach
Traverse all the elements in the matrix add calulate the absolute value of the elements, simultaneously also keep track of the number of negative elements and minimum of elements, by applying above condition described in the intution we can arrive at the solution.

## Complexity
- Time complexity:O(N*m)


- Space complexity:O(1)
