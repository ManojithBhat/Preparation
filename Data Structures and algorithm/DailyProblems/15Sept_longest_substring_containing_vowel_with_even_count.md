# Find the Longest Substring Containing Vowels in Even Counts
[Problem Link](https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/?envType=daily-question&envId=2024-09-15)

## Problem desciption 

Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

### Example 1:

**Input:** s = "eleetminicoworoep"
**Output:** 13
**Explanation:** The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.

## constraints
* 1 <= s.length <= 5 x 10^5
* s contains only lowercase English letters.

## Code
```cpp
class Solution {
public:
    int findTheLongestSubstring(string s) {
        //represent each state as 0/1, if 0 means even and 1 means odd;
        //do it as a prefix sum calc 
        unordered_map<string,int>mp;
        string iniOrder = "00000";
        vector<int> state(5,0);
        mp[iniOrder] = -1;
        
        int n = s.size();
        int maxLen = 0 ;
        for(int i = 0;i<n;i++){
            if(s[i] == 'a'){
                state[0] = state[0]^1;
            }
            else if(s[i] == 'e'){
                state[1] = state[1]^1;
            }
            else if(s[i] == 'i'){
                state[2] = state[2]^1;
            }
            else if(s[i] == 'o'){
                state[3] = state[3]^1;
            }
            else if(s[i] == 'u'){
                state[4] = state[4]^1;
            }

            string curOrder = "";
            for(int i = 0;i<5;i++){
                curOrder += to_string(state[i]);
            }

            if(mp.find(curOrder)!=mp.end()){
                maxLen = max(maxLen, i - mp[curOrder]);
            }else{
                mp[curOrder] = i;
            }
        }

        return maxLen;
    }
};

```

## Intuition
The sliding window approach doesnt work here, because there is no fixed paraemeter from where you try to reduce the window size, thus we use similar concept of prefix sum, we keep a parameter of string of whether we have achieved the even count of character for example 1 for odd n 0 for even, first we set and push 00000 as the initial state, then whenver we find any vowel we make the state of that xor by 1 for ``` a e i o u => 0 0 0 0 0```... if there is a odd count of a and e and even count of i the state would be ```a e i o u => 1 1 0 0 0``` and by comparing the map, we find the length of the subarray

## Approach


## Complexity
- Time complexity: O(N)


- Space complexity: O(N)
