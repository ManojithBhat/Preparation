# Spiral Matrix 

## Problem desciption 
Given an m x n matrix, return all elements of the matrix in spiral order.

**Example 1**

> Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
> <br>
> Output: [1,2,3,4,8,12,11,10,9,5,6,7]

**Example 2**
> Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
> <br>
> Output: [1,2,3,6,9,8,7,4,5]

## constraints
* m == matrix.length
* n == matrix[i].length
* 1 <= m, n <= 10
* -100 <= matrix[i][j] <= 100

## Code
```cpp

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> res;
        int left = 0,top = 0, right = m - 1,bottom = n - 1;

        while(left<=right && top<=bottom){
            //keep row as constant and iterate through the column 
            for(int i=left;i<=right;i++) res.push_back(matrix[top][i]);
            top++;

            //keep the column as constant and iterate through the row
            for(int j=top;j<=bottom;j++) res.push_back(matrix[j][right]);
            right--;

            if(top<=bottom){
                //keep the row iterator as constant and iterate through the column
                for(int i=right;i>=left;i--) res.push_back(matrix[bottom][i]);
                bottom--;
            }

            if(left<=right){
                //keep the column as constant and iterate through the row 
                for(int j=bottom;j>=top;j--) res.push_back(matrix[j][left]);
                left++;
            }
            
        }
        return res;
    }
};

```

## Intuition

The problem requires traversing a 2D matrix in a spiral order, starting from the top-left corner and moving inwards in a clockwise direction. This pattern of traversal can be achieved by maintaining boundaries for the top, bottom, left, and right edges of the matrix and adjusting these boundaries as we progress.

## Approach
Use a while loop to continue until the boundaries overlap, i.e., top exceeds bottom or left exceeds right.
Traverse from left to right along the top boundary and then increment the top boundary.
Traverse from top to bottom along the right boundary and then decrement the right boundary.
If there are remaining rows, traverse from right to left along the bottom boundary and then decrement the bottom boundary.
If there are remaining columns, traverse from bottom to top along the left boundary and then increment the left boundary.

## Complexity
- Time complexity: O(n*m)


- Space complexity: O(1)
