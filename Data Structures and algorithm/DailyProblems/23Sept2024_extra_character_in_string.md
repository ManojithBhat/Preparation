# Extra Characters in a String
[Problem Link](https://leetcode.com/problems/extra-characters-in-a-string/description/?envType=daily-question&envId=2024-09-23)

## Problem desciption 
You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

Return the minimum number of extra characters left over if you break up s optimally.

 

### Example 1:

**Input:** s = "leetscode", dictionary = ["leet","code","leetcode"]<br>
**Output:** 1<br>
**Explanation:** We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.



## constraints

* 1 <= s.length <= 50
* 1 <= dictionary.length <= 50
* 1 <= dictionary[i].length <= 50
* dictionary[i] and s consists of only lowercase English letters
* dictionary contains distinct words

## Code
```cpp
class Solution {
public:
    int dp[51];
    int solve(int ind,string& s,unordered_map<string,int> &mp){
        int n = s.size();
        if(ind == n) return 0;

        if(dp[ind]!=-1) return dp[ind];
        //skip the current element thinking that it is not ther 
        int result = 1 + solve(ind+1,s,mp);

        //let us check if the string exist
        for(int i = ind;i<n;i++){
            string tmp = s.substr(ind,i - ind+1);
            if(mp.find(tmp)!=mp.end()){
                result = min(result,solve(i+1,s,mp));
            }
        }
        return dp[ind] = result;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, int> mp;
        for(auto it: dictionary) mp[it] = it.size();

        memset(dp,-1,sizeof(dp));
        int n = s.size();
        int len = solve(0,s,mp);
        return len;
    }
};
```

## Intuition
a pick not pick logic where we assume that current index isnt there in the dict and it will be ther and do the same 


## Complexity
- Time complexity: O(N2)


- Space complexity: O(N)
