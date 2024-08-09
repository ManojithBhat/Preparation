# Rotate Image 

## Problem desciption 
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

### Example 1
> **Input:** matrix = [[1,2,3],[4,5,6],[7,8,9]]
> **Output:** [[7,4,1],[8,5,2],[9,6,3]]

### Example 2
> **Input:** matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
> **Output:** [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

## Code
```cpp

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

```

## Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The intuition for rotating a matrix 90 degrees clockwise can be understood by visualizing the movement of elements:

Corner elements:
The top-left corner moves to the top-right, top-right to bottom-right, bottom-right to bottom-left, and bottom-left to top-left.
Edge elements:
Elements on the top edge move to the right edge, right edge to bottom, bottom to left, and left to top.
Inner elements:
They follow the same pattern, moving in concentric squares.

## Approach
<!-- Describe your approach to solving the problem. -->
The approach is to follow these two steps 
* Take the transpose of the given matrix 
* Rotate the individual row of the matrix to get the rotated image

## Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
O(n*n) - As need to trasverse through the matrix

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
O(1) - we are modifying the given matrix 