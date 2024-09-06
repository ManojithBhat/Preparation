# Most Stones Removed with Same Row or Column
[Problem Link](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/?envType=daily-question&envId=2024-08-29)

## Problem desciption 
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 
 ### Example 1:

**Input:** stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]<br>
**Output:** 5<br>
**Explanation:** One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.


## constraints
* 1 <= stones.length <= 1000
* 0 <= xi, yi <= 104
* No two stones are at the same coordinate point.

## Code
```cpp

  int n;
        void dfs(vector<vector<int>> & stones, int index,
                 vector<bool>& visited) {
            visited[index] = true;

            for (int i = 0; i < n; i++) {
                if (!visited[i] && ((stones[i][0] == stones[index][0]) ||
                                    (stones[i][1] == stones[index][1]))) {
                    dfs(stones, i, visited);
                }
            }
        }
        int removeStones(vector<vector<int>> & stones) {
            n = stones.size();
            vector<bool> visited(n, false);

            int count = 0;
            for (int i = 0; i < n; i++) {
                if (visited[i])
                    continue;
                dfs(stones, i, visited);
                count++;
            }

            return n - count;
        }

```

## Intuition
we have to make a group and the total number of deletion is equal to n - (grps formed)
we do the dfs traversal to find the same row and col and mark them as the grp and find the number of grps


## Complexity 
- Time complexity: O(N^2)


- Space complexity: O(N)
