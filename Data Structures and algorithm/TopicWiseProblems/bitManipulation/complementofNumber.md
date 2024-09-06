# Complement of the number
[Problem Link](https://leetcode.com/problems/number-complement/description/?envType=daily-question&envId=2024-08-22)

## Problem desciption 
The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer num, return its complement.

### Example 1:

> **Input:** num = 5<br>
> **Output:** 2<br>
> Explanation: The binary representation of 5 is 101 (no  leading zero bits), and its complement is 010. So you need to  output 2.

## constraints
* 1 <= num < 2^31
  
## Code
```cpp
class Solution {
public:
    int findComplement(int num) {
        //approach 1

        int num_bits = (int)log2(num)+1;
        for(int i=0;i<num_bits;i++){
            num = num^(1<<i);
        }
        return num;

        //approach 2 
        int num_bits = (int)log2(num)+1;

        unsigned int mask = (1U << num_bits) - 1;

        return num^mask;

        //approach 3
        int i = 0;
        int complement = 0;

        while(num){
            if(!(num&1)){
                //get the last bit, if the bit value is 0, flip it
                complement |= (1<<i);
            }
            num = num>>1;
            i++;
        }
        return complement;
    }
};

```

## Intuition

**Approach 1**
As we need to compliment the digits, the first thing that should come to our mind is ```xor```  as xoring a number with 1 will flip the bit but there is a catch , we need to xor untill that bit untill where the digit is ranged for example 5 is 3 as it can be represented as 101.
for this reason we take the number of bits in a number by taking ```log2(num) + 1```, then we do xor operation by left shifting. 
<br>
1   0   1 <br>
After xoring with 1<<0 - 1 0 0 
similarly do for 3 times 

**Approach 2** -  bit masking 
<br>
This is the iteration over last approach. why can't we do 1 xor with all the element at once ? for that we use a concept of masking, that is we mask only those bits that needs to be xored. for this reason we mask by doing (1<<bit_len) this will make bits into .. 0 0 1 0 0 0 .. if we subtract then that will be converted to 0 0 0 1 1 1 1.. all the bit right of the 1 will be 1 and that 1 will be 0.Then we do xor operation to get the desired number.

**Aproach 3**
This code snippet calculates the bitwise complement of a given number by flipping only the bits that are 0 in its binary representation. It starts by initializing a counter `i` to track the current bit position and a variable `complement` to store the result. The code then enters a loop that continues until the input number `num` becomes 0. In each iteration, it checks the last bit of `num`. If the last bit is 0, the corresponding bit in the `complement` is set to 1 by using a bitwise OR operation with `1` shifted to the `i`-th position. The number is then right-shifted to move to the next bit, and the counter `i` is incremented. This process repeats until all bits have been processed, resulting in a `complement` where all the 0 bits in the original number have been flipped to 1, while the 1 bits remain unchanged. The final value of `complement` is then returned, effectively giving a partial bitwise complement of the original number, focused only on flipping the 0s to 1s.


## Approach


## Complexity
- Time complexity: O(log2(num)) for 1st and 3rd approach and O(1) for 2nd


- Space complexity: O(1)
