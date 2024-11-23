# Rotating the box
[Problem Link](https://leetcode.com/problems/rotating-the-box/?envType=daily-question&envId=2024-11-23)

## Problem desciption 
You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:

A stone '#'
A stationary obstacle '*'
Empty '.'
The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.

Return an n x m matrix representing the box after the rotation described above.


### Example 1
> **Input:** box = [["#",".","*","."],<br>
>               ["#","#","*","."]]<br>
> **Output:** [["#","."],<br>
>          ["#","#"],<br>
>          ["*","*"],<br>
>          [".","."]]<br>


## constraints
* m == box.length
* n == box[i].length
* 1 <= m, n <= 500
* box[i][j] is either '#', '*', or '.'.

## Code
```cpp
class Solution {
public:

    void move(vector<vector<char>> &vec,int i,int j,int c){
        int p = i,q = j-1;
        while( p <= q ){
            if(vec[p][c] == '#'){
                swap(vec[p][c],vec[q][c]);
                q--;
            }else{
                p++;
            }
        }
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();

        vector<vector<char>> rb(m, vector<char>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rb[j][i] = box[i][j];
            }
        }

        for (auto &row : rb) {
            reverse(row.begin(), row.end());
        }

        for (int k = 0;k<n;k++) {
            int i = 0, j = 0;
            while (i < m) {
                j = i;
                while (j < m && rb[j][k] != '*') {
                    j++;
                }
                move(rb,i,j,k);
                i = j + 1;
            }
        }
        return rb;
    }
};
```

## Intuition
Brute force - rotate the matrix logic and then move the stones down until the stone or ground


## Complexity
- Time complexity: O(N*N)


- Space complexity: O(n*m)
