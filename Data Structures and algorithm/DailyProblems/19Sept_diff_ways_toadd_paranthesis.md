# Different ways to add paranthesies
[Problem Link](https://leetcode.com/problems/different-ways-to-add-parentheses/description/?envType=daily-question&envId=2024-09-19)

## Problem desciption 
Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.

### Example 2:

> **Input:** expression = "2*3-4*5"<br>
**Output:** [-34,-14,-10,-10,10]<br>
**Explanation:**<br>
(2*(3-(4*5))) = -34 <br>
((2*3)-(4*5)) = -14 <br>
((2*(3-4))*5) = -10 <br>
(2*((3-4)*5)) = -10 <br>
(((2*3)-4)*5) = 10<br>


## constraints

* 1 <= expression.length <= 20
* expression consists of digits and the operator '+', '-', and '*'.
* All the integer values in the input expression are in the range [0, 99].
* The integer values in the input expression do not have a leading '-' or '+' denoting the sign.

## Code
```cpp
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for (int i = 0; i < expression.size(); ++i) {
            char oper = expression[i];
            if (oper == '+' || oper == '-' || oper == '*') {
                vector<int> s1 = diffWaysToCompute(expression.substr(0, i));
                vector<int> s2 = diffWaysToCompute(expression.substr(i + 1));
                for (int a : s1) {
                    for (int b : s2) {
                        if (oper == '+') res.push_back(a + b);
                        else if (oper == '-') res.push_back(a - b);
                        else if (oper == '*') res.push_back(a * b);
                    }
                }
            }
        }
        if (res.empty()) res.push_back(stoi(expression));
        return res;
    }
};
```

## Intuition


## Approach


## Complexity
- Time complexity:


- Space complexity:
