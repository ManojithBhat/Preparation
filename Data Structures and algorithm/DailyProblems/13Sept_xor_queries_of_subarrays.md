# Xor Queries of Subarrays
[Problem Link](https://leetcode.com/problems/xor-queries-of-a-subarray/description/?envType=daily-question&envId=2024-09-13)

## Problem desciption 
You are given an array arr of positive integers. You are also given the array queries where queries[i] = [lefti, righti].

For each query i compute the XOR of elements from lefti to righti (that is, arr[lefti] XOR arr[lefti + 1] XOR ... XOR arr[righti] ).

Return an array answer where answer[i] is the answer to the ith query.

 

### Example 1:

> **Input:** arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]<br>
**Output:** [2,7,14,8] <br>
**Explanation:** <br>
The binary representation of the elements in the array are:<br>
1 = 0001 <br>
3 = 0011 <br>
4 = 0100 <br>
8 = 1000 <br>
The XOR values for queries are:<br>
[0,1] = 1 xor 3 = 2 <br>
[1,2] = 3 xor 4 = 7 <br>
[0,3] = 1 xor 3 xor 4 xor 8 = 14 <br>
[3,3] = 8<br>


## constraints
* 1 <= arr.length, queries.length <= 3 * 104
* 1 <= arr[i] <= 109
* queries[i].length == 2
* 0 <= lefti <= righti < arr.length

## Code
```cpp

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> xor_vec,res;
        int xor_num = 0;
        for(int i = 0;i<n;i++){
            xor_num^=arr[i];
            xor_vec.push_back(xor_num);
            cout<<xor_vec.back()<<endl;
        }
        
        for(auto it: queries){
            int st =  xor_vec[it[1]];
            int end = it[0] == 0 ? 0 : xor_vec[it[0]-1];

            int res_xor =st ^ end;
            res.push_back(res_xor);
        }
        return res;

    }
};

```

## Intuition
The intution is cummulative xor, we try to find the cummulative xor upto n elements and then inorder to find the query say ( 2, 4 )
<br>
We take the cummulative xor till 4 and again xor with the cummulative xor upto 1 ( ie 2 - 1) if it is the first element ( ie 0 ) then what i do is keep it as 0 as xor with 0 is the same number the reason of taking the xor and not subtracting is that xor with the same element vanishes theis is the prime funda of this question that has to e remembererd


## Complexity
- Time complexity: O(N)


- Space complexity: O(N)
