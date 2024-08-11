# Convert Binary Number in a Linked List to Integer
[Problem Link](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/)

## Problem desciption 
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

### Example 1
> **Input:** head = [1,0,1]<br>
> **Output:** 5<br>
> **Explanation:** (101) in base 2 = (5) in base 10
> <br>

## constraints
* The Linked List is not empty.
* Number of nodes will not exceed 30.
* Each node's value is either 0 or 1.


## Code
```cpp

class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    int getDecimalValue(ListNode* head) {
        head = reverse(head);
        ListNode* curr = head;
        int powerOfTwo = 0;
        int number = 0;
        while(curr){
            number += curr->val*pow(2,powerOfTwo);
            powerOfTwo++;
            curr = curr->next;
        }
        return number;
    }
};

```


## Approach
* Reverse the given Linked list.
* Keep two variables : power of two and number 
* Traverse the linkedlist and perform the operation ``` number += node->val*pow(2,poweroftwo)```


## Complexity
- Time complexity: O(N) - reversing the ll + traversing for calculating.


- Space complexity: O(1)
