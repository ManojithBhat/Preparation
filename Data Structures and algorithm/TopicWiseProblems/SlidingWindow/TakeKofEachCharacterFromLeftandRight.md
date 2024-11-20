# Take K of Each Character From Left and Right
[Problem Link](https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/submissions/1458115788/?envType=daily-question&envId=2024-11-20)

## Problem desciption 
You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.

Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.

### Example 1:

> **Input:** s = "aabaaaacaabc", k = 2<br>
> **Output:** 8<br>
> **Explanation:** <br>
> Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.<br>
> Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.<br>
> A total of 3 + 5 = 8 minutes is needed.<br>
> It can be proven that 8 is the minimum number of minutes needed.<br>


## constraints
* 1 <= s.length <= 105
* s consists of only the letters 'a', 'b', and 'c'.
* 0 <= k <= s.length

## Code
```cpp
class Solution {
public:
    int check(vector<int>& mp, vector<int>& hash) {

        for (int i = 0; i < 3; i++) {
            if (mp[i] > hash[i])
                return false;
        }
        return true;
    }

    int takeCharacters(string s, int k) {
        int i = 0, j = 0;
        int n = s.size();
        vector<int> hash(3, 0), mp(3, 0);
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            hash[s[i] - 'a']++;
        }

        for (int i = 0; i < 3; i++) {
            if (hash[i] - k < 0)
                return -1;
            hash[i] -= k;
        }

        while (j < n) {
            mp[s[j] - 'a']++;

            while (i <= j && !check(mp, hash)) {
                mp[s[i] - 'a']--;
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return n - maxLen;
    }
};
```

## Intuition
As we need to find the minimum number of minutes needed to take at least k of each character, i.e, to have a size of subarray that contains atleast k of a,b,c. so we will convert this question into find the maximum length of subarray that contains atmost k occurances of a,b and c. By this transformation we have modelled this question into variable sized sliding window technique. 

## Approach
Count all the occurences of a,b and c and check whether it is possible to obtain any the required result. If yes perform then sliding window technique and shrink the window acc to the condition and find out the maximum of all window size.

## Complexity
- Time complexity: O(N)


- Space complexity: O(1)
