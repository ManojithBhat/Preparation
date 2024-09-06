# minimum deletions to make character frequencies unique
[Problem Link](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/)

## Problem desciption 
A string s is called good if there are no two different characters in s that have the same frequency.

Given a string s, return the minimum number of characters you need to delete to make s good.

The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

### Example 1:

Input: s = "aab"
Output: 0
Explanation: s is already good.

### Example 2:

Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".

## constraints
* 1 <= s.length <= 105
* s contains only lowercase English letters

## Code
```cpp
class Solution {
public:
    int minDeletions(string s) {
        /* my first accepted solution _ inefficient as always :(
        unordered_map<char,int> freq;
        for(auto it: s) freq[it]++;

        vector<int> arr(freq.size());
        set<int> st;
        for(auto it: freq) {
            arr.push_back(it.second);
            st.insert(it.second);
        }

        if(st.size() == arr.size()) return 0;

        sort(arr.begin(),arr.end());
        int cnt = 0;
        for(int i = 0;i<arr.size()-1;i++){
            if(arr[i] == arr[i+1]){
                int nums = arr[i+1];
                int cntr = 0;
                while(st.find(nums)!=st.end()){
                    cntr++;
                    nums--;
                }
                if(nums!=0){
                    st.insert(nums);
                }
                cnt += cntr;
            }
        }
        return cnt;
    */

        /*
            // without the use of greedy technique
            int freq[26]={0};
            for (int i = 0; i < s.size(); i++)
                freq[s[i] - 'a']++;

            unordered_set<int> st;
            int result = 0;
            for (int i = 0; i < 26; i++) {
                while(freq[i] > 0 && st.find(freq[i]) != st.end() ){
                    result++;
                    freq[i]--;
                }

                st.insert(freq[i]);
            }
            return result;
        */

        // using greedy technique and hash map
        int freq[26] = {0};
        for (int i = 0; i < s.size(); i++)
            freq[s[i] - 'a']++;

        sort(freq,freq+26);
        int result = 0;
        for(int i = 24;i>=0 && freq[i]>0;i--){

            if(freq[i] >= freq[i+1]){
                int preval = freq[i];
                freq[i] = max(0,freq[i+1]-1);
                result += preval - freq[i];
            }
        }
        return result;
    }
};

```

## Intuition
We will create the frequency array ( as we need to operate on the frequencis of the elements ), then we traverse throught the frequecny array, if the frequency is not present in the array we add it into the set, if else we try to reduce ( as we can reduce that only ) and increment the count untill all the character are exhausted. 

The second approcah is the greedier one, where we try to sort by frequency and if the frequency of curr is greater than the next one which means there is someone who is greater than the current one. so we dedcut one by the next one or do it 0 and take the diff of previous value to the curr value as the decremental number. 
``` bash
`
Take for example : 0 0 0 0 2 2 2 3
after doing x operation  0 0 0 0 2 | 0 1 2 3 

note that it is increasing ...

```

## Complexity
- Time complexity: O(nlogn) in case of greedy 


- Space complexity: O(26) 
