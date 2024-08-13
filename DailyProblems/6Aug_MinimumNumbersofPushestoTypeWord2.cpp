#include<bits/stdc++.h>

/*
You are given a string word containing lowercase English letters.

Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .

It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.

Return the minimum number of pushes needed to type word after remapping the keys.

An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.


Input: word = "abcde"
Output: 5
Explanation: The remapped keypad given in the image provides the minimum cost.
"a" -> one push on key 2
"b" -> one push on key 3
"c" -> one push on key 4
"d" -> one push on key 5
"e" -> one push on key 6
Total cost is 1 + 1 + 1 + 1 + 1 = 5.
It can be shown that no other mapping can provide a lower cost.
*/

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;     
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<word.size();i++) mp[word[i]]++;  //O(N)
        for(auto it: mp){
            pq.push({it.second,it.first}); //O(NlogN)
        }

        int count = 0;
        int iter = 1;
        int maxPress = 0;
        while(!pq.empty()){  //O(N)
            int top = pq.top().first;
            pq.pop();
            if(count==8){
                iter++;
                count=0;
            }
            count++;
            maxPress+=iter*top;
        }
        return maxPress;
    }
};

/*
 
 Intution : 
    By the description it is clear that we need to minimise the number of pushes to type the world.
    so, the first thing that comes to mind is greedy approach, where as the number of pushes needs to be minimised, then we need to push the most frequent character first, so assigning the most frequent character the furst position will be the best appproach.
    so to keep the track of the frequency of the characters, i will be using the unordered_map.
    then to assign the most frequent character the first position, i will be using the max_heap, and assign the first 8 top element to the first 8 keys and then to the next 8 keys ( so push count will be 2 ..3 and so on)
    and by calculating the character count and the currPush we can achieve minimum number of pushes.

 */

/*
Time Complexity : O(NlogN) as we are using the priority queue to get the top element
Space Complexity : O(2*N) as we are using the unordered_map to store the frequency of the characters
*/

