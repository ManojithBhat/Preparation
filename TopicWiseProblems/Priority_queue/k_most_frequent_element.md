# K Most frequent element 
# K Closest Points to Origin

[Problem Link 1](https://leetcode.com/problems/k-closest-points-to-origin/)

[Problem Link 2](https://leetcode.com/problems/k-closest-points-to-origin/)

## Problem desciption 

## Problem 1

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

### Example 1

> **Input:** nums = [1,1,1,2,2,3], k = 2<br>
>**Output:** [1,2]

 ## Problem 2

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

> **Input:** points = [[1,3],[-2,2]], k = 1<br>
> **Output:** [[-2,2]]<br>
> **Explanation:**
The distance between (1, 3) and the origin is sqrt(10).<br>
The distance between (-2, 2) and the origin is sqrt(8).<br>
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.<br>
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].<br>

## constraints
* 1 <= nums.length <= 105
* -104 <= nums[i] <= 104
* k is in the range [1, the number of unique elements in the array].
* It is guaranteed that the answer is unique.

## Code
can also be done by max heap

```cpp
class Solution {
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
        }

        for(auto it : mp){
            pq.push({it.second,it.first});
            if(pq.size() > k) pq.pop();
        }

        while(pq.size()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
        
    }
};
```

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //it is standard heap solution with coordinate points given.
        //as it is said that we need closest - that is smaller values, we keep max heap
        priority_queue<pair<long long,vector<int>>> pq;
        vector<vector<int>> res;
        int n = points.size();

        for(int i = 0;i<n;i++){
            long long dis = pow(points[i][0],2) + pow(points[i][1],2);

            pq.push({dis,{points[i][0],points[i][1]}});

            if(pq.size() > k) pq.pop();
        }

        while(pq.size()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

```

## Intuition
Simple intution that inordere to top max min, we will use heap

## Approach


## Complexity
- Time complexity: O(m*logk)

- Space complexity:
