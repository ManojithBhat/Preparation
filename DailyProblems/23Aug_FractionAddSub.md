# Fraction Addition and Subtraction
[Problem Link](https://leetcode.com/problems/fraction-addition-and-subtraction/description/?envType=daily-question&envId=2024-08-23)

## Problem desciption 
Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.

The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.


### Example 1:

> Input: expression = "-1/2+1/2"<br>
> Output: "0/1"<br>

### Example 2:

> Input: expression = "-1/2+1/2+1/3"<br>
> Output: "1/3"<br>

### Example 3:

> Input: expression = "1/3-1/2"<br>
> Output: "-1/6"<br>

## constraints
* The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
* Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
* The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
* The number of given fractions will be in the range [1, 10].
* The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.

## Code
```cpp
class Solution {
public:
    string fractionAddition(string expr) {
        int nume = 0;
        int deno = 1;

        int i = 0;
        int n = expr.length();
        while(i < n) {
            int currNume = 0;
            int currDeno = 0;

            bool isNeg = (expr[i] == '-');
            
            if(expr[i] == '+' || expr[i] == '-') {
                i++;
            }

            //Build the currNume
            while(i < n && isdigit(expr[i])) {
                int val = expr[i] - '0';
                currNume = (currNume*10) + val;
                i++;
            }

            i++; //numerator / denominator //skipiing the divisrio character '/'

            if(isNeg == true) {
                currNume *= -1;
            }

            //Build the currDeno
            while(i < n && isdigit(expr[i])) {
                int val = expr[i] - '0';
                currDeno = (currDeno * 10) + val;
                i++;
            }

            nume = nume * currDeno + currNume * deno;
            deno = deno * currDeno;
        }

        //num
        //deno
        //-3 / 6 //GCD : 3
        int GCD = abs(__gcd(nume, deno)); //3

        //this is for simplification 
        nume /= GCD; //-1
        deno /= GCD; //2

        return to_string(nume) + "/" + to_string(deno); //"-1/2"
    
    }
};

```

## Intuition
This is a simulation based solution comnined with the knowledge of mathematics
<br>
Key take aways from this problem 
* Learn to traverse and get the things. 
* Taking the gcd of both the numerator and denominator and dividing by that will result in the simplified form of the expression.
* taking numerator and denominator calculation separetely.
* handling the negative term case ( use different flag to handle this ).



## Complexity 
- Time complexity: O(N)


- Space complexity: O(1)
