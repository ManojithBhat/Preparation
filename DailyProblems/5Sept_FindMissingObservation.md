# Finding Missing Observation
[Problem Link](https://leetcode.com/problems/find-missing-observations/description/)

## Problem desciption 
You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. n of the observations went missing, and you only have the observations of m rolls. Fortunately, you have also calculated the average value of the n + m rolls.

You are given an integer array rolls of length m where rolls[i] is the value of the ith observation. You are also given the two integers mean and n.

Return an array of length n containing the missing observations such that the average value of the n + m rolls is exactly mean. If there are multiple valid answers, return any of them. If no such array exists, return an empty array.

The average value of a set of k numbers is the sum of the numbers divided by k.

Note that mean is an integer, so the sum of the n + m rolls should be divisible by n + m.

### Example 1:

> **Input:** rolls = [3,2,4,3], mean = 4, n = 2<br>
> **Output:** [6,6]<br>
> **Explanation:** The mean of all n + m rolls is (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4.


### Example 2:

> **Input:** rolls = [1,5,6], mean = 3, n = 4<br>
> **Output:** [2,3,2,2]<br>
> **Explanation:** The mean of all n + m rolls is (1 + 5 + 6 + 2 + 3 + 2 + 2) / 7 = 3.


## constraints
* m == rolls.length
* 1 <= n, m <= 105
* 1 <= rolls[i], mean <= 6


## Code
```cpp
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        int m = rolls.size();
        for(int i = 0;i<m;i++) sum+=rolls[i];
        int remSum = (n+m)*mean - sum;
        //now the problem is finding n elements such that it adds up to remsum and the numbers are between 1 and 6;
        if(remSum > 6*n || remSum < n) return {};
        vector<int> res;
        
        for(int i=0;i<n;i++){
            int size = 6;
            while(size){
                if(remSum - size >= n - i - 1){
                    res.push_back(size);
                    remSum -= size;
                    break;
                }
                size--;
            }
        }
        return res;
    }
};

```

## Intuition
The problem requires us to find n elements such that elemnts sum up to (n+m)*mean - sum. Now, what we do is we first try to assign the max Number ie. 6 and so on greedly, but only when if i am able to distribute atleast 1 to the remaining n - i - 1 elements, if it is not possible then we decrease max Number by one and try that.
The edge case is to return empty array when i can't assign atleast 1 to all the elements or when I can't satisfy even by assigning max ( ie. 6 ) to every elements.


## Complexity
- Time complexity: O(n)

- Space complexity: O(1)
