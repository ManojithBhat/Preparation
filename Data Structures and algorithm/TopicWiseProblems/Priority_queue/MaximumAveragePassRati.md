# Maximum Average Pass Ratio
[Problem Link](https://leetcode.com/problems/maximum-average-pass-ratio/description/?envType=daily-question&envId=2024-12-15)

## Problem desciption 
There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.

 

### Example 1:

> **Input:** classes = [[1,2],[3,5],[2,2]], extraStudents = 2<br>
> **Output**: 0.78333<br>
> **Explanation:** You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.<br>


## constraints
* 1 <= classes.length <= 105
* classes[i].length == 2
* 1 <= passi <= totali <= 105
* 1 <= extraStudents <= 105

## Code
```cpp
class Solution{
public:
    #define P pair<double,int> 
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<P> pq;

        int n = classes.size();

        for(int i = 0;i<n;i++){

            double ration = (double)classes[i][0]/(double)classes[i][1];
            double newRation = ((double)classes[i][0]+1)/((double)classes[i][1]+1);

            double diff = newRation - ration;

            //priority queue stores the diff by adding one and the index
            pq.push({diff,i});
        }

        while(extraStudents--){
            P top = pq.top();
            pq.pop();

            double givenRatio = top.first;
            int index = top.second;

            classes[index][0]++;
            classes[index][1]++;

            double ration = (double)classes[index][0]/(double)classes[index][1];
            double newRation = ((double)classes[index][0]+1)/((double)classes[index][1]+1);

            double diff = newRation - ration;

            //priority queue stores the diff by adding one and the index
            pq.push({diff,index});

        }

        double sum = 0;
        for(int i = 0;i<n;i++){
            sum += (double)classes[i][0]/(double)classes[i][1];
        }

        double result = sum/n;
        return result;
    }
};
```

## Intuition
We have worked on maximizing with the numbers or elements as it is, but this is one of such kind of questions where we try to seek maximize the rate of increment and then add elements. 

## Approach
Store the increase in the value after adding 1, and store it in the maxheap, untill the students == 0, pick the maxIncrement value and then update it in the orginal array. 

## Complexity
- Time complexity: O(NlogN)


- Space complexity: O(N)
