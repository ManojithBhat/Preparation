# 2696. Minimum String Length After Removing Substrings
[Problem Link](https://leetcode.com/problems/minimum-string-length-after-removing-substrings/?envType=daily-question&envId=2024-10-07)

## Problem desciption 
You are given a string s consisting only of uppercase English letters.

You can apply some operations to this string where, in one operation, you can remove any occurrence of one of the substrings "AB" or "CD" from s.

Return the minimum possible length of the resulting string that you can obtain.

Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.

 

### Example 1:

> **Input:** s = "ABFCACDB"<br>
>**Output:** 2<br>
>**Explanation:** We can do the following operations:<br>
>- Remove the substring "ABFCACDB", so s = "FCACDB".<br>
> - Remove the substring "FCACDB", so s = "FCAB".<br>
> - Remove the substring "FCAB", so s = "FC".<br>
> So the resulting length of the string is 2.<br>
> It can be shown that it is the minimum length that we can obtain.<br>


## constraints
* 1 <= s.length <= 100
* s consists only of uppercase English letters.

## Code
```cpp
class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(!st.empty() && (( s[i]=='B' && st.top() == 'A') || s[i] == 'D' && st.top() == 'C')){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        return st.size();
    }
};
```

## Intuition
As we are supposed to remove the character even after removing a part hence stack would be a better option since it can keep track of the previous characters as its top element, if not so then we could have used sliding window. 

## Approach
Intialise and declare a stack of characters, now if the stack is not empty and if the current element is ``B`` and the previous element is ``A`` then we will pop out be similarly if the curr element is ``D`` and previous element is ``C`` then we will pop out this too and wont push curr element as it is removed part, if not push the element to the stak. at last return the size of the stack. 


## Complexity
- Time complexity: O(N)


- Space complexity: O(N)
