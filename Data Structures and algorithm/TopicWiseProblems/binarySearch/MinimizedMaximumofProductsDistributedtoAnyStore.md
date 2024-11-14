# Minimized Maximum of Products Distributed to Any Store
[Problem Link](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/?envType=daily-question&envId=2024-11-14)

## Problem desciption 
You are given an integer n indicating there are n specialty retail stores. There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, where quantities[i] represents the number of products of the ith product type.

You need to distribute all products to the retail stores following these rules:

A store can only be given at most one product type but can be given any amount of it.
After distribution, each store will have been given some number of products (possibly 0). Let x represent the maximum number of products given to any store. You want x to be as small as possible, i.e., you want to minimize the maximum number of products that are given to any store.
Return the minimum possible x.


### Example 1:

**Input:** n = 6, quantities = [11,6]<br>
**Output:** 3<br>
**Explanation:** One optimal way is:<br>
- The 11 products of type 0 are distributed to the first four stores in these amounts: 2, 3, 3, 3<br>
- The 6 products of type 1 are distributed to the other two stores in these amounts: 3, 3<br>
The maximum number of products given to any store is max(2, 3, 3, 3, 3, 3) = 3.<br>


## constraints
m == quantities.length
1 <= m <= n <= 105
1 <= quantities[i] <= 105

## Code
```cpp
class Solution {
public:
    bool check(int n,int p,vector<int> &quantities){
        int m = quantities.size();
        int total = 0;
        for(int i = 0;i<m;i++){
            total += (quantities[i]/n);
            if(quantities[i]%n) total += 1;
        }

        if(total <= p) return true;
        return false;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int k = quantities.size();

        int maxEle = INT_MIN;
        for(int i=0;i<k;i++) maxEle = max(maxEle,quantities[i]);

        int low = 1;
        int high = maxEle;
        int result = 0;

        while(low <= high){
            int mid = (low + high)/2;

            if(check(mid,n,quantities)){
                result = mid;
                high = mid - 1;
            }else{
                low = mid+1;
            }
        }
        return result;
    }
};
```

## Intuition
Standard min max problem 

## Approach


## Complexity
- Time complexity:


- Space complexity:
