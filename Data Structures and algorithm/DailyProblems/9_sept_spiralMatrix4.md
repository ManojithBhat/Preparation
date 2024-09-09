# Spiral Matrix IV
[Problem Link](https://leetcode.com/problems/spiral-matrix-iv/description/?envType=daily-question&envId=2024-09-09)

## Problem desciption 
You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

Return the generated matrix.

### Example 1

**Input:** m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]<br>
**Output:** [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]<br>
**Explanation:** The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.


## constraints
* 1 <= m, n <= 105
* 1 <= m * n <= 105
* The number of nodes in the list is in the range [1, m * n].
* 0 <= Node.val <= 1000

## Code
```cpp

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m,vector<int>(n,-1));
        ListNode* curr = head;
        int left = 0,right = n - 1,top = 0,bottom = m - 1;
        int cnt = 0;
        while(curr){

            for(int i = left;i<=right && curr;i++){
                res[top][i] = curr->val;
                curr = curr->next;
            }
            top++;

            for(int j=top;j<=bottom && curr;j++){
                res[j][right] = curr->val;
                curr = curr->next;
            }
            right--;

            for(int i=right;i>=left && curr;i--){
                res[bottom][i] = curr->val;
                curr = curr->next;
            }
            bottom--;

            for(int j = bottom;j>=top && curr;j--){
                res[j][left] = curr->val;
                curr = curr->next;
            }
            
            left++;
        }

        return res;
    }
};

```

## Intuition
Similar to the spiral matrix, here they would have given linked list, initialise the matrix with -1, now traverse through the linked list untill it is exhausted,
adnd rest of the logic is same as spiral matrix. 


## Complexity
- Time complexity: O(n)


- Space complexity: O(n*m)
