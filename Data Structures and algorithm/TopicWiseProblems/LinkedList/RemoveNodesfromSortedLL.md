# Remove Duplicates from Sorted List II
[Problem Link](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)

## Problem desciption 
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.


### Examples 1
>**Input:** head = [1,2,3,3,4,4,5]<br>
>**Output:** [1,2,5]<br>

## constraints
* The number of nodes in the list is in the range [0, 300].
* -100 <= Node.val <= 100
* The list is guaranteed to be sorted in ascending order.

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy, *curr = head;

        while(curr && curr->next) {

            if (curr->val == curr->next->val) {
                ListNode* tmp = curr->next;
                while (tmp!=NULL && curr->val == tmp->val)
                    tmp = tmp->next;
                prev->next = tmp;
                curr = tmp;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};

```

## Intuition
We keep a dummy node as we are using prev pointer and linking and joining the nodes, we traverse thorugh the entire linked list, and whenever we find the next node is same, we traverse unitll the numbers are same, then we make prev->next to point to the current node and then we move further. 


## Complexity
- Time complexity: O(N)


- Space complexity:O(1)
