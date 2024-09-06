#include<bits/stdc++.h>
/*

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3

*/

// approach 1 : sort the array and find the repeated element 
/*
    TC : O(NlogN) SC: O(1)
*/

//approach 2 : using set - store the elements in the set and check if the element is already present in the set or not 
// TC : O(N) SC : O(N)

//approach 3 : without the space and extra time complexity


int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int newNum = abs(nums[i]);
            if(nums[newNum]>0){
                int ind = newNum;
                nums[ind] = -nums[ind];
            }else{
                return newNum;
            }
        }
        return -1;
    }


/*
Intution : as the range of the number is from 1 to n+1, and in the array the index can go from 0 to n, so we can make use of the index to find whether the particular element is present in the array, whenever we encounter an element, then we go to the index corresponding to the element, if if it is alreay found then that would have already been visited so that is the element repeated, if not then we mark the element as visited by making it negative. 

Time Complexity : O(N) as we are traversing the array only once.
Space Complexity : O(1) as we are not using any extra space.

*/