# Parsing a Boolean Expression
[Problem Link](https://leetcode.com/problems/parsing-a-boolean-expression/?envType=daily-question&envId=2024-10-20)

## Problem desciption 

A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

* 't' that evaluates to true.
* 'f' that evaluates to false.
* '!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
* '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
* '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
Given a string expression that represents a boolean expression, return the evaluation of that expression.

It is guaranteed that the given expression is valid and follows the given rules.

 
### Example 1:

**Input:** expression = "&(|(f))"<br>
**Output:** false<br>
**Explanation:** 
First, evaluate |(f) --> f. The expression is now "&(f)".<br>
Then, evaluate &(f) --> f. The expression is now "f".<br>
Finally, return false.<br>

## constraints
* 1 <= expression.length <= 2 * 104
* expression[i] is one following characters: '(', ')', '&', '|', '!', 't', 'f', and ','.

## Code
```cpp
class Solution {
public:
    char operation(char op,char arg1,char arg2){
        if(op == '|'){
            if(arg1 == 'f' && arg2 =='f') return 'f';
            return 't';
        }
        else if(op == '&'){
            if(arg1 == 't' && arg2 == 't') return 't';
            return 'f';
        }
        
        if(arg1 == 't') return 'f';
        return 't';
        
    }

    bool parseBoolExpr(string exp) {
        stack<char> st,stOp;

        int i = 0;
        int n = exp.size();
        
        for(int i = 0;i<n;i++){
            if(exp[i] == ',') continue;
            if(exp[i] == '&' || exp[i] == '|' || exp[i] == '!'){
                stOp.push(exp[i]);
            }
            else if(exp[i] == '(') st.push(exp[i]);
            else if(exp[i] == 't' || exp[i] == 'f'){
                st.push(exp[i]);
            }
            else{
                while(!st.empty() && st.top()!='('){
                    
                    char fchar = st.top();
                    st.pop();
                    char schar = st.top();
                    st.pop();

                    char op = stOp.top();

                    if(schar != '('){
                        st.push(operation(op,fchar,schar));
                    }else{
                        if(op == '!'){
                            fchar = operation(op,fchar,schar);
                        }
                        stOp.pop();
                        st.push(fchar);
                        break;
                    }
                }
            }
           
        }
        if( st.top() == 't') return true;
        else return false;
    }
};
```

## Intuition
I have used two stacks one to store the operator and the other to store the brackets and expression, however we can use a single stack and use the vector to store all the expression and then use the opertor to traverse them. it is more optimisied then what i have solved.


## Complexity
- Time complexity: o(n^2)


- Space complexity: O(n)
