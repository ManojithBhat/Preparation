* bitwise AND of two different numbers will always be strictly less than the maximum of those two numbers.
   eg. take and of (5 and 7 ) and now try (5 7 and 1) 

## Special type of problem 
* [longest_substring_containing_vowel_with_even_count](\DailyProblems\15Sept_longest_substring_containing_vowel_with_even_count.md)


## Comparator function 
``` cpp
bool compare(int a, int b) {
   
   return a>b;
}
```

The default comparator is for ascending in the c++, however there is greater<int> template that is used for descending order which is written there above.

How does it work?
consider an array [ 3 10 34 ]
if we want to sort it in a descending order then the function takes 2 elements let us say 3 and 10 and checks 3 > 10 which is false meaning it is not in the correct order so it will swap, so thing to note is if it returns false then it will swap or interchange then no change. 