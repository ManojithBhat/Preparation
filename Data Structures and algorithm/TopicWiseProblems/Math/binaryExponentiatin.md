# Pow(x, n)
[Problem Link](https://leetcode.com/problems/powx-n/description/)

## Problem desciption 
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).


## constraints
* -100.0 < x < 100.0
* -231 <= n <= 231-1
* n is an integer.
* Either x is not zero or n > 0.
* -104 <= xn <= 104

## Code
```cpp
class Solution {
public:
    double binaryExponent(double a, long long n){
        if(n == 0) return 1;

        double res = binaryExponent(a,n/2);

        if(n%2){
            return res*res*a;
        }
        return res*res;
    }

    double myPow(double x, int n) {
        long long m = n;
        if( m < 0){
            m = m*-1;
            x = 1/x;
        }

        return binaryExponent(x,m);
    }
};
```

## Intuition
The computation of power for higher number takes o(N) time, but this can be bougth down to logn time.
any exponent power can be broken down into n/2 and n/2 if n is even and n/2, n/2 and 1 if its odd. so we can peform recursion.      

## Approach
refer this [reference resource](https://cp-algorithms.com/algebra/binary-exp.html)

## Complexity
- Time complexity: O(NLogN)


- Space complexity: O(1)
