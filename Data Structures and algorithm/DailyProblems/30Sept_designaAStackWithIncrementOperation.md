# Design a Stack with increment operation
[Problem Link](https://leetcode.com/problems/design-a-stack-with-increment-operation/?envType=daily-question&envId=2024-09-30)

## Problem desciption 
Design a stack that supports increment operations on its elements.

Implement the CustomStack class:

CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack.
void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.
int pop() Pops and returns the top of the stack or -1 if the stack is empty.
void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements in the stack.
 

### Example 1:

> **Input**
> ["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]<br>
[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]<br>
**Output**<br>
[null,null,null,2,null,null,null,null,null,103,202,201,-1]<br>
Explanation<br>
CustomStack stk = new CustomStack(3); // Stack is Empty []<br>
stk.push(1);                          // stack becomes [1]<br>
stk.push(2);                          // stack becomes [1, 2]<br>
stk.pop();                            // return 2 --> Return top of the stack 2, stack becomes [1]<br>
stk.push(2);                          // stack becomes [1, 2]<br>
stk.push(3);                          // stack becomes [1, 2, 3]<br>
stk.push(4);                          // stack still [1, 2, 3], Do not add another elements as size is 4<br>
stk.increment(5, 100);                // stack becomes [101, 102, 103]<br>
stk.increment(2, 100);                // stack becomes [201, 202, 103]<br>
stk.pop();                            // return 103 --> Return top of the stack 103, stack becomes [201, 202]<br>
stk.pop();                            // return 202 --> Return top of the stack 202, stack becomes [201]<br>
stk.pop();                            // return 201 --> Return top of the stack 201, stack becomes []<br>
stk.pop();                            // return -1 --> Stack is empty return -1.<br>
 

## constraints
* 1 <= maxSize, x, k <= 1000
* 0 <= val <= 100
* At most 1000 calls will be made to each method of increment, push and pop each separately.

## Code
```cpp
class CustomStack {
public:
    vector<int> v;
    int top;
    int size;
    CustomStack(int maxSize) {
        this->size = maxSize;
        top = 0;
    }
    
    void push(int x) {
        if(top == size) return;
        top++;
        v.push_back(x);
    }
    
    int pop() {
        if(top == 0) return -1;
        top--;
        int val = v.back();
        v.pop_back();
        cout<<val<<endl;
        return val;
    }
    
    void increment(int k, int val) {
        if( top == -1 ) return;
        if( k > top ) k = top;
        for(int i = 0;i<k;i++) v[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
```

## Intuition
Same as implementing the stack using vector approach.


## Complexity
- Time complexity: O(1)


- Space complexity:O(k)
