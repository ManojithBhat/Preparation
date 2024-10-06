# Sentence Similarity 3

[Problem Link](https://leetcode.com/problems/sentence-similarity-iii/description/?envType=daily-question&envId=2024-10-06)

## Problem desciption 
You are given two strings sentence1 and sentence2, each representing a sentence composed of words. A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of only uppercase and lowercase English characters.

Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. Note that the inserted sentence must be separated from existing words by spaces.

For example,

s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in s1.
s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although there is a sentence "s are" inserted into s1, it is not separated from "Frog" by a space.
Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.

### Example 1:

> **Input:** sentence1 = "My name is Haley", sentence2 = "My Haley"<br>
**Output:** true<br>
**Explanation:**
sentence2 can be turned to sentence1 by inserting "name is" between "My" and "Haley".<br>

### Example 2:
> **Input:** sentence1 = "of", sentence2 = "A lot of words"<br>
**Output:** false<br>
**Explanation:**
No single sentence can be inserted inside one of the sentences to make it equal to the other.<br>

### Example 3:
> **Input:** sentence1 = "Eating right now", sentence2 = "Eating"<br>
**Output:** true<br>
**Explanation:**
sentence2 can be turned to sentence1 by inserting "right now" at the end of the sentence.<br>


## constraints
* 1 <= sentence1.length, sentence2.length <= 100
* sentence1 and sentence2 consist of lowercase and uppercase English letters and spaces.
* The words in sentence1 and sentence2 are separated by a single space.

## Code
```cpp
class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.length() < s2.length()) {
            swap(s1, s2);
        }

        //keep the longest string as s1 and smallest as s2

        vector<string> vec1, vec2;
        stringstream ss1(s1);
        string token;
        while(ss1 >> token) {
            vec1.push_back(token);
        }

        stringstream ss2(s2);
        while(ss2 >> token) {
            vec2.push_back(token);
        }

        int i = 0, j = vec1.size()-1; //s1 (vec1)
        int k = 0, l = vec2.size()-1; //s2 (vec2)
        //start comparing from the start and the end if j cross i then we can add sentence in between to make it to sentence 2 or else we cant 
        while(k < vec2.size() && i < vec1.size() && vec2[k] == vec1[i]) {
            k++;
            i++;
        }

        while(l >= k && vec2[l] == vec1[j]) {
            j--;
            l--;
        }
        return l < k;
    }
};
```

## Complexity
- Time complexity: O(n+m)

- Space complexity:O(m+n)
