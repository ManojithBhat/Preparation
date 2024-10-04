# Divide player into equal skill
[Problem Link](https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/?envType=daily-question&envId=2024-10-04)

## Problem desciption 
You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.

The chemistry of a team is equal to the product of the skills of the players on that team.

Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.

### Example 1:

**Input:** skill = [3,2,5,1,3,4]<br>
**Output:** 22<br>
**Explanation:** <br>
Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where each team has a total skill of 6.
The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.


## constraints

* 2 <= skill.length <= 105
* skill.length is even.
* 1 <= skill[i] <= 1000

## Code
```cpp
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(),skill.end());

        long long skillSum = skill[0] + skill[n-1];
        long long chemistry = 0;
        for(int i = 0;i<n/2;i++){
            if(skill[i] + skill[n-i-1] != skillSum ) return -1;
            chemistry += (skill[i]*skill[n-i-1]);
        }
        return chemistry;
    }
};

```

## Intuition
In order to pick the sum should be equal the only way to pick is one from end and other from the start. If not let us assume that we pick last and mid element now when we pick the first element there has to be an element that is greater than the last element to equalise the sum, hence we take last and first element.


The other would be to use the map and find the target that is the sum for each pair - current element. the sum for each pair would be the sum/(n/2). If the sum is odd we can return that is not possible, we can keep checking the map.


## Complexity
- Time complexity: O(NlogN)


- Space complexity: O(1)
