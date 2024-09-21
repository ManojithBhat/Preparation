# Lexicogrphic numbers
[Problem Link](https://leetcode.com/problems/lexicographical-numbers/description/?envType=daily-question&envId=2024-09-21)

## Problem desciption 
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

## Example 1:

**Input:** n = 13 <br>
**Output:** [1,10,11,12,13,2,3,4,5,6,7,8,9]

## constraints
* 1 <= n <= 5 * 104

## Code
```cpp
class Solution {
public:
    void dfs(int k,int n,vector<int>&res){
       if( k > n) return;
       res.push_back(k);

       for(int digit = 0 ; digit <= 9;digit++){
            int num = k*10 + digit;
            if(num > n) return;
            dfs(num,n,res);
       }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int st = 1;st<=9;st++) dfs(st,n,res);
        return res;
    }
};
```

## Intuition
DFS

## Approach


## Complexity
- Time complexity: O(n)


- Space complexity:O(1)
