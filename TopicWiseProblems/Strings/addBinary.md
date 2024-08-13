# Add Binary
[Problem Link](https://leetcode.com/problems/add-binary/)

## Problem desciption 
Given two binary strings a and b, return their sum as a binary string.

### Example 1:

> **Input:** a = "11", b = "1" <br>
> **Output:** "100"

## constraints
* 1 <= a.length, b.length <= 104
* a and b consist only of '0' or '1' characters.
* Each string does not contain leading zeros except for the zero itself.

## Code
```cpp

class Solution {
public:
    int convertToDecimal(string num){
        int decimal = 0;
        int pow2 = 0;
        reverse(num.begin(),num.end());
        for(int i=0;i<num.size();i++){
            decimal += (num[i]-'0')*pow(2,pow2);
            pow2++;
        }
        return decimal;
    }

    string convertToBinary(int res){


        string binary  = "";
        while(res!=0){
            binary += (res%2 + '0');
            res /= 2;
        }
        reverse(binary.begin(),binary.end());
        return binary;
    }

    string addBinary(string a, string b) {

        //this doesnt work - gives tle 
        /*
        if(a == "0" && b == "0") return "0";
        int numA = convertToDecimal(a);
        int numB = convertToDecimal(b);

        int res = numA + numB;
        return convertToBinary(res);
        */

        //This problem is a pattern for adding 2 binary numbers or linked list 
        string ans = "";
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;

        while(i>=0 || j>=0 || carry){
            int sum = 0;
            if(i>=0){
                sum += (a[i--]-'0');
            }   
            if(j>=0){
                sum += (b[j--]-'0');
            }
            sum += carry;
            carry = sum/2;
            ans += to_string(sum%2);
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};

```

## Intuition


## Approach


## Complexity
- Time complexity: O(N)


- Space complexity: O(1)
