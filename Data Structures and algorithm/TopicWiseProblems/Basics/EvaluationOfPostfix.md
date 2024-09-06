# Evaluation of postfix expression 
[Problem Link](https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1)

## Problem desciption 

Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.

### Example 1:

> **Input:** S = "231*+9-"<br>
> **Output:** -4<br>
> **Explanation:**
After solving the given expression, 
we have -4 as result.

## constraints
* 1 ≤ |S| ≤ 105
* 0 ≤ |Si|≤ 9 (And given operators)

## Code
```cpp
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> st;
        for(int i=0;i<S.length();i++){
            if(S[i]>='0'&&S[i]<='9'){
                st.push(S[i]-'0');
            }
            else{
                int operator2 = st.top();
                st.pop();
                int operator1 = st.top();
                st.pop();
                
                char ch = S[i];
                switch(ch){
                    case '+' : st.push(operator1+operator2);
                        break;
                    case '-' : st.push(operator1-operator2);
                        break;
                    case '*' : st.push(operator1 * operator2);
                        break;
                    case '/': st.push(operator1/operator2);
                        break;
                    default : st.push(operator1^operator2);
                        break;
                    }
            }
        }
        return st.top();
    }
};
```


## Complexity
- Time complexity: O(N)

- Space complexity: O(N)
