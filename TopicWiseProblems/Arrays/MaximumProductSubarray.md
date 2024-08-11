# Maximum Product Subarray 

[Problem Link leetcode](https://leetcode.com/problems/maximum-product-subarray/)
<br>
[Problem Link GFG](https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/0) <br>
[Quick Reference](https://www.youtube.com/watch?v=hnswaLJvr6g)

## Problem desciption 
Given an integer array nums, find a 
subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

### Example 1:
> 
> **Input:** nums = [2,3,-2,4]<br>
> **Output:** 6<br>
> **Explanation:** [2,3] has the largest product 6.<br>
> 
### Example 2:

> **Input:** nums = [-2,0,-1] <br>
> **Output:** 0 <br>
> **Explanation:** The result cannot be 2, because [-2,-1] is not a subarray.


## constraints
* 1 <= nums.length <= 2 * 104
* -10 <= nums[i] <= 10
* The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.


## Code
```cpp

long long maxProduct(vector<int> arr, int n) {
	    // code here
	   long long maxproduct = INT_MIN;
	   for(int i=0;i<n;i++){
	   long long product=1;
	   for(int j=i;j<n;j++){
	       product*=arr[j];
	       maxproduct = max(maxproduct,product);
	   }
	       
	   }
	   return maxproduct;
	   

	   //optimal solution 
	   //here we have 3 casses .. all positive .. even negative and all positive ... 
	   //odd negatives and all positive and 0 are present 
	   // here we are traversing from back and front and updating the ans ... if it encounters 0 we are starting from 1 agian 

	   long long pre=1,suff=1;
	   long long ans = INT_MIN;
	   for(int i=0;i<n;i++){
	       if(pre==0) pre=1;
	       if(suff==0) suff=1;
	       
	       pre = pre*arr[i];
	       suff=suff*arr[n-i-1];
	       ans = max(ans,max(pre,suff));
	   }
	   return ans;
	}

```

## Intuition
_Brute force_ :  <br>
Generate all the subarray and find the maximum of the subarray found.

_Optimal Solution_ :<br>
Here we have to consider 4 cases : 
* **All the elements are positive :** simple approach traverse and find the maximum 
* **Even number of negative numbers :** The product formed by multiplying two negative numbers will be positive. So the simple approach would work.
* **Odd number of negative numbers :** This is the trickiest part, whenever we have odd number of negative numbers we can partition the array into two parts right and left of the negative number, which can form the positive number product. take for example 
<br>
```Array : [ 1 2 3 -4 9 2 1] ``` <br>The product to the left and right of the -4 are 6 and 18. <br>
```Array : [1 2 3 -4 2 -1 4 -9 3 4]``` <br>
the array can be divided into three parts keeping -4 and -1 and -9 as the point. we can generate positive product with -4 and -9 as point of division.
* **Zeroes present** : This situation can be handled by making the prefix / suffix product one whenever this becames zero. 


## Approach
Traverse the array from both left and right and keeping suffix and prefix product and simultaneously updating the maxProuct and handling the case when prefix as well as suffix product becames zero.

## Complexity
- Time complexity: O(N)


- Space complexity: O(1)
