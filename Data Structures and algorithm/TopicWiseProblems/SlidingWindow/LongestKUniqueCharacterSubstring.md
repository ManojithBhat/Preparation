# Longest K unique charachter substring
[Problem Link](https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1)

## Problem desciption 

Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.

## Example
**Input:**<br>
S = "aabacbebebe", K = 3<br>
**Output:** <br>
7<br>
**Explanation:** <br>
"cbebebe" is the longest substring with 3 distinct characters.<br>

## constraints
* 1 ≤ |S| ≤ 105
* 1 ≤ K ≤ 26
* All characters are lowercase latin characters.

## Code
```cpp
class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int n = s.size();
        unordered_map<char,int> mp;
        int i = 0,j = 0;
        int maxLen = -1;
        
        while(j<n){
            mp[s[j]]++;
            
            while(mp.size() > k){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            
            if(mp.size() == k) maxLen = max(j-i+1,maxLen);
            
            j++;
        }
        return maxLen;
    }
};
```

## Intuition
This is the standard template for the variable size sliding window, there is a calculation phase then if the condition go beyond the limit reduce the window size and then calculate for given condition. 


## Complexity
- Time complexity: O(N)


- Space complexity: O(k)
