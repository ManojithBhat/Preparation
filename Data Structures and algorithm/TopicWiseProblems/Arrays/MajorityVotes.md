# Majoity Votes
[Problem Link](https://www.geeksforgeeks.org/problems/majority-vote/1   )

Refer this solution and intution and then move forward:
<br>
[Majority Element](MajorityElement.md)

## Problem desciption 
You are given an array of integer nums[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return -1. 

Note: The answer should be returned in an increasing format.

### Example 1
**Input:** nums = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]<br>
**Output:** [5, 6]<br>
**Explanation:** 5 and 6 occur more n/3 times.<br>

### Example 2
**Input:** nums = [1, 2, 3, 4, 5]<br>
**Output:** [-1]<br>
**Explanation:** no candidate occur more than n/3 times.<br>

## constraints
* 1 <= nums.size() <= 106
* 0 <= nums[i] <= 109

## Code
```cpp
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        // Code here
        map<int,int> store;
        vector<int> answer;
        for(int i=0;i<n;i++){
            store[nums[i]]++;
        }
        
        for(auto it:store){
            if(it.second >n/3){
                answer.push_back(it.first);
            }
        }
        if(answer.size()==0){
            return {-1};
        }
        return answer;
    }
};
```
Optimal solution
```cpp
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {     
        
        //optimal solution 
        int cnt1 = 0,cnt2=0;
        int el1=INT_MIN,el2=INT_MIN;
        for(int i=0;i<n;i++){
            if(cnt1==0 && el2!=nums[i]){
                cnt1++;
                el1=nums[i];
            }
            else if(cnt2==0 && el1!=nums[i]){
                cnt2++;
                el2 = nums[i];
            }
            else if(nums[i]==el1) cnt1++;
            else if(nums[i]==el2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ls;
        cnt1=0;cnt2=0;
        for(int i=0;i<n;i++){
            if(el1==nums[i]){
                cnt1++;
            }
            if(el2==nums[i]){
                cnt2++;
            }
        }
        int mini = (int)(n/3)+1;
        if(cnt1>=mini) ls.push_back(el1);
        if(cnt2>=mini) ls.push_back(el2);
        
        if(ls.size()==0) return {-1};
        
        return ls;
        
    }
};

```

## Intuition
The intution remains same as the [majority element](MajorityElement.md) but here we are using two variables for count and two variable for count. Here the elements are intitialised to -1 seeing the constraints. 
Here when we encounter a element that is not part of ele1 or ele2 it cancels out two of the element that is of ele1 and ele2. If not it increments each of the counts.

Unlike the majority element with n/2 here we are supposed to take care of another edge case is that when the cnt1 becames 0 but that element is already a part of the element2 then in that case we are not supposed to update it so we add another check case for that. 

Similarly we also check if the elements we have got. do they satisfy the n/3 condition.
There could be either 0,1,2 majority element at max.

## Approach
Similar to the majority element

## Complexity
- Time complexity: O(N)


- Space complexity: O(1)
