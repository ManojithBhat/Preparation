# Largest number in K swaps
[Problem Link](https://www.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1)

## Problem desciption 
Given a number k and string s of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of s at most k times.


## constraints
1 ≤ s.size() ≤ 15
1 ≤ k ≤ 7

## Examples

**Input:** s = "1234567", k = 4<br>
**Output:** 7654321<br>
**Explanation:** Three swaps can make the input 1234567 to 7654321, swapping 1 with 7, 2 with 6 and finally 3 with 5.<br>


**Input:** s = "3435335", k = 3<br>
**Output:** 5543333<br>
**Explanation:** Three swaps can make the input 3435335 to 5543333, swapping 3 with 5, 4 with 5 and finally 3 with 4.<br>

**Input:** s = "1034", k = 2<br>
**Output:** 4301<br>
**Explanation:** Two swaps can make the input 1034 to 4301, swapping 1 with 4 and finally 0 with 3. <br>

## Code
```cpp
class Solution {
  public:
    // Function to find the largest number after k swaps.
    void solve(int idx, int k, string s, string &ans){
        if(k==0 || idx==s.size()){
            if(s>ans) ans = s;
            return;
        }
        for(int i = idx; i<s.length();i++){
            if(s[i]>s[idx]){
                swap(s[i],s[idx]);
                solve(idx+1,k-1,s,ans);
                swap(s[i],s[idx]);
            }
            solve(i+1,k,s,ans);
        }
    }
    string findMaximumNum(string& s, int k) {
        // code here.
        string ans = s;
        solve(0,k,s,ans);
        return ans;
    }
};
```

## Intuition
The core idea is to explore all possible swap combinations recursively, but with pruning to avoid unnecessary exploration.
At each position idx in the string, we want to place the largest available digit.
If a larger digit exists to the right of idx, we swap it with the digit at idx, decrement k, and recursively explore the remaining string.
If no larger digit exists, we move to the next position without performing a swap.
The recursion stops when we have exhausted all allowed swaps (k == 0) or reached the end of the string (idx == s.size()).

## Approach
findMaximumNum(string& s, int k): This is the main function that initiates the process.

It initializes ans with the original string s. This variable will store the largest number found so far.
It calls the solve function to recursively explore possible swaps.
Finally, it returns the ans string, which contains the largest number found.
solve(int idx, int k, string s, string &ans): This is the recursive function that explores the search space.

idx: The current index being considered.

k: The number of swaps remaining.

s: The current string.

ans: The largest string found so far (passed by reference to update it).

Base Case:

if(k==0 || idx==s.size()): If we run out of swaps or reach the end of the string, we check if the current string s is larger than the current largest string ans. If it is, we update ans.
Recursive Step:

for(int i = idx; i<s.length();i++): Iterate through the string from the current index idx to the end.
if(s[i]>s[idx]): If we find a digit s[i] to the right of idx that is larger than s[idx], we perform a swap.
swap(s[i],s[idx]): Swap the characters at indices i and idx.
solve(idx+1,k-1,s,ans): Recursively call solve for the next index idx+1, decrementing k because we used a swap.
swap(s[i],s[idx]): Backtrack: Swap the characters back to restore the original string for exploring other possibilities.
solve(i+1,k,s,ans): This line is crucial for exploring all possibilities. Even if we find a larger digit and swap it, we still need to consider the case where we don't swap and move on to the next position. This ensures that we explore all possible combinations of swaps. Critically, the index i+1 is passed here, not idx+1. This is because we want to explore the possibility of making swaps at indices after i, not just after idx.
4. Example

s = "129814999", k = 4
The algorithm will try to place the largest digit ('9') at the beginning, then the next largest, and so on, using swaps. The backtracking ensures all combinations are explored.
5. Key Concepts

Recursion: The problem is naturally solved using recursion because each swap leads to a subproblem of finding the largest number with the remaining swaps.
Backtracking: The swap operations are undone after each recursive call to explore other possibilities. This is essential for finding the optimal solution.
Greedy Approach with Exploration: The algorithm tries to place the largest available digit at each position (greedy), but it explores all possible combinations of swaps to ensure it finds the absolute largest number (not just a locally optimal one).
6. Potential Improvements/Considerations.
7. 

## Complexity
- Time complexity:


- Space complexity:
