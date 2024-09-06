# 3 Sum
[Problem Link](https://leetcode.com/problems/3sum/submissions/1375163036/)

## Problem desciption 
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

### Example 1:

**Input:** nums = [-1,0,1,2,-1,-4]<br>
**Output:** [[-1,-1,2],[-1,0,1]]<br>
**Explanation:** <br>
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.<br>
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.<br>
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.<br>
The distinct triplets are [-1,0,1] and [-1,-1,2].<br>
Notice that the order of the output and the order of the triplets does not matter.<br>

## constraints
* 3 <= nums.length <= 3000
* -105 <= nums[i] <= 105

## Code
```cpp
class Solution {
public:
    //example test case to try out : 
    //[ -2 -2 -2 -1 -1 -1 0 0 0 2 2 2 2] - this example will clear why should we move the pointer when there is repetition

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());

        for(int i = 0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int s = i+1;
            int e = n - 1;
            
            while(s<e){
                int sum = nums[i];
                sum += (nums[s] + nums[e]);
                if(sum == 0){
                    res.push_back({nums[i],nums[s],nums[e]}); 
                    s++;
                    e--;
                    while(s<e && nums[s] == nums[s - 1]) s++;
                    while(s<e && nums[e] == nums[e  + 1] ) e--;
                }
                else if(sum < 0){
                    s++;
                }else e--;
            }
        }
        return res;
    }
};
```

## Intuition
When they mean by duplicate is not present , which means the combination triplet mean the same 
<br>
Take for example (-2 0 2) is same as (2 0 -2) so we need to mind these things. 

The brute force solution would be to have a three for loops running along wiht the set data structure ``` unordered_set<vector<int>>``` to store the sorted triplet always. the time complexity would be O(N^3*log(size of the answer)).

The optimal solution would be to have 2 for loops and a map datastructure to store the elements between any two index i and j  ( exclusive).
to compute the arr[i] = -(arr[j] + arr[k]). and find the suitable pair . here too we need to have a set datastructure to store the unique elements.

The optimal solution is would be to not to use the set datastructure and sort the array, whenver we encounter same element as the previous element we just move to the next position as it would generate the same triplet.

## Approach
1. Sort the array.
2. keep one pointer and use for loops - use the condition ```if(i>0 && nums[i] == nums[i-1])``` to move if we encounter same element. 
3. use the logic of 2 sum and find the other two elements here too manage a while loop to remove the duplicate element. 

example test case to try case 
```[ -2 -2 -2 -1 -1 -1 0 0 0 2 2 2 2]```

## Complexity
- Time complexity: O(nlogn + N2)
 
- Space complexity: O(1) - wer are only using to return answer
