# Fractional knapsack
[Problem Link](https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1)

## Problem desciption 
Given weights and values of n items, we need to put these items in a knapsack of capacity w to get the maximum total value in the knapsack. Return a double value representing the maximum value in knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item here. The details of structure/class is defined in the comments above the given function.

### Example 1
> **Input:** n = 3, w = 50, value[] = [60,100,120], weight[] = > [10,20,30]<br>
> **Output:** 240.000000<br>
> **Explanation:** Take the item with value 60 and weight 10, > value 100 and weight 20 and split the third item with value > 120 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total value becomes 60+100+80.0=240.0 Thus, total maximum value of item we can have is 240.00 from  the given capacity of sack. <br>

## constraints

* 1 <= n <= 105
* 1 <= w <= 109
* 1 <= valuei, weighti <= 104

## Code
```cpp
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comp(Item a,Item b){
        double r1 = (double)a.value/(double)a.weight;
        double r2 = (double)b.value/(double)b.weight;
        return r1>r2;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        //sort in descending order 
       sort(arr,arr+n,comp);
        
        int i=0;
        double cost=0;
        int currWeight = 0;
        
       for(int i=0;i<n;i++){
           if(currWeight + arr[i].weight <=W){
               currWeight+=arr[i].weight;
               cost += arr[i].value;
           }
           else{
               int remain = W - currWeight;
               cost += (arr[i].value/(double)arr[i].weight)*(double)remain;
                break;
               
           }
       }
        return cost;
    }
        
};

```

## Intuition
The intution of the problem is to take the maximum profit. unlike 0/1 knapsack where we have to take either a object or not here we can take fractinal part of it. 

We have to make a greedy decision here by taking the object that gives me the ```maximum value/weight``` profit. Hence for that we sort the array based on the value / weight. Then we pick all the object completely unitl the weight is satisfied, if it exceeds then we take the fractinal part of that.


## Complexity
- Time complexity: O(nlogn)


- Space complexity: O(1)
