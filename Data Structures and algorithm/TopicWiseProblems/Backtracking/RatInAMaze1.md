# Rat in a maze 1

[problem link](https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1)

## Problem desciption 
Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the destination at (n - 1, n - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list. The driver will output "-1" automatically

### Example 1

> **Input:** mat[][] = [[1, 0, 0, 0], <br>
>                 [1, 1, 0, 1], <br>
>                 [1, 1, 0, 0], <br>
>                 [0, 1, 1, 1]] <br>
> <br>
> **Output:** DDRDRR DRDDRR
> <br>
> 
> **Explanation:** The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.


## constraints
* 2 ≤ n ≤ 5
* 0 ≤ mat[i][j] ≤ 1


## Code
```cpp

// User function template for C++

class Solution{
    public:
    void solve(int r,int c,int n,vector<vector<int>> &m,string &curr,vector<string>&res){
        if(r==n-1 && c==n-1){
            res.push_back(curr);
            return;
        }
        
        int row[4] = {0,1,0,-1};
        int col[4] = {1,0,-1,0};
        
        for(int i=0;i<4;i++){
            int nrow = row[i] + r;
            int ncol = col[i] + c;
            
            if(nrow < n && ncol < n && nrow>=0 && ncol>=0 && m[nrow][ncol]){
                m[r][c] = 0;
                if(row[i]==0 && col[i]==1){
                    //it is right 
                    curr.push_back('R');
                    solve(nrow,ncol,n,m,curr,res);
                    curr.pop_back();
                }
                else if(row[i]==0 && col[i]==-1){
                    curr.push_back('L');
                    solve(nrow,ncol,n,m,curr,res);
                    curr.pop_back();
                }
                else if(row[i]==1 && col[i]==0){
                    curr.push_back('D');
                    solve(nrow,ncol,n,m,curr,res);
                    curr.pop_back();
                }else if(row[i]==-1&& col[i]==0){
                    curr.push_back('U');
                    solve(nrow,ncol,n,m,curr,res);
                    curr.pop_back();
                }
                m[r][c] = 1;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(!m[0][0] || !m[n-1][n-1]) return {"-1"};
        
        vector<string> res;
        string s;
        
        solve(0,0,n,m,s,res);
        
        return res;
    }
};

```

## Intuition
This is one such question, which involoves the combination of both ***backtracking*** ( as we are taking the path which we are following ) and graph concept of ***Depth First Search*** .
<br>
It is important to note the edge cases - 
<br>
* if the first and last cells is 0 then we cannot have a path, so return at the first.
* we need to mark the cell as 0 before going to next call, and make it again 1 when finished ( a typical format of backtracking ).
  <br>

We explore all the four direction wrt the constraint ( boundary condition ) push the character to the string and pop it afterwards.
<br>
Once we reach the base case ( reach the last cell ) we push the string to the answer array.

## Approach
A combo of DFS and backtracking.

## Complexity
- Time complexity:  O(3^n^2)  - As we are trying to find all the combination 


- Space complexity: O(n*m)
