# Group Anagram 
[Problem Link](https://leetcode.com/problems/group-anagrams/description/)

## Problem desciption 
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

### Example 1:

**Input:** strs = ["eat","tea","tan","ate","nat","bat"]<br>
**Output:** [["bat"],["nat","tan"],["ate","eat","tea"]]<br>

### Example 2

**Input:** strs = [""]<br>
**Output:** [[""]]<br>

### Example 3:

**Input:** strs = ["a"]<br>
**Output:** [["a"]]<br>



## constraints
* 1 <= strs.length <= 104
* 0 <= strs[i].length <= 100
* strs[i] consists of lowercase English letters.

## Code
```cpp

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,int>mp;
        vector<vector<string>> ans;

        for(int i=0;i<strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            //if the string is already present in the map then 
            if(mp.find(temp)!=mp.end()){
                ans[mp[temp]].push_back(strs[i]);
            }
            else{
                mp[temp] = ans.size();
                ans.push_back({strs[i]});
            }
        }
        return ans;
    }
};

```

## Intuition
The intution is that anagrams are ```An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.``` So sorted anagram are always the same, so keeping a map in which sorted string is key is the key idea to note. 

## Approach

We keep an unordered_map to keep the list of all anagrams or basically to group it. when we find the string whch is not there in the map, we mark that string in the map and add to the array, next time, when we encounter the sorted string is already present in the map, we index it through the ``` size of the array ``` and push it.


## Complexity
- Time complexity: O(N)


- Space complexity: O(N)
