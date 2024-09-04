# Walking robot simulation
[Problem Link](https://leetcode.com/problems/walking-robot-simulation/)

## Problem desciption 
A robot on an infinite XY-plane starts at point (0, 0) facing north. The robot can receive a sequence of these three possible types of commands:

- -2: Turn left 90 degrees.
- -1: Turn right 90 degrees.
1 <= k <= 9: Move forward k units, one unit at a time.

Some of the grid squares are obstacles. The ith obstacle is at grid point obstacles[i] = (xi, yi). If the robot runs into an obstacle, then it will instead stay in its current location and move on to the next command.

Return the maximum Euclidean distance that the robot ever gets from the origin squared (i.e. if the distance is 5, return 25).

Note:

* North means +Y direction.
* East means +X direction.
* South means -Y direction.
* West means -X direction.
* There can be obstacle in [0,0].
 
### Example 1:

> **Input:** commands = [4,-1,3], obstacles = []<br>
> **Output:** 25<br>
> **Explanation:** The robot starts at (0, 0):<br>
> 1. Move north 4 units to (0, 4).
> 2. Turn right.
> 3. Move east 3 units to (3, 4).<br>
> The furthest point the robot ever gets from the origin is (3, 4), which squared is 32 + 42 = 25 units away.


### Example 2:

>**Input:** commands = [4,-1,4,-2,4], obstacles = [[2,4]]<br>
>**Output:** 65<br>
>**Explanation:** The robot starts at (0, 0):<br>
>1. Move north 4 units to (0, 4).
>2. Turn right.
>3. Move east 1 unit and get blocked by the obstacle at (2, 4), robot is >at (1, 4).
>4. Turn left.
>5. Move north 4 units to (1, 8).<br>
>The furthest point the robot ever gets from the origin is (1, 8), which squared is 12 + 82 = 65 units away.

## constraints
* 1 <= commands.length <= 104
* commands[i] is either -2, -1, or an integer in the range [1, 9].
* 0 <= obstacles.length <= 104
* -3 * 104 <= xi, yi <= 3 * 104
* The answer is guaranteed to be less than 231.


## Code
```cpp
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<vector<int>> dirn = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dirnptr = 0;
        int maxDist = 0;
        set<vector<int>>st;
        for (auto it : obstacles)
            st.insert(it);

        int n = commands.size();
        int coorx = 0, coory = 0;

        for (int i = 0; i < n; i++) {
            //cout<<dirnptr<<endl;
            if (commands[i] == -1) {
                // turn to right
                dirnptr = (dirnptr + 1) % 4;
            } else if (commands[i] == -2) {
                // turn to left
                dirnptr = (dirnptr - 1) % 4;
                if(dirnptr < 0) dirnptr += 4;
            } else {
                // move in some distance.

                while (commands[i] != 0) {
                    coorx = dirn[dirnptr][0] + coorx;
                    coory = dirn[dirnptr][1] + coory;

                    if (st.find({coorx, coory}) != st.end())
                    {
                        coorx = -dirn[dirnptr][0] + coorx;
                        coory = -dirn[dirnptr][1] + coory;
                        break;
                    }
                    commands[i]--;
                }
            }
            //cout<<coorx<<" "<<coory<<endl;
            
            maxDist = max(maxDist,coorx * coorx + coory * coory);
        }
        return maxDist;
    }
};
```

## Intuition
As we need to keep track of the obstacles as we travel, we keep a set datastructure to keep track of all the coordinates. when ever we encounter obstacle, we move a step backward and continue our travel. We also use vector<vector<int>> dirn that keeps the constant to add according to the direction.For example

{0,1}=> north traversal as we need to move in +y direction for x

we perform the same for all the four direction.

We also keep a direction pointer dirnptr which keep track of the current direction we are in. we initialise it to 0 ( pointing to the north ). The array has coordinates such that when incremented by 1 in circular manner we move in righ direction and when decremented we move to left in circular manner. A case is handled where dirn = - 1 is converted back to 3 by adding 4.

## Approach


## Complexity
- Time complexity:


- Space complexity:
