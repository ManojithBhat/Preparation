# Flip Columns For Maximum Number of Equal Rows
[Problem Link](https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/)

## Problem desciption 
You are given an m x n binary matrix matrix.

You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).

Return the maximum number of rows that have all values equal after some number of flips.

 

### Example 1:

> **Input:** matrix = [[0,1],[1,1]]
> **Output:** 1
> **Explanation:** After flipping no values, 1 row has all values equal.

> ### Example 2:

> **Input:** matrix = [[0,1],[1,0]]
> **Output:** 2
> **Explanation:** After flipping values in the first column, both rows have equal values.

### Example 3:

> **Input:** matrix = [[0,0,0],[0,0,1],[1,1,0]]
> **Output:** 2
> **Explanation:** After flipping values in the first two columns, the last two rows have equal values.


## constraints
* m == matrix.length
* n == matrix[i].length
* 1 <= m, n <= 300
* matrix[i][j] is either 0 or 1.

## Code
```cpp
class Solution {
public:
    /*
        The intution of the problem is to check for the particular rows for a given row how many similar and inverted row is possible.

        1 0 0 
        1 0 0 
        0 1 0 
        0 1 1 

        In the above example, for the first row 1 0 0, the row 2nd is same and last row is inverted so the count is 3,
        for the second row 1 0 0 check all the rows 1, 2 and 4th row
        for third row ther is no row with similarity or reverse similarity
        for the fourth row 1st and 2nd row are reverse similar 
        by chekcking all the counts we find 3 is maximum. 
    */
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        unordered_map<string,int> mp;

        for(auto row: matrix){
            string str = "",rev = "";
            for(auto it: row){
                str += (it==1 ? '1':'0');
                rev += (it==0 ? '1':'0');
            }
            mp[str]++;
            mp[rev]++;
        }

        int cnt = 0;
        for(auto it: mp){
            cnt = max(cnt,it.second);
        }
        return cnt;
    }
};
```

## Complexity
- Time complexity: O(M*N)


- Space complexity: O(N*M)
