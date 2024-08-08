# Spiral Matrix 3 
[https://leetcode.com/problems/spiral-matrix-iii/description/](problem link)


## Problem desciption 
You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.

Return an array of coordinates representing the positions of the grid in the order you visited them.

 
### Example 1:
Input: rows = 1, cols = 4, rStart = 0, cStart = 0
Output: [[0,0],[0,1],[0,2],[0,3]]

### Example 2:
Input: rows = 5, cols = 6, rStart = 1, cStart = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
 

## Constraints:
1 <= rows, cols <= 100
0 <= rStart < rows
0 <= cStart < cols


## Code
```

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> directions = {
            {0,1}, //Towards East
            {1,0}, //towards south
            {0,-1}, //towards west
            {-1,0}, //towards north
        };

        int dirn = 0; //initial movement is towards east
        int steps = 0;

        vector<vector<int>> result;
        result.push_back({rStart,cStart});

        while(result.size() < rows*cols){

            if(dirn == 0 || dirn == 2){
                steps++;
            }

            for(int cnt = 0;cnt<steps;cnt++){
                 rStart += directions[dirn][0];
                 cStart += directions[dirn][1];

                if(rStart>=0 && cStart>=0 && rStart<rows && cStart<cols){
                    result.push_back({rStart,cStart});
                }
            }

            dirn = (dirn+1)%4;
        }
        return result;
    }
};

```

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
As we need to travel in spiral way, and we are supposed to take turn at the variable len we need to keep track of 2 things, one - directions and the other is steps to be taken for each direction
* for the direction we have the vector representing the directions north , south , east and west
* the step length varies when ever it changes direction to the east or west  
* after every dirn we have to increase the dirn count

# Approach
<!-- Describe your approach to solving the problem. -->
we keep iterating until the size of the resultant vector becmes equal to the size of the matrix ( ie. row and column )
every time we have to check the direction to increase the count 
we iterate count/steps number of times and add to the cStart and rStart and put into the res only when it is in the range 

# Complexity
- Time complexity:
O((max(n,m))^2) - it is not conventional spiral matrix, the largest lenght would be max of n and m

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
O(1) - we are returning the answer 