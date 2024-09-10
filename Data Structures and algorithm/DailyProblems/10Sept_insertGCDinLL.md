# Insert Greatest Common Divisors in Linked List
[Problem Link](https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/?envType=daily-question&envId=2024-09-10)

## Problem desciption 
Given the head of a linked list head, in which each node contains an integer value.

Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.

Return the linked list after insertion.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.


### Example 1
> **Input:** head = [18,6,10,3]<br>
> **Output:** [18,6,6,2,10,1,3]<br>
> **Explanation:** The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes (nodes in blue are the inserted nodes).<br>
- We insert the greatest common divisor of 18 and 6 = 6 between the 1st and the 2nd nodes.<br>
- We insert the greatest common divisor of 6 and 10 = 2 between the 2nd and the 3rd nodes.<br>
- We insert the greatest common divisor of 10 and 3 = 1 between the 3rd and the 4th nodes.<br>
There are no more adjacent nodes, so we return the linked list.<br>


## constraints
* The number of nodes in the list is in the range [1, 5000].
* 1 <= Node.val <= 1000

## Code
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        while(curr->next){
            int gcd = __gcd(curr->val,curr->next->val);
            
            ListNode* newNode = new ListNode(gcd);
            newNode->next = curr->next;
            curr->next = newNode;

            curr = newNode->next;
        }
        return head;
    }
};

```

## Intuition
Use the __gcd operator in c++ to find the gcd of the curr as well as curr->next value and just insert the node next to curr and move curr to newNode->next. no edge cases to handle and pretty straight fwd question.


## Complexity
- Time complexity: O(N) 


- Space complexity: O(N)
