* bitwise AND of two different numbers will always be strictly less than the maximum of those two numbers.
   eg. take and of (5 and 7 ) and now try (5 7 and 1) 

* The maximum OR of an array is obtained by taking or of all the elements - bc it requires max 1s

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


### Template for variable size sliding window 
```cpp

    // your code here
        int n = s.size();
        unordered_map<char,int> mp;
        int i = 0,j = 0;
        int maxLen = -1;
        
        while(j<n){
            mp[s[j]]++; //calculation phase
            
            while(mp.size() > k){ //window shrinking phase 
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            
            if(mp.size() == k) maxLen = max(j-i+1,maxLen); //optimal solution calculation phase
            
            j++;
        }
        return maxLen;

```

## Stringstream in C++
stringstream in C++ is a class that is part of the <sstream> library. It allows you to treat a string like a stream (similar to how cin and cout handle input and output) so that you can perform input/output operations on a string.

### Key Uses of stringstream:
* Extracting Data from a String:<br>
This is useful for splitting strings, parsing numbers, or reading formatted data from a string.

* Inserting Data into a String:<br>
Just like how cout is used to output data to the console, you can insert data into a stringstream and then get the entire string for further use.

```cpp

stringstream ss1(s1);
    string token;
    while(ss1 >> token) {
        vec1.push_back(token);
    }

```

### f a given integer num is a perfect square.

```cpp
   
int root = (int)sqrt(num);
if(root*root == num) return true;
else return false;
```