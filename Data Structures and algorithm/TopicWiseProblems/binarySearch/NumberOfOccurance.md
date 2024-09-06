# Number of occurrence

[Problem Link](https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1)

## Problem desciption 
Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

### Example 1 

Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: x = 2 occurs 4 times in the given array so the output is 4


## constraints
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ 106
1 ≤ X ≤ 106

## Code
```cpp
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    //funda : find the position of the first and last occurances and get the count
	    
	    int low = 0;
	    int high = n - 1;
	    int floor = -1, ceil = -1;
	    while(low <= high){
	        int mid = (low + high)/2;
	        
	        if(arr[mid]==x){
                high = mid-1;
                floor = mid;
	        }
	        else if(arr[mid] > x) high = mid-1;
	        else low = mid + 1;
	    }
	    
	    low = 0;
	    high = n - 1;
	    
	    while(low <= high){
	        int mid = (low + high)/2;
	        if(arr[mid] == x){
	            ceil = mid;
	            low = mid + 1;
	        }
	        else if(arr[mid] > x) high = mid-1;
	        else low = mid + 1;
	    }
	    
	    if(floor == -1 || ceil == -1) return 0;
	    return ceil - floor + 1;
	}
};

```

similar question but to find the last and first occurance of the number in  the sorted array


``` cpp

class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        int n = arr.size();
	    
	    int low = 0;
	    int high = n - 1;
	    int floor = -1, ceil = -1;
	    while(low <= high){
	        int mid = (low + high)/2;
	        
	        if(arr[mid]==x){
                high = mid-1;
                floor = mid;
	        }
	        else if(arr[mid] > x) high = mid-1;
	        else low = mid + 1;
	    }
	    
	    low = 0;
	    high = n - 1;
	    
	    while(low <= high){
	        int mid = (low + high)/2;
	        if(arr[mid] == x){
	            ceil = mid;
	            low = mid + 1;
	        }
	        else if(arr[mid] > x) high = mid-1;
	        else low = mid + 1;
	    }
	    
	    if(floor == -1 || ceil == -1) return {-1,-1};
	    return {floor,ceil};
	}
};



```

## Intuition


## Approach


## Complexity
- Time complexity:


- Space complexity:
