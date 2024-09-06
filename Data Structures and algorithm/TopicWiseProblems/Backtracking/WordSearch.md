#  Word Search
[Problem Link](https://leetcode.com/problems/word-search/)

## Problem desciption 
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

### Example 1
**Input:** board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"<br>
**Output:** true

## constraints
* m == board.length
* n = board[i].length
* 1 <= m, n <= 6
* 1 <= word.length <= 15
* board and word consists of only lowercase and uppercase English letters.

## Code
```cpp
class Solution {
public:
    bool wordSearch(int ind, int i, int j, vector<vector<char>>& board,
                    vector<vector<int>>& vis, string word) {
        if (ind == word.size()) {
            return true;
        }

        int n = board.size();
        int m = board[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || board[i][j] != word[ind]) {
            return false; // Out of bounds or already visited or character doesn't match
        }

        int row[4] = {0, 1, 0, -1};
        int col[4] = {1, 0, -1, 0};
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
        
            int nrow = row[k] + i;
            int ncol = col[k] + j;

            if (wordSearch(ind + 1, nrow, ncol, board, vis, word) == true)
                    return true;
        }
        vis[i][j] = 0;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        char start = word[0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == start) {
                    vector<vector<int>> vis(n, vector<int>(m, 0));
                    if (wordSearch(0, i, j, board, vis, word) == true)
                        return true;
                }
            }
        }
        return false;
    }
};

```

## Intuition
This problem is combination of backtracking and depth first search. Here we go through all the cells and start at that cell where we find word[0]. Then we perform dfs call by marking the current cell visited, before that is is important that we check for the bounds prior so that it works for all the test cases.
> edge case encountered : <br> borad  [["a"]] and word = "a"

and then we mark the cell call for next index of word and four direction adjacent to the curr cell and then unmark, whenver it returns true, we pass it to the main function. 

## Approach


## Complexity
- Time complexity: O((n*m)^2)


- Space complexity:
