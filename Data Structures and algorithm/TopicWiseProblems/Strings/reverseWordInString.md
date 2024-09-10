# Reverse Word in String
[Problem Link](https://leetcode.com/problems/reverse-words-in-a-string/)

## Problem desciption 
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

### Example 2:

> **Input:** s = "  hello world  "<br>
> **Output:** "world hello"<br>
> **Explanation:** Your reversed string should not contain leading or trailing spaces<br>

## constraints


## Code
```cpp
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string ans="";
        int n = s.size();

        //remove trailing zeroes
        int i = 0,j=n-1;
        for(i = 0;i<n;i++) if(s[i] != ' ') break;
        for(j = n-1;j>=0;j--) if(s[j] != ' ') break;
        while(i<=j){
            string curr = "";
            int k = i;
            while( k<=j && s[k]!=' ') {
                curr+= s[k];
                k++;
            }
            reverse(curr.begin(),curr.end());
            ans+= curr;
            ans+= " ";
            i = k + 1;
            while(i<=j && s[i]==' ') i++;
        }
        ans.pop_back();
        return ans;
    }
};
```
```cpp

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string result = "";
        for (const char& ch : s) {
            if (ch != ' ') {
                result += ch;
            } 
            else if(!result.empty()){
                words.push_back(result);
                result = "";
            }
        }

        if (!result.empty()) {
            words.push_back(result);
            result = "";
        }

        for (int i = words.size() - 1; i >= 0; i--) {
            result += words[i];
            result += " ";
        }

        if(result.back() == ' '){
            result.pop_back();
        }

        return result;
    }
};

```

## Intuition


## Approach


## Complexity
- Time complexity:


- Space complexity:
