#  Find the Length of the Longest Common Prefix
[Problem Link](https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/?envType=daily-question&envId=2024-09-24)

## Problem desciption 
You are given two arrays with positive integers arr1 and arr2.

A prefix of a positive integer is an integer formed by one or more of its digits, starting from its leftmost digit. For example, 123 is a prefix of the integer 12345, while 234 is not.

A common prefix of two integers a and b is an integer c, such that c is a prefix of both a and b. For example, 5655359 and 56554 have a common prefix 565 while 1223 and 43456 do not have a common prefix.

You need to find the length of the longest common prefix between all pairs of integers (x, y) such that x belongs to arr1 and y belongs to arr2.

Return the length of the longest common prefix among all pairs. If no common prefix exists among them, return 0.

 

### Example 1:

> **Input:** arr1 = [1,10,100], arr2 = [1000]<br>
> **Output:** 3<br>
> **Explanation:** There are 3 pairs (arr1[i], arr2[j]):<br>
> - The longest common prefix of (1, 1000) is 1.<br>
> - The longest common prefix of (10, 1000) is 10.<br>
> - The longest common prefix of (100, 1000) is 100.<br>
> The longest common prefix is 100 with a length of 3.<br>


## constraints

* 1 <= arr1.length, arr2.length <= 5 * 104
* 1 <= arr1[i], arr2[i] <= 108

## Code

```cpp

 /* BRUTE FORCE APPROACH - GIVES TLE*/
     int solve(string t,string s){
         int n = t.size();
         int m = s.size();
         int cnt = 0;
         int i = 0;
         while(i < n && i<m){
             if(t[i]!=s[i]) break;
             cnt++;
             i++;
         }
         return cnt;
     }

     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
         int n = arr1.size();
         int m = arr2.size();

         int maxPrefix = 0;
         for(int i = 0;i<m;i++){
             string t = to_string(arr2[i]);
             for(int j = 0;j<n;j++){
                 string k = to_string(arr1[j]);
                 maxPrefix = max(maxPrefix,solve(t,k));
             }
         }
         return maxPrefix;
     }


```

```cpp
 /* OPTIMAL APPROACH - USING SET TO STORE THE PREFIX */
     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st; //O(total length of all the prefix)

        //generate all the prefix from the array1
        //{12345} => {12345,1234,123,12,1} are the prefix
        for(auto num:arr1){
            while(!st.count(num) && num>0){
                st.insert(num);
                num/=10;
            }
        }

        int maxPrefix = 0;
        //now generate the prefix in array2 and check in the set
        for(int val: arr2){
            while(!st.count(val) && val>0){
                val/=10;
            }
            if(val > 0){
                maxPrefix = max(maxPrefix,static_cast<int>(log10(val))+1);
            }
        }
        return maxPrefix;
    }
```

```cpp
//template for node implementation
struct TrieNode{
    //char data;
    TrieNode* children[10];
};

class Solution {
public:
   
    //code for trie
    TrieNode* getTrieNode(){
        //creates a node with all initialised to null
        TrieNode* node = new TrieNode();
        for(int i = 0;i<10;i++){
            node->children[i] = nullptr;
        }
        return node;
    }

    void insert(int num,TrieNode* root){
        string numStr = to_string(num);
        TrieNode* crawl = root;

        //traverse through the every character and construct node for the same if not present
        for(char ch: numStr){
            int idx = ch-'0'; //get the index 
            if(crawl->children[idx]==nullptr){
                //create a node for this character 
                crawl->children[idx] = new TrieNode();
            }
            crawl = crawl->children[idx] ;
        }
    }

    int traverse(int num,TrieNode* root){
        string strNum = to_string(num);
        TrieNode* crawl = root; //crawler is used to traverse the trie
        int len = 0;

        for(char ch : strNum){
            int idx = ch-'0';
            if(crawl->children[idx]!=nullptr){
                len++;
                crawl = crawl->children[idx];
            }else{
                break;
            }
        }
        return len;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = new TrieNode();

        for(int num: arr1){
            insert(num,root);
        }

        int maxLen = 0;
        for(int num: arr2){
            maxLen = max(maxLen,traverse(num,root));
        }

        return maxLen;
    }
};
```

## Intuition
Two key takeaways from the problem
* We can do static_cast<int>(log10(num))+1 to get the number of digits in the number
* How to find the prefix subarray


## Complexity 
- Time complexity: O(n*d + N*D) where n and M are array size and d and D represents the max prefixes from the number


- Space complexity: O(N*8) as max it can have 8 digits ( 10^8 ) and there are n elements.
