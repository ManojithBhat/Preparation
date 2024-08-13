# Problem Title
[Problem Link]()

## Problem desciption 
Convert a non-negative integer num to its English words representation.

### Example 1:

> Input: num = 123<br>
> Output: "One Hundred Twenty Three"<br>

### Example 2:

> Input: num = 12345<br>
> Output: "Twelve Thousand Three Hundred Forty Five"<br>

### Example 3:

> Input: num = 1234567<br>
> Output: "One Million Two Hundred Thirty Four Thousand Five > Hundred Sixty Seven"<br>
<br>


## Code
```cpp

class Solution {
public:
        // Unordered maps to store words for numbers less than 10, 20, and 100
        unordered_map<int, string> belowTen = {
            {0, ""},     {1, "One"}, {2, "Two"},   {3, "Three"}, {4, "Four"},
            {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}};
        unordered_map<int, string> belowTwenty = {
            {10, "Ten"},      {11, "Eleven"},    {12, "Twelve"},
            {13, "Thirteen"}, {14, "Fourteen"},  {15, "Fifteen"},
            {16, "Sixteen"},  {17, "Seventeen"}, {18, "Eighteen"},
            {19, "Nineteen"}};
        unordered_map<int, string> belowHundred = {
            {1, "Ten"},     {2, "Twenty"}, {3, "Thirty"},
            {4, "Forty"},   {5, "Fifty"},  {6, "Sixty"},
            {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"}};

        string solve(int num) {
            if (num < 10) {
                return belowTen[num];
            }

            if (num < 20) {
                return belowTwenty[num];
            }

            if (num < 100) { // 89 = "Eighty Nine"
                return belowHundred[num / 10] +
                       ((num % 10 != 0) ? " " + belowTen[num % 10] : "");
            }

            if (num < 1000) { // 879/100 = 8 "Eight"
                return solve(num / 100) + " Hundred" +
                       ((num % 100 != 0) ? " " + solve(num % 100) : "");
            }

            if (num < 1000000) {
                return solve(num / 1000) + " Thousand" +
                       ((num % 1000 != 0) ? " " + solve(num % 1000) : "");
            }

            if (num < 1000000000) {
                return solve(num / 1000000) + " Million" +
                       ((num % 1000000 != 0) ? " " + solve(num % 1000000) : "");
            }

            return solve(num / 1000000000) + " Billion" +
                   ((num % 1000000000 != 0) ? " " + solve(num % 1000000000)
                                            : "");
        }

        string numberToWords(int num) {
            if (num == 0) {
                return "Zero";
            }

            return solve(num);
        }
    };

```

## Intuition
    This is a hard level problem in terms of figuring out how the number are expressed in the english word, the intution for the recursion comes as the number can be divided into parts ( with some conditions ) 
        * for example, seventy five can be written as seventy + five, however seventy can be splitted into seventy + "", simillarly there is some difference in the way the number are expressed when it comes to 1 to 10 and 11 to 20 and 30,40..90. 
        * the other thing to note here is that the number can be divided into 3 parts, 1 to 999, 1000 to 999999, 1000000 to 999999999, 1000000000 to 999999999999.
        *  so by this way we can express the number in the english word such as million, thousand, billion etc. by keeping this in mind, 
        
        we keep a map that stores from the 1 to 10, 11 to 20 and the 30,40..90. and then we keep a solve function that takes the number and then divides the number into the parts and then returns the english word for the number. and then we keep a numberToWords function that takes the number and then returns the english word for the number.

## Approach


## Complexity
- Time complexity:  O(log10(n) + 1 ) //as we are dividing the number by 10 in each iteration


- Space complexity: O(log10(N)+1) as we are using stack space of O(log10(n)+1)  

