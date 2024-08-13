# Permutations
[Problem Link](https://leetcode.com/problems/permutations/description/)

## Problem desciption 
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

### Example 1:
> 
> **Input:** nums = [1,2,3] <br>
> **Output:** [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
> 
## constraints
* 1 <= nums.length <= 6
* -10 <= nums[i] <= 10
* All the integers of nums are unique.


## Code
```cpp

class Solution {
public:

    void f(vector<int>& nums,vector<int> &arr,vector<int>&freq,vector<vector<int>> &res){

        if(arr.size()==nums.size()){
            res.push_back(arr);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(freq[i]) continue;
            freq[i]=1;
            arr.push_back(nums[i]);
            f(nums,arr,freq,res);
            arr.pop_back();
            freq[i]=0;
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> arr;
        int n = nums.size();
        //need the hash map for marking whether we have taken the particular ele
        vector<int> freq(n,0);
        f(nums,arr,freq,res);
        return res;
    }
};

```
By swapping the adjacent element every time.
```cpp

    f(int ind,vector<int> &nums,vector<vector<int>>&res){
        if(ind==nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i=ind,i<nums.size();i++){
            swap(nums[ind],nums[i]);
            f(i+1,nums,res);
            swap(nums[ind],nums[i]);
            }
        }
```

## Intuition


## Approach


## Complexity
- Time complexity:   O(n!*n) <br>
    * n! is bc we are going through whole array everytime, 
    * n is because copying arr to res takes n time 


- Space complexity: O(n)
