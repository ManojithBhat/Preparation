# The Celebrity Problem
[Problem Link](https://www.geeksforgeeks.org/problems/the-celebrity-problem/1)

## Problem desciption 
A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people.  A square matrix mat is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.
<br>
Note: Follow 0-based indexing.

## constraints
* 1 <= mat.size()<= 3000
* 0 <= mat[i][j]<= 1
  
### Example 1
> 
> **Input:** mat[][] = [[0 1 0],<br>
>                 [0 0 0], <br>
>                 [0 1 0]]<br>
> **Output:** 1<br>
> **Explanation:** 0th and 2nd person both know 1. Therefore, 1 is the celebrity. <br>
> <br>

## Code
Code with without using stack. 

```cpp

//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    bool checkrow(vector<vector<int>>&M,int row,int n){
        //all the row has to be 0 if he is a celebraty
        for(int i=0;i<n;i++){
            if(M[row][i]!=0) return false;
        }
        return true;
    }
    
    bool checkcol(vector<vector<int>>&M,int col,int n){
        //if he is a celebrity then all of them except him should know ( equals to 1 )
        for(int i=0;i<n;i++){
            if(i!=col && M[i][col]!=1) return false;
        }
            return true;
    }
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        for(int i=0;i<n;i++){
            //for every diagnol i need to check whether 
            if(checkrow(M,i,n) && checkcol(M,i,n)) return i;
        }
        return -1;
    }
};

```
Solution with stack 

```cpp 

int celebrity(vector<vector<int> >& M, int n) 
    {
       
        //optimised solution using stack 
        stack<int> st;
        //first push all of them to the stack
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        //pop two elements in the stack ( representing the people here) until there is only one element
        while(st.size()>1){
            int p1 = st.top();
            st.pop();
            int p2 = st.top();
            st.pop();
            
            //if the M[p1][p2] = 0; which means p1 does not know who p2 is. hence we can remove p2 as he is not the celebrity 
            //if M[p2][p1] =0 which means p2 does not know who p1 is. hence we imply that p1 is not celebrity
            if(M[p1][p2]==0){
                st.push(p1);
            }else if(M[p2][p1]==0){
                st.push(p2);
           }
        }
        if(st.size()==0) return -1;
        int p = st.top();
        for(int i = 0 ;i<n;i++){
            if(M[p][i]==1)
                return -1;
        }
        for(int i = 0 ;i<n;i++){
            if(p == i)
                continue;
            if(M[i][p]==0)
                return -1;
        }
        return p;
        
    }

```

## Intuition
The intution for solution without the stack is straight forward. for every person that is i, we need to check the corresponding row and column for the given constraints, if those satisfy then we have found the celebrity.

<br><br>

The solution with the stack is that we pick two people ( whome we have pushed to the stack at the first place ), if the person doesnot know the celebrity then we can remove him from the stack, we do this procedure until there is only 1 or 0 element in the stack.
<br>
If no element then there is no celebrity.
If there is one element we need to make sure that he is the celebrity. 

## Complexity
- Time complexity: <br>
    without stack : O(N^2) <br>
    with stack : O(N)


- Space complexity: <br>
    without stack : O(1) <br>
    with stack : O(N)
