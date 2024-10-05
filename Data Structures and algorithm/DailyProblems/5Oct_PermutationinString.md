# Permutation in string
[Problem Link](https://leetcode.com/problems/permutation-in-string/description/)

## Problem desciption 
Given two strings s1 and s2, return true if s2 contains a 
permutation
 of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

## Example 1:

**Input:** s1 = "ab", s2 = "eidbaooo"<br>
**Output:** true<br>
**Explanation:** s2 contains one permutation of s1 ("ba").

## constraints
* 1 <= s1.length, s2.length <= 104
* s1 and s2 consist of lowercase English letters.

## Code
```cpp
class Solution {
public:
    bool compare(vector<int>& freq, vector<int>& freq1) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] != freq1[i])
                return false;
        }
        //cout<<endl;
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0), mp(26, 0);
        for (char ch : s1) {
            freq[ch - 'a']++;
        }

        int i = 0, j = 0;
        int n = s2.size(), m = s1.size();

        while (j < n) {
            mp[s2[j] - 'a']++;

            if (j - i + 1 == m) {
                if (compare(freq,mp) == true)
                    return true;
                mp[s2[i] - 'a']--;
                i++;
            }

            j++;
        }
        return false;
    }
};

```

## Intuition
We need to find a substring, so a sliding window approach seems appropriate. We can maintain a frequency map to track the characters and their frequencies. Since we are looking for a subarray of s1 within s2, the window size should be fixed to the length of s1.

Using this fixed-size sliding window approach, we will check if the frequency map of the current window in s2 matches the frequency map of s1. If they match, we return true. If no match is found, we continue sliding the window and return false if no valid match exists.

## Approach
We will use two frequency arrays, freq and mp. As we slide the window across s2 (of size equal to s1), we compare these arrays. If they match, we have found the substring; otherwise, we continue until the window has traversed all of s2.

## Complexity
- Time complexity: O(N)


- Space complexity: O(26)
