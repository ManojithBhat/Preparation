# N Queens 


# Problem desciption 
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

> Example 2:
> *Input:* n = 4
> *Output*: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
> Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

>  Example 2:
> *Input:* n = 1
> *Output:* [["Q"]]


# Code
```

class Solution {
public:
    bool isCorrectPosition(int i, int j, int n, vector<string>& board) {
    // I need to only look for the rows above because we haven't filled the board below 
    // for example when we are in (x,y) we have to look
    // column above
    // diagonally up-right
    // diagonally up-left

    // look up
    int duprow = i;
    while (duprow >= 0) {
        if (board[duprow][j] == 'Q') return false;
        duprow--;
    }

    // look diagonally up-left
    duprow = i;
    int dupcol = j;
    while (duprow >= 0 && dupcol >= 0) {
        if (board[duprow][dupcol] == 'Q') return false;
        duprow--;
        dupcol--;
    }

    // look diagonally up-right
    duprow = i;
    dupcol = j;
    while (duprow >= 0 && dupcol < n) {
        if (board[duprow][dupcol] == 'Q') return false;
        duprow--;
        dupcol++;
    }

    return true;
}

void solve(int ind, int n, vector<string>& board, vector<vector<string>>& res) {
    if (ind == n) {
        res.push_back(board);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (isCorrectPosition(ind, j, n, board)) {
            board[ind][j] = 'Q';
            solve(ind + 1, n, board, res);
            board[ind][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));

    // to generate a board with all '.'
    solve(0, n, board, res);
    return res;
}

};

```

## Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
This is the backtracking problem where we need to try out all the possible combinations, so the thought process is if we want to place the queen in the certain position then we need to check in the first place whether we can place this queen at this particular position or not, then only we can place this and move to the next row. if it is not possible then we are not position.

# Approach
<!-- Describe your approach to solving the problem. -->
We will be using the standard backtracking templte, 
base case 
check for the condition 
do some calculation 
call next recursion call 
remove the calucation done 
<br>
Here for the condition part : 
as we are traversing along the row, if we want to place the queen then we need to check whether queen is placed in : 
diagnolly up-left 
diagnolly up-right
vertically up 
<br>
if at these positions queen isnt placed we can proceed 

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
O(n!) - as we are trying out all the columns of each row and all the possibility

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
O(1) as we are returning the answer 